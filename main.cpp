#include "solv.h"
#include <cstdio>

Solution solv;

extern int yylex();
extern FILE *yyin;

int main() {
    std::cout << "0 - Ручной ввод;\nВсе остальное - генератор\n";
    std::cin >> solv.choise;
    solv.generateLexers();
    std::ofstream fileGood("/Users/egorbaranov/Desktop/CLion/automataLab1m/goodstr.txt", std::ios::trunc);
    fileGood.close();
    std::ofstream fileBad("/Users/egorbaranov/Desktop/CLion/automataLab1m/badstr.txt", std::ios::trunc);
    fileBad.close();
    yyin = fopen("/Users/egorbaranov/Desktop/CLion/automataLab1m/input.txt", "r");
    if (!yyin) return 1;
    yylex();
    fclose(yyin);
    solv.printStats();
    return 0;
}
