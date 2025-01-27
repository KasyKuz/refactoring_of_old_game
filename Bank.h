#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "Letter.h"
using namespace std;
class Bank {
private:
    //int number_of_alph;
    Letter bank[32];
    int BANK_count;

public:
    Bank();
   // ~Bank();
    int give_letter(Letter l);
    Letter take_letter(int c);
    int return_bank_count();
    void low_bank_count();
};
    



