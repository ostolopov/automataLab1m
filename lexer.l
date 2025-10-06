%option noyywrap

%{
#include <iostream>
#include <string>
#include <sstream>
#include "solv.h"
using namespace std;
%}

EMAIL   ([a-z]{1,20}\@([a-z]{1,20}\.)+[a-z]{1,5})
TEL     (\+[0-9]{11})
TYPE    (tel|sms|fax)

BODY_SMS (;body=([0-9a-zA-Z%.,!? ]{0,64}))?

TEL_LIST ({TEL}(,{TEL})*)

SHBL_SMS sms:{TEL_LIST}{BODY_SMS}
SHBL_OTHER (tel|fax):{TEL_LIST}

%%

[ \t\n]+       {  }
{EMAIL}        { cout << "EMAIL: " << yytext << endl; }
{SHBL_SMS}     {
                  std::ofstream file("/Users/egorbaranov/Desktop/CLion/automataLab1m/goodstr.txt", std::ios::app);
                  file << yytext << "\n";
                  file.close();

                  cout << "SHBL_SMS: " << yytext << endl;
                  string text(yytext);
                  auto colonPos = text.find(':');
                  if (colonPos != string::npos) {
                      string phones = text.substr(colonPos + 1);
                      auto semicolonPos = phones.find(';');
                      if (semicolonPos != string::npos)
                          phones = phones.substr(0, semicolonPos);
                      string phone;
                      stringstream ss(phones);
                      while (getline(ss, phone, ',')) {
                          solv.parseByName(phone);
                      }
                  }
               }
{SHBL_OTHER}   {
                  std::ofstream file("/Users/egorbaranov/Desktop/CLion/automataLab1m/goodstr.txt", std::ios::app);
                  file << yytext << "\n";
                  file.close();
                  cout << "SHBL_OTHER: " << yytext << endl;
                  string text(yytext);
                  auto colonPos = text.find(':');
                  if (colonPos != string::npos) {
                      string phones = text.substr(colonPos + 1);
                      string phone;
                      stringstream ss(phones);
                      while (getline(ss, phone, ',')) {
                          solv.parseByName(phone);
                      }
                  }
               }
.*            {
              std::ofstream file("/Users/egorbaranov/Desktop/CLion/automataLab1m/badstr.txt", std::ios::app);
              file << yytext << "\n";
              file.close();
              cout << "OTHER: " << yytext << endl;
              }

%%
