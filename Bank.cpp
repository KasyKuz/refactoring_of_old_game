
#include "Bank.h"
#include "Letter.h"
#include <iostream>
#include <map>
#include <conio.h>


Bank::Bank()
{
   
    char letters[32] = { 'à','á', 'â', 'ã', 'ä', 'å', 'æ', 'ç', 'è', 'é', 'ê', 'ë', 'ì', 'í', 'î', 'ï', 'ð', 'ñ', 'ò', 'ó', 'ô', 'õ', 'ö', '÷', 'ø', 'ù', 'ú', 'û', 'ü', 'ý', 'þ', 'ÿ' };
    for (int i = 0; i < 32; i++) {
        Letter a(letters[i]);// , cost[letters[i]], ostatok[letters[i]]);
        bank[i] = a;
    }
    BANK_count = 103;
}

int Bank::give_letter(Letter l)
{
    return 0;
}


Letter Bank::take_letter(int c)
{
    int kk = 0;
    int i = 0;
    while (i<32) {
        if (bank[i].return_nums() + kk >= c) {
            bank[i].delete_one_letter();
            return bank[i];
        }
        kk += bank[i].return_nums();
        i++;
    }
   
}

int Bank::return_bank_count()
{
    return BANK_count;
}

void Bank::low_bank_count()
{
    BANK_count -= 1;
}
/* 
void Bank::make_bank_count(int b)
{
    BANK_count = b;
}
*/