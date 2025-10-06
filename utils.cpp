#include "utils.h"

std::string randomPhone() {
    std::string s = "+";
    for (int i = 0; i < 11; i++) s += std::to_string(rand() % 10);
    return s;
}

std::string randomType() {
    std::vector<std::string> types = {"tel", "sms", "fax"};
    return types[rand() % types.size()];
}

std::string randomBody() {
    if (rand() % 2 == 0) return "";
    std::string chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!?.,% ";
    std::string body = ";body=";
    int len = rand() % 15 + 5;
    for (int i = 0; i < len; i++) body += chars[rand() % chars.size()];
    return body;
}

std::string randomShbl() {
    std::string res = randomType() + ":" + randomPhone();
    int len = rand() % 20;
    for (int i = 0; i < len; i++) {
        if (rand() % 3 == 0)
            res += "," + randomPhone();
    }
    res += randomBody();
    return res;
}