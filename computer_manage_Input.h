#pragma once
using namespace std;

#include <iostream>
#include <stdio.h>
#include "Input.h"
class computer_manage_Input: public Input
{
private:
    string all_words[50];
    string all_banks[50];
    int choose_move_mas[50];
    int choose_move_count = 0;
    int word_count = 0;
    int bank_count = 0;
public:
    int input_choose_move() override;
    string input_choose_str() override;

    void make_all_words(string* w, int n)override;
    void make_all_banks(string*  b, int n)override;
    string give_bank()override;
    void make_choose_move_mas(int *ch, int n)override;
};