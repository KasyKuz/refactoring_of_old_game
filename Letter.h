#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <iostream>
#include <map>
#include <conio.h>

using namespace std;
class Letter {
private:
    char value;
    int weight;
    int nums;
    bool locked;
  

    std::map<char, unsigned> cost = { {'à',1},{'á',3},{'â',1},{'ã',3},{'ä',2},{'å',1},{'æ',5},{'ç',5}, {'è',1},
            {'é',4},{'ê',2}, {'ë', 2}, {'ì',2}, {'í',1},{'î',1},{'ï',2},{'ð',1},{'ñ',1},{'ò',1},
            {'ó',2},{'ô',8},{'õ',5},{'ö',5},{'÷',5},{'ø',8},{'ù',10},{'ú',15},{'û',4},{'ü',3},{'ý',8},{'þ',8},{'ÿ',3} };


    std::map<char, unsigned> ostatok = { {'à',8},{'á',2},{'â',4},{'ã',2},{'ä',4},{'å',9},{'æ',1},{'ç',2}, {'è',6},
        {'é',1},{'ê',4}, {'ë', 4}, {'ì',3}, {'í',5},{'î',10},{'ï',4},{'ð',5},{'ñ',5},{'ò',5},
        {'ó',4},{'ô',1},{'õ',1},{'ö',1},{'÷',1},{'ø',1},{'ù',1},{'ú',1},{'û',2},{'ü',2},{'ý',1},{'þ',1},{'ÿ',2} };

public:
    Letter();
    Letter(char c);
    Letter(char v, int w, int n);
    char return_value();
    int return_nums();
    void delete_one_letter();
    void change_locked(bool b);

    int return_weight();
    bool return_locked();


};

