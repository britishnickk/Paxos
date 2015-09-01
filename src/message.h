
//TCP
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string>

class messenger{

	private:
	int PORT;
	const char *HOST;	
	public:
	messenger(const char *h,int p):HOST(h),PORT(p){
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

	    memcpy(hp->h_addr, &(server.sin_addr.s_addr), hp->h_length);
	    server.sin_port = htons(PORT);

	    connect(sd, (const sockaddr *)&server, sizeof(server));
	    send(sd, (char *)message.c_str(), strlen((char *)message.c_str()), 0);
	}

};
