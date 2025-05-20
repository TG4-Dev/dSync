#include <cstdio>
#include <sys/socket.h>
#include <filesystem>

int main(int argc, char* argv[])
{
    struct sockaddr address;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1)
    {
        std::perror("ERROR: Can't create socket!");
    }
    

    close(sockfd);

}
