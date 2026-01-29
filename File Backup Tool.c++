#include <fstream>
#include <iostream>

int main() {
    std::ifstream src("source.txt", std::ios::binary);
    std::ofstream dst("backup.txt", std::ios::binary);

    if (!src || !dst) {
        std::cout << "File error\n";
        return 1;
    }

    dst << src.rdbuf();
    std::cout << "Backup completed\n";
}
