#include <iostream>
#include <thread>
#include <vector>
#include <netinet/in.h>
#include <unistd.h>

int main() {
    int server = socket(AF_INET, SOCK_STREAM, 0);

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = INADDR_ANY;

    bind(server, (sockaddr*)&addr, sizeof(addr));
    listen(server, 5);

    std::cout << "Chat server started\n";

    while (true) {
        int client = accept(server, nullptr, nullptr);
        std::thread([client]() {
            char buffer[1024];
            while (true) {
                int r = read(client, buffer, sizeof(buffer));
                if (r <= 0) break;
                write(client, buffer, r);
            }
            close(client);
        }).detach();
    }
}
