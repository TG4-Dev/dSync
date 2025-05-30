#pragma once

#include <cstdio>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>



class Server
{
public:
    Server(int port);
    ~Server();
    void run();

private:
    int m_serverfd;
    int m_clientfd;
    int m_port;



    void init();
    void handle_client();
};
