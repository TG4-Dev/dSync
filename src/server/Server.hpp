#pragma once

#include <cstdio>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>



class Server
{
public:
    Server();
    ~Server();
   void Run();
   void Listen();
   void Accept();

private:
    int m_SocketFd, m_SocketNew;
    sockaddr_in m_Address;
    socklen_t m_AddressLength;
};
