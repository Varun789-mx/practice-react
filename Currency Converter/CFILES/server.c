
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>

#define BUFFER_SIZE 255

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "Port no is not provided program terminated\n");
        exit(1);
    }
    int sockfd, newsock_fd, portno, n;
    char buffer[255];

    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        error("error in opening socket");
    }
    bzero((char *)&serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    int b = bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (b < 0)
    {
        error("Binding failed");
    }
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    newsock_fd = accept(sockfd,(struct &servaddr)&cli_addr,&clilen);
    if(newsock_fd < 0) { 
        error("Error in accepting connection");
    }
    

}
