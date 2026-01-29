#include <filesystem>
#include <iostream>
namespace fs = std::filesystem;

int main() {
    fs::path src = "src_folder";
    fs::path dst = "dst_folder";

    for (auto& f : fs::directory_iterator(src)) {
        fs::copy(f.path(), dst / f.path().filename(), fs::copy_options::overwrite_existing);
    }

    std::cout << "Sync completed\n";
}
