#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "Letter.h"
#include "Pole.h"
#include "Constructor.h"
using namespace std;
class Word {
    //private:
    Pole pole;
    int x;
    int y;
    int ststr;
    int lens;
    int num_z;
    Letter mas[15];
    Letter bank[7];



public:
    Word(string s, int len, int xx, int yy, int st, Pole& pole, Letter l[7]);
    int check_alphs();
    int pirog();
    int get_weight();
    int dict_check(Constructor& Constr);
    void return_bank(Letter* u);
    int all_check( Constructor& Constr);
    //Pole return_pole();
    /* 
    int check_in_dict(int var);
    int pirog(int str_st, int num, int I, int J, int num_z);
    int get_weight(int num, int I, int J, char sl[15]);
    */
};
