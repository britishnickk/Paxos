//General
#include <iostream>
#include <stdio.h>
#include <string.h>

#include <unistd.h> //fork

//TCP
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 1599
#define HOST "127.0.0.1"
using namespace std;
int main(int argc, char *argv[]){


}

int create_server(int portNum){
	static unsigned int servnum=0;
	
	int pid = fork();
	if(pid==0)//child
		return 0; //exec(Server.cpp) 
	//else
		//add pid to list for monitoring
		
	servnum++;
	return 1;
}

//Message send adapted from
//http://stackoverflow.com/questions/16486361/creating-a-basic-c-c-tcp-socket-writer
void message_send(std::string message)
{
    int sd, ret;
    struct sockaddr_in server;
    struct in_addr ipv4addr;
    struct hostent *hp;

    sd = socket(AF_INET,SOCK_STREAM,0);//SOCK_STREAM > SOCK_DGRAM for UDP
    server.sin_family = AF_INET;

    inet_pton(AF_INET, HOST, &ipv4addr);
    hp = gethostbyaddr(&ipv4addr, sizeof ipv4addr, AF_INET);
    //hp = gethostbyname(HOST);

    memcpy(hp->h_addr, &(server.sin_addr.s_addr), hp->h_length);
    server.sin_port = htons(PORT);

    connect(sd, (const sockaddr *)&server, sizeof(server));
    send(sd, (char *)message.c_str(), strlen((char *)message.c_str()), 0);
}
