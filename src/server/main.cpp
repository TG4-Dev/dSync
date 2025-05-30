#include <string>
#include <sys/socket.h>
#include "Server.hpp"

int main(int argc, char* argv[])
{
    if(argc < 2) {
        std::cerr << "ERROR: Not enough arguments specified." << std::endl;
        std::cerr << "Usage: "<<  argv[0] << " <port>" << std::endl;
        return 1;
    }

    int port = std::stoi(argv[1]);
    Server server(port);
    server.run();
}
