#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h> 

void error(const char *msg)
{
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[])
{
    int sockfd, portno, n; // socket and port number
    struct sockaddr_in serv_addr; // server address
    struct hostent *server; // 

    char buffer[256]; // Buffer to write and receive the message

    // Check if the address and port is provided as command line arguments
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }

    portno = atoi(argv[2]); // Get the port number from the arguments
    sockfd = socket(AF_INET, SOCK_STREAM, 0); // Create a new TCP IP socket

    // Check if the socket was opened properly
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    server = gethostbyname(argv[1]); // get the hostname of the server

    // Check if the host exists
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // connfigure the server address of type IP and port number
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);

    serv_addr.sin_port = htons(portno); // set the port number

    // Connect to the server using the socket
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Read the message to send to the host
    printf("Please enter the message: ");
    bzero(buffer,256);
    fgets(buffer,255,stdin);

    // Send the message to the server
    n = write(sockfd,buffer,strlen(buffer));

    // Check if the message was sent successfully
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Clear the buffer
    bzero(buffer,256);

    // Read the response from the server
    n = read(sockfd,buffer,255);

    // Check if the response was read correctly
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Print the response
    printf("%s\n",buffer);

    // Close the socket
    close(sockfd);

    return 0;
}