//General
#include <iostream>
#include <stdio.h>
#include <cstring>
#include <unistd.h>

#include <unistd.h> //fork

#include "message.h"
#define PORT 1599
#define HOST "127.0.0.1"
using namespace std;

int create_server(int portNum){
	static unsigned int servnum=0;
	
	char* pn=new char[std::to_string(portNum).size()];
	pn = std::strcpy(pn,std::to_string(portNum).c_str());
	char* sn=new char[std::to_string(servnum).size()];
	sn= std::strcpy(sn,std::to_string(servnum).c_str());
	char* args[] = {pn,sn};
	int pid = fork();
	if(pid==0)//child
		execv("./Server.cpp",args); 
	//else
		//add pid to list for monitoring
		
	servnum++;
	return 1;
}
int main(int argc, char *argv[]){
	create_server(1600);
	messenger server1("127.0.0.1",1600);

	while(true){
		usleep(10000);	//Lets not DOS ourselves
	}
}

