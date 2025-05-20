#include <sys/socket.h>
#include "Server.hpp"

int main(int argc, char* argv[])
{
    Server server;
    server.Listen();
    server.Accept();
}
