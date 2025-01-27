#pragma once
using namespace std;
#include "Pole.h"
#include "Letter.h"

class  Output {
public:
    virtual void output_choose_move() = 0;
    virtual void output(string s) = 0;
    virtual void all_pole_output(Pole& pl) = 0;

    virtual void player_information_output(int n, Letter* l, int score) = 0;
    virtual void player_bank_output(Letter* l, int n) = 0;
};

