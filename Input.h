#pragma once
using namespace std;

class  Input {
public:
    virtual int input_choose_move() = 0;
    virtual string input_choose_str() = 0;

    virtual void make_all_words(string* w, int n) = 0;
    virtual void make_all_banks(string* b, int n) = 0;
    virtual string give_bank() = 0;
    virtual void make_choose_move_mas(int* ch, int n) = 0;

};

