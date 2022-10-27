memoryOverTCPIP

This c++ basic example is able to send and recieve :

		1.	Text messages.
		2.	Files, for example pictures.
		3.	Send endless memory over the internet with 
			the help of a custom build data chunker and
			server-client sockets.
			
			An implementation could be:
			
			Stream openGl textures without any modification 
			or in between steps straight trough the socket.
			
			Eliminate's in between steps.
			Can be easy encrypted to some spacy language.


![imgOverTCPIP](https://github.com/grotius-cnc/imgOverTCPIP/blob/main/ManInTheMiddle.png)


Skynet Cyberdyne ported the original code 
to c++ and transferred the code into a cmake project.

The code has 2 projects wich are build by the toplevel cmake file.

How it works.

Program cyclus for the memory transfer:

	1. 	The server will wait until the client is up.
	2. 	When client is up, it will transfer the memory trough 
		the socket connection to the server.
	3. 	The server will recieve a memory package and will send a confirmation 
		text message back to the client to keep the process going.
	4. 	When the client has recieved the confirmation text message, 
		it will send the next memory package until transfer 
		is complete.
		
Explaining sending memory over the internet:

	Some of us will just save a openGl texture to a file, 
	open and recreate the texture in a other
	program and show the output on the screen. This wil result in a slow update
	ratio. Transferring the memory would be more effiecent.
	
	So i build a memory chunker first. This took me 2 day's inluding testing.
	The chunker creates packages (chunks) from the memory size.
	
	After that i was able to create a server-client program.
	
	Now it can transfer raw memory data. 
	
	You can think about not saving the texture or bitmap to a file before transferring.
	No it now sends the packages in the gluBytes, or whatever. 
	
	The chunker has a tiny template class where more datatypes are welcome to transfer.
	
	So far so good, No threading and no mutex is show'n today.
	
		
Considerations:
		
	1. 	Multi threading. When integrating this code in a gui project, 
		threading with detach is a must, otherwise this process 
		will lock your gui app. This example is creating a thread in a
		c++ class and passing a int value trough it.
		
		class theClass {
		public:
			theClass(int theValue){
				myThread = new std::thread(&XClient::thread,this,theValue);
       			myThread->detach(); //! Execute the thread independent from other programs.
        	}
        	
       		void thread(int theValue){
       			//! This function will run like a while loop.
   			}
    	};
    	private:
    	std::thread *myThread;
    	
	
	2.  When using multi threading in a gui project, you could 
		use the std::mutex to lock variables being used by multiple
		threads at the same time. Setting up a mutex is quite easy.
		The thread calling the function() will lock acces from other 
		threads to the variable.
		
		std::mutex myMutex;
		void function(){
	    	myMutex.lock();
	    		// update your variable here. 
			myMutex.unlock();
		}
		
	3. 	Log the bytes send and recieved so you can check if data 
		is really transferred. 
		I have experienced data losses in other socket examples.

Performance:

	When not outcommented, std::chrono log's the transfer time. 
	
	The attached picture = 572,7 KiB (586403 B) 
	Transfer time : ~10ms

To build the project:
		
	clone https://github.com/grotius-cnc/imgOverTCPIP.git
	mkdir build
	cd build
	cmake .. 
	make

To run in terminal, first start the server: 

	$ ./server
		
If server run's, fire up the client :		

	$ ./client.

Or just open the cmakelist file in a code editor, 
this will problably load the project.

This code is tested and build on linux amd64.


