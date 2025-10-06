#ifndef SOLV_H
#define SOLV_H

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

class Solution {
public:
    int choise;
    void generateLexers();
    void parseByName(const std::string& s);
    void printStats() const;

private:
    int number{};
    std::string str;
    std::map<std::string, int> counter;
};

extern Solution solv;

#endif
