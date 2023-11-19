#include <iostream>
#include <string>
#include <unordered_map>

bool RLpaper(const std::string& ransomLetter, const std::string& paper) {
    std::unordered_map<char, int> rs_maps, p_maps;
    
    for (auto iter = ransomLetter.begin(); iter != ransomLetter.end(); ++iter) {
        ++rs_maps[*iter];
    }

    for (auto iter = paper.begin(); iter != paper.end(); ++iter) {
        ++p_maps[*iter];
    }

    for (const auto& [letter, count] : rs_maps) {
        if (p_maps[letter] < count) {
            return false;
        }
    }
    return true;
}

int main() {
    std::string ransomLetter, paper;
    std::cout << "Vvedi Letter: ";
    std::cin >> ransomLetter;

    std::cout << "Vvedi Paper: ";
    std::cin >> paper;

    if (RLpaper(ransomLetter, paper)) {
        std::cout << "True\n";
    }
    else {
        std::cout << "False\n";
    }
    return 0;
}
