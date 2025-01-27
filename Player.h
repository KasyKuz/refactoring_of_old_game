#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "Letter.h"
#include "Bank.h"
#include "Pole.h"
#include "Constructor.h"

using namespace std;
class Player {
private:
    int score;
    int number;
    Letter using_letters[7];
    void print_choose_move();
    void check_func(string s, int x, int y, int ststr , Constructor& Constr);
    int range_check(int x, int y, int ststr, int len);
    //Bank bank;
    Pole pole;
   // Constructor Constr;
    //add _str, _sapacity,_lengh
    //!!!!!!!

public:

    Player(int num);
    //Player(char let[7]);
   // void giving_letters(Bank& bank);
    void giving_letters(Bank& bank, Constructor& Constr);
    void show_player_bank();
    void show_information();
    void show_player_score();
    int make_one_step(Pole& p, Constructor& Constr);
    Pole return_pole();

    int return_score();
    int return_number();
   // bool return_locked_inf();
    Letter return_bank_l(int i);
    Letter* return_all_bank_l();
};

