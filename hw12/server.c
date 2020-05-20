/* A simple server in the internet domain using TCP
   The port number is passed as an argument */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, newsockfd, portno; // socket and port number
    socklen_t clilen; // length of the client address
    
    char buffer[256]; // To store the message received from the client
    struct sockaddr_in serv_addr, cli_addr; // server address and client address
    int n; // amount of bytes read from client

    // Check if the port is provided as command line argument
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    // Create new socket of type TCP over IP
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if the socket was open properly
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Write zeroes int the server address struct
    bzero((char *) &serv_addr, sizeof(serv_addr));

    // Get the port number from the command line argument
    portno = atoi(argv[1]);

    // Configure the server address of type IP and set the port number
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    // Bind the created socket to the defined server address and check for 
    // an error
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
            sizeof(serv_addr)) < 0) {
                error("ERROR on binding");
            }

    listen(sockfd,5); // Wait for a connection
    clilen = sizeof(cli_addr); // get the client address length

    // Create a connection with the found address
    newsockfd = accept(sockfd, 
                (struct sockaddr *) &cli_addr, 
                &clilen);

    // Check if there is an error accepting
    if (newsockfd < 0) {
        error("ERROR on accept");
    }

    // Clear the buffer
    bzero(buffer,256);

    // Read the message of the client into the buffer
    n = read(newsockfd,buffer,255);

    // Check if something was read
    if (n < 0) {
        error("ERROR reading from socket");
    }

    // Print the receiced message
    printf("Here is the message: %s\n",buffer);

    // Respond to the client saying message was received
    n = write(newsockfd,"I got your message",18);

    // Check if response was sent correctly
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Close server and client sockets
    close(newsockfd);
    close(sockfd);
    return 0; 
}