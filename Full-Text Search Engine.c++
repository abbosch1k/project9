#include <iostream>
#include <fstream>
#include <string>
#include <vector>

int main() {
    std::ifstream file("text.txt");
    std::string word;
    std::vector<std::string> words;
    while(file >> word) words.push_back(word);

    std::string query;
    std::cout << "Search: ";
    std::cin >> query;

    for(auto &w: words) if(w==query) std::cout << "Found: " << w << "\n";
}
