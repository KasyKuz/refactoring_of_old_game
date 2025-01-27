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
  

    std::map<char, unsigned> cost = { {'�',1},{'�',3},{'�',1},{'�',3},{'�',2},{'�',1},{'�',5},{'�',5}, {'�',1},
            {'�',4},{'�',2}, {'�', 2}, {'�',2}, {'�',1},{'�',1},{'�',2},{'�',1},{'�',1},{'�',1},
            {'�',2},{'�',8},{'�',5},{'�',5},{'�',5},{'�',8},{'�',10},{'�',15},{'�',4},{'�',3},{'�',8},{'�',8},{'�',3} };


    std::map<char, unsigned> ostatok = { {'�',8},{'�',2},{'�',4},{'�',2},{'�',4},{'�',9},{'�',1},{'�',2}, {'�',6},
        {'�',1},{'�',4}, {'�', 4}, {'�',3}, {'�',5},{'�',10},{'�',4},{'�',5},{'�',5},{'�',5},
        {'�',4},{'�',1},{'�',1},{'�',1},{'�',1},{'�',1},{'�',1},{'�',1},{'�',2},{'�',2},{'�',1},{'�',1},{'�',2} };

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

