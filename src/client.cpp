#include <cstdio>
#include <unistd.h>

#include <thread>
#include <string>
#include <vector>

std::vector<std::string> records;
void request_records(int first, int last=-1){

}
void update(){

	while(true){	//in its own thread, just keeps polling the server
		//printf("Calling request_records"); Very verbose
		request_records(records.size());
		usleep(10000);	//Lets not DOS ourselves
	}

}
void user(){

	//Handle user input. Run game.

}
//sendMessage(server, std::string message)


int main(int argc, char* argv[]){

	request_records(0);	//Get Caught Up

	std::thread jim (update);	//jim constantly checks for updates. Poor jim.
	std::thread user_thread(user);
	//start update thread
	//start user thread

	jim.join();
	user_thread.join();
}
