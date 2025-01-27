#pragma once
#include <iostream>
#include <string.h>
#include <string>
//#include "Constructor.h"

using namespace std;
class Pole {
private:
    char pole[15][15];
    void pole_z();
   

public:
    Pole(void);
    Pole(string ss);

    Pole(Pole& p);
    void pole_print();
    char* return_pole_world(int flag, int num);
    void write_word(string s, int flag, int count, int i, int j);
    char return_letter_from(int x, int y);
   
};