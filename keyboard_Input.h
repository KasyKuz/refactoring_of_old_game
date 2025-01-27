#pragma once
using namespace std;
#include "Pole.h"
#include <iostream>
#include <stdio.h>
#include "Input.h"

class  keyboard_Input : public Input
{
public:
    int input_choose_move() override;
    string input_choose_str() override;

    void make_all_words(string* w, int n)override {
        return;
    }
    void make_all_banks(string * b, int n)override{
        return;
    }
    string give_bank()override {
        string s = " ";
        return s;
    }
    void make_choose_move_mas(int *ch, int n)override {
        return;
    }
};