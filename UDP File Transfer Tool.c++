#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8082);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    std::string msg = "Hello UDP";
    sendto(sock, msg.c_str(), msg.size(), 0, (sockaddr*)&addr, sizeof(addr));

    char buffer[1024];
    socklen_t len = sizeof(addr);
    int n = recvfrom(sock, buffer, sizeof(buffer), 0, (sockaddr*)&addr, &len);
    std::cout.write(buffer, n);

    close(sock);
}
