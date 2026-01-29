#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

int main() {
    fs::path dir = ".";
    for(auto& f: fs::recursive_directory_iterator(dir))
        std::cout << f.path() << "\n";
}
