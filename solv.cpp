#include "solv.h"
#include "utils.h"

void Solution::generateLexers() {
    std::ofstream file("/Users/egorbaranov/Desktop/CLion/automataLab1m/input.txt");
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return;
    }
    std::cout << "Enter number of lexers: ";
    std::cin >> number;
    std::cin.ignore();

    if (choise == 0) {
        for (int i = 0; i < number; i++) {
            getline(std::cin, str);
            file << str << "\n";
        }
    } else {
        for (int i = 0; i < number; i++) {
            file << randomShbl() << "\n";
        }
    }

    file.close();
}

void Solution::parseByName(const std::string& s) {
    counter[s]++;
}

void Solution::printStats() const {
    std::ofstream file("/Users/egorbaranov/Desktop/CLion/automataLab1m/output.txt");
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл!" << std::endl;
        return;
    }
    for (const auto &p : counter) {
        if (p.second > 1)
            file << p.first << " : " << p.second << "\n";
    }
    file.close();
}
