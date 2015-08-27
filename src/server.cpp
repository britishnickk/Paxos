#include <vector>
#include <string>

#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

std::vector<std::string> ledger;
struct serv{unsigned int servnum; sockaddr_in port;};
std::vector<std::string> servers;
int port;
int host; //not an int
unsigned int servnum;

int main(int argc, char *argv[]){

	//get servnum, port number 

}
std::string listen(int blocking=0){
	return "";
}
void broadcast(std::string message){
	//foreach server in servers: send message
	for(std::vector<std::string>::iterator s = servers.begin(); s!= servers.end(); s++){
		//sendMessage(message, *s);	
	} 
}
void propose(){
}
void promise(){
	//check if we can promise to accept
	//react accordingly
}
void accept(){
	//check if we can accept
	//react accordingly
}


