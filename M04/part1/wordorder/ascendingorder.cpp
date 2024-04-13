#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <algorithm>
#include <cctype>
#include <vector>

class word_order {
public:
    void file_reader(std::ifstream& file);
    void print();
private:
    std::set<std::string> words;
};

void word_order::file_reader(std::ifstream& file) {
    std::string temp_word;
    while (file >> temp_word) {
        std::string word;
        for (char c : temp_word) {
            c = std::tolower(c);
            if (isalpha(c)) {
                word.push_back(c);
            }
        } 
        words.insert(word);
    }
}

void word_order::print() {
    std::cout << "Words in ascending order:" << std::endl;
    for (const auto &word : words) {
        std::cout << word << " ";
    }
    std::cout << "\n";
}

int main() {
    word_order reg;
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    reg.file_reader(file); 
    file.close();
    reg.print();
}
