#include "computer_manage_Input.h"
#include <iostream>
using namespace std;
int computer_manage_Input::input_choose_move()
{
    return choose_move_mas[choose_move_count++];
}


string computer_manage_Input::input_choose_str()
{
    /* 
    char s[16];
    int i;
    for (i = 0; i < all_words[word_count].length(); i++) {
        s[i] = all_words[word_count][i];
    }
    s[i] = '\0';
    */
  //  word_count++;
    return all_words[word_count++];
}

void computer_manage_Input::make_all_words(string* w, int n)
{
    for (int i = 0; i < n; i++) {
        all_words[i] = w[i];
    }
}

void computer_manage_Input::make_all_banks(string* b,int n)
{
    for (int i = 0; i < n; i++) {
        all_banks[i] = b[i];
    }
}

string computer_manage_Input::give_bank()
{
    /* 
    char s[7];
    for (int i = 0; i < 7; i++) {
        s[i] = all_banks[bank_count][i];
    }
    */
   // bank_count++;
   
    return all_banks[bank_count++];
}

void computer_manage_Input::make_choose_move_mas(int *ch, int n)
{
    for (int i = 0; i < n; i++) {
        choose_move_mas[i] = ch[i];
    }
}
