#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>

int main() {
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }

    std::set<std::string> words;
    std::string word;
    while (file >> word) {
        words.insert(word);
    }
    file.close();

    std::cout << "Words in ascending order:" << std::endl;
    for (const auto& w : words) {
        std::cout << w << " ";
    }
    std::cout << '\n';
}

