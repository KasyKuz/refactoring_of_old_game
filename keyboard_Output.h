#pragma once

#include "Pole.h"
#include "Letter.h"
#include "Output.h"
using namespace std;

class  keyboard_Output : public Output
{
public:
    void output_choose_move()override;
    void output(string) override;
    void all_pole_output(Pole& pl) override;
    //void player_information_output(Player& pl) override;
    //void player_bank_output(Player& pl)override;
    void player_information_output(int n, Letter* l, int score) override;
    void player_bank_output(Letter* l,int n)override;
};