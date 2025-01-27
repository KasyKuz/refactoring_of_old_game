#pragma once

#include "Pole.h"
#include "Letter.h"
#include "Output.h"
using namespace std;

class  computer_manage_Output : public Output
{
public:
    void output_choose_move()override {
        return;
    }
    void output(string s) override {
        return;
    }
    void all_pole_output(Pole& pl) override {
        return;
    }
    //void player_information_output(Player& pl) override;
    //void player_bank_output(Player& pl)override;
    void player_information_output(int n, Letter* l, int score) override {
        return;
    }
    void player_bank_output(Letter* l, int n)override
    {
        return;
    }
};