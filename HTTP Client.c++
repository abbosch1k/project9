#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8081);
    inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr);

    connect(sock, (sockaddr*)&addr, sizeof(addr));

    std::string req = "GET / HTTP/1.1\r\nHost: localhost\r\n\r\n";
    write(sock, req.c_str(), req.size());

    char buffer[4096];
    int n = read(sock, buffer, sizeof(buffer));
    std::cout.write(buffer, n);

    close(sock);
}
