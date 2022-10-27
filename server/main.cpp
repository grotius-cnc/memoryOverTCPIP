#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>
#include <chrono>
#include <GL/gl.h>
#include <XChunker.h>

#define SIZE 1024
std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
//! Edited by Skynet Cyberdyne 2022.
//! Ported to c++

int send_text(int socket)
{
    int n;
    char buffer[SIZE] = "Test sending from Server!\n";

    n = send(socket, buffer, sizeof(buffer), 0);
    if (n <= 0){
        perror("[-]Error in sending text.");
        return -1;
    }

    bzero(buffer, sizeof(buffer));
    return 0;
}

int receive_text(int socket)
{
    int n;
    char buffer[SIZE];

    n = recv(socket, buffer, SIZE, 0);
    if (n <= 0)
    {
        return -1;
    }
    std::cout<<"Received Text:"<<buffer<<std::endl;

    bzero(buffer, SIZE);
    return 0;
}

void send_image(int socket)
{

    FILE *picture;
    int size, read_size, stat, packet_index;
    char send_buffer[10240], read_buffer[256];
    packet_index = 1;

    picture = fopen("picture.jpeg", "r");
    std::cout<<"Getting Picture Size"<<std::endl;

    if(picture == NULL)
    {
        std::cout<<"Error Opening Image File."<<std::endl;
    }

    fseek(picture, 0, SEEK_END);
    size = ftell(picture);
    fseek(picture, 0, SEEK_SET);
    printf("Total Picture size: %i\n",size);

    //Send Picture Size
    std::cout<<"Sending Picture Size."<<std::endl;
    send(socket, (void *)&size, sizeof(int), 0);

    //Send Picture as Byte Array
    std::cout<<"Sending Picture as Byte Array."<<std::endl;

    do { //Read while we get errors that are due to signals.
        stat = recv(socket, &read_buffer , 255, 0);
        printf("Bytes read: %i\n",stat);
    } while (stat < 0);

    std::cout<<"Received data in socket."<<std::endl;
    //printf("Socket data: %c\n", read_buffer);

    while(!feof(picture))
    {
        //while(packet_index = 1){
        //Read from the file into our send buffer
        read_size = fread(send_buffer, 1, sizeof(send_buffer)-1, picture);

        //Send data through our socket
        do{
            stat = send(socket, send_buffer, read_size, 0);
        }while (stat < 0);

        std::cout<<"Packet Number:"<<packet_index<<std::endl;
        std::cout<<"Packet Size Sent:"<<read_size<<std::endl;
        std::cout<<std::endl;
        std::cout<<std::endl;

        packet_index++;

        //! Zero out our send buffer
        bzero(send_buffer, sizeof(send_buffer));
    }
    fclose(picture);
}

int receive_image(int socket)
{ //! Start function

    int recv_size = 0,size = 0, read_size, write_size, packet_index =1,stat;

    char imagearray[10241];
    FILE *image;

    //! Find the size of the image
    do{ stat = recv(socket, &size, sizeof(int), 0);
    } while(stat<0);

    std::cout<<"Packet received."<<std::endl;
    std::cout<<"Packet size:"<<stat<<std::endl;
    std::cout<<"Image size:"<<size<<std::endl;
    std::cout<<std::endl;

    char buffer[] = "Got it";

    //! Send our verification signal
    do { stat = write(socket, &buffer, sizeof(int));
    } while(stat<0);

    std::cout<<"Reply sent"<<std::endl;
    std::cout<<std::endl;

    image = fopen("recieved.jpeg", "w");

    if( image == NULL) {
        std::cout<<"Error has occurred. Image file could not be opened."<<std::endl;
        return -1; }

    //! Loop while we have not received the entire file yet

    struct timeval timeout = {10,0};

    fd_set fds;
    int buffer_fd;

    while(recv_size < size) {
        //! while(packet_index < 2){

        FD_ZERO(&fds);
        FD_SET(socket, &fds);

        buffer_fd = select(FD_SETSIZE,&fds,NULL,NULL,&timeout);

        if (buffer_fd < 0)
            std::cout<<"error: bad file descriptor set."<<std::endl;

        if (buffer_fd == 0)
            std::cout<<"error: buffer read timeout expired."<<std::endl;

        if (buffer_fd > 0)
        {
            do{
                read_size = recv(socket,imagearray, 10241, 0);
            }while(read_size <0);

            std::cout<<"Packet number received:"<<packet_index<<std::endl;
            std::cout<<"Packet size:"<<read_size<<std::endl;


            //! Write the currently read data into our image file
            write_size = fwrite(imagearray,1,read_size, image);
            std::cout<<"Written image size:"<<write_size<<std::endl;

            if(read_size !=write_size)
            {
                std::cout<<"error in read write"<<std::endl;
            }

            //! Increment the total number of bytes read
            recv_size += read_size;
            packet_index++;
            std::cout<<"Total received image size:"<<recv_size<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;
        }

    }

    fclose(image);
    std::cout<<"Image successfully Received!"<<std::endl;
    return 1;

}

int socket_init_server()
{
    int socket_desc;
    struct sockaddr_in server;
    //! Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        std::cout<<"Could not create socket"<<std::endl;
    }

    //! Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8889 );

    //! Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        puts("bind failed");
        return 1;
    }

    puts("bind done");

    //! Listen
    listen(socket_desc , 3);

    //! Accept and incoming connection
    puts("Waiting for incoming connections...");

    std::cout<<"Debug: socket_desc:"<<socket_desc<<std::endl;
    return socket_desc;
}

int socket_handshake_server(int socket_desc)
{
    int new_socket, c;
    struct sockaddr_in client;

    c = sizeof(struct sockaddr_in);

    if((new_socket = accept(socket_desc, (struct sockaddr *)&client,(socklen_t*)&c)))
    {
        puts("Connection accepted");
    }

    fflush(stdout);

    if (new_socket<0)
    {
        std::cerr<<"Accept Failed"<<std::endl;
        return 1;
    }

    return new_socket;
}

void receive_memory(int socket)
{ //! Start function

    int recv_size = 0,size = 0, read_size, write_size, packet_index =1,stat;

    GLubyte imagearray[10241];

    //! Find the size of the image
    do{ stat = recv(socket, &size, sizeof(int), 0);
    } while(stat<0);

    std::cout<<"Packet received."<<std::endl;
    std::cout<<"Packet size:"<<stat<<std::endl;
    std::cout<<"Image size:"<<size<<std::endl;
    std::cout<<std::endl;

    char buffer[] = "Got it";

    //! Send our verification signal
    do { stat = write(socket, &buffer, sizeof(int));
    } while(stat<0);

    std::cout<<"Reply sent"<<std::endl;
    std::cout<<std::endl;

    //! Loop while we have not received the entire file yet

    struct timeval timeout = {10,0};

    fd_set fds;
    int buffer_fd;
    XChunks myChunks;
    while(recv_size < size) {
        //! while(packet_index < 2){

        FD_ZERO(&fds);
        FD_SET(socket, &fds);

        buffer_fd = select(FD_SETSIZE,&fds,NULL,NULL,&timeout);

        if (buffer_fd < 0)
            std::cout<<"error: bad file descriptor set."<<std::endl;

        if (buffer_fd == 0)
            std::cout<<"error: buffer read timeout expired."<<std::endl;

        if (buffer_fd > 0)
        {
            do{
                //! In this section we build the chunk vector.

                read_size = recv(socket,imagearray, 10241, 0);

                XChunk theChunk;
                for(int i=0; i<read_size; i++){
                    theChunk.push_back(imagearray[i]);
                }
                myChunks.push_back(theChunk);

            }while(read_size <0);

            std::cout<<"Packet number received:"<<packet_index<<std::endl;
            std::cout<<"Packet size:"<<read_size<<std::endl;

            write_size = read_size;
            std::cout<<"Written image size:"<<write_size<<std::endl;

            if(read_size !=write_size)
            {
                std::cout<<"error in read write"<<std::endl;
            }

            //! Increment the total number of bytes read
            recv_size += read_size;
            packet_index++;
            std::cout<<"Total received image size:"<<recv_size<<std::endl;
            std::cout<<std::endl;
            std::cout<<std::endl;
        }

    }

    std::cout<<"Image successfully Received!"<<std::endl;
    std::cout<<"Total recieved chunks:"<<myChunks.size()<<std::endl;
    std::cout<<"Total recieved chunks bytes:"<<int(XChunker().getChunksByteSize(myChunks))<<std::endl;

    //! For example save to picture.
    XChunker().savePictureFromChunks("out.png",myChunks);
    //! For example save to a openGl texture, cq custom png pixmap.
    /*
    XPngPixmap myPixmap =XChunker().chunksToPngPixmap(myChunks);
    int theWidth;
    int theHeight;
    int theChannels;
    //! Your openGl texture :
    unsigned char* image = SOIL_load_image_from_memory(myPixmap.first,myPixmap.second,&theWidth,&theHeight,&theChannels,false);
    return 1;
    */
}

int main(int argc , char *argv[])
{
    argc=0;
    argv=0;
    int socket_desc_main , new_socket_main;

    socket_desc_main = socket_init_server();
    if (socket_desc_main == 1)
    {
        std::cout<<"Could not init socket Server!"<<std::endl;
        return 1;
    }
    new_socket_main = socket_handshake_server(socket_desc_main);

    // send_text(new_socket_main);
    // send_text(new_socket_main);
    // receive_text(new_socket_main);

    //! This will recieve 1000 images and then stops.
    int x=0;
    // while(x<1000){
    x++;
    start = std::chrono::high_resolution_clock::now();
    //receive_image(new_socket_main);
    receive_memory(new_socket_main);
    send_text(new_socket_main);
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Elapsed time in milliseconds: "<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;
    // }
    close(socket_desc_main);
    fflush(stdout);
    std::cout<<"Server Socket Closed!!!"<<std::endl;

    //! This part can be used to send images.
    /*
    socket_desc_main = socket_init_server();
    if (socket_desc_main == 1)
    {
        printf("Could not init socket Server!\n");
        return 1;
    }
    new_socket_main = socket_handshake_server(socket_desc_main);
    send_image(new_socket_main);
    close(socket_desc_main);
    fflush(stdout);
    std::cout<<"Server Socket Closed!!!"<<std::endl;
    */
    return 0;
}

