#include "Server.hpp"

#define PORT 22001

Server::Server() {
    //socket
    //bind
    //listen
    //accept
    std::cout << "Initializing server..." << std::endl;
    m_SocketFd = socket(AF_INET, SOCK_STREAM, 0);  
    if(m_SocketFd < 0) {
        std::perror("Error: Can't create socket!"); 
    }
    
    m_Address.sin_family = AF_INET;
    m_Address.sin_addr.s_addr = INADDR_ANY;
    m_Address.sin_port = htons(PORT);


    socklen_t addressLength  = sizeof(m_Address);
    if(bind(m_SocketFd, reinterpret_cast<struct sockaddr*>(&m_Address), addressLength) < 0) {
        std::perror("Error: Can't bind socket!");
    }
}


Server::~Server() {
   close(m_SocketFd); 
}


void Server::Listen() {
    if(listen(m_SocketFd, 3) < 0) {
        std::perror("Error: Listen failed!");
    }
}

void Server::Accept() {
    socklen_t addressLength  = sizeof(m_Address);
    m_SocketNew = accept(m_SocketFd, reinterpret_cast<struct sockaddr*>(&m_Address), &addressLength);
    if(m_SocketNew < 0) {
        std::perror("Error: Accept failed!");
    }

}
void Server::Run() {
}
