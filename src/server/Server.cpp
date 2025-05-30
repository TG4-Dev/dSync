#include "Server.hpp"
#include <cstdlib>
#include <string>
#include <sys/socket.h>

#define PORT 22001

Server::Server(int port) : m_port(port){
    init();
}


Server::~Server() {
   close(m_serverfd); 
   close(m_clientfd);
}



void Server::init() {
    m_serverfd = socket(AF_INET, SOCK_STREAM, 0);
    if(m_serverfd < 0) {
        std::perror("ERROR: Cannot create socket!");
        exit(EXIT_FAILURE);
    }
    
    sockaddr_in addr; 
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(m_port);

    if (bind(m_serverfd, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        std::perror("ERROR: Cannot bind socket!");
        exit(EXIT_FAILURE);
    }


    if(listen(m_serverfd, 1) < 0) {
        std::perror("ERROR: Listen error!");
        exit(EXIT_FAILURE);
    }

    std::cout << "[+] Listening on port : " << m_port << std::endl;



}



void Server::run() {
    sockaddr_in client_addr;
    socklen_t client_len = sizeof(client_addr);

    m_clientfd = accept(m_serverfd, (struct sockaddr*)&client_addr, &client_len);

    if(m_clientfd < 0) {
        std::perror("ERROR: Cannot accept connection!");
        return;
    }

    std::cout << "[+] Client connected!" << std::endl;
    handle_client();
    
}


void Server::handle_client() {
    const size_t buffer_size = 1024;
    char buffer[buffer_size];


    for(;;) {
        ssize_t bytes = read(m_clientfd, buffer, buffer_size);
        if(bytes <= 0)
            break;

        std::cout << "[Recieved >] : " << std::string(buffer, bytes);
        //Echo
        write(m_clientfd, buffer, bytes);
    }

    std::cout << "[*] Client disconnected." << std::endl;
}


