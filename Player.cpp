#define _CRT_SECURE_NO_WARNINGS
#include "Player.h"

#include "Word.h"

#include <Windows.h>
#include <iostream>
using namespace std;
#include <cstring>
#include <sstream>
#include <string>


void Player::print_choose_move()
{
    printf("print 1 and after enter word with coordinates (row , column, str/st - 0/1) on next line\n");
    printf("print 2 to finish inputing\n");
    printf("print 3 to finish game\n");
}

void Player::check_func(string s, int x, int y, int ststr, Constructor& Constr)
{
    //char* xx;
    //xx = strchr(s,(int)' ');
    int len = s.size() ;//(int)(xx - s);
    
    if (range_check(x,y,ststr,len) == 0) {
        //printf("word is out of rang, change it\n");
        Constr.myOutInterface()->output("word is out of rang, change it");
        return;
    }
    else {
        Word word(s, len,x, y, ststr, pole,using_letters);
        int res = word.all_check(Constr);
        if (res != -1) {
            pole.write_word(s, ststr, len,x-1,y-1);
            //pole.pole_print();
            Constr.myOutInterface()->all_pole_output(pole);
            word.return_bank(using_letters);

            score += res;
            //show_information();
            Constr.myOutInterface()->player_information_output(number,using_letters , score);
        }
    }

}

int Player::range_check(int x, int y, int ststr, int len)
{
    if (x > 0 && x < 16 && y>0 && y < 16 && (ststr == 1 || ststr == 0)) {
        if (ststr == 0 && x + len < 16) {
            return 1;
        }
        else if (ststr == 1 && y + len < 16) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return 0;
    }
}

Player::Player(int num){
    
    
    //Constructor Constr (C);
   // Constr = C;
	score = 0;
    number = num;
    for (int i = 0; i < 7; i++) {
        Letter let('z', -1, -1);
        using_letters[i]= let;
    }
   
}


void Player::giving_letters(Bank& bank,Constructor& Constr)
{
    if (Constr.return_N() == 10) {
        string s = Constr.myInInterface()->give_bank();
        for (int i = 0; i < 7; i++) {
            using_letters[i] = s[i];
        }
    }
    else {
        int o = 0;
        int c;
        char t;
        //выдача букв игроку 1
        //Bank bank;
        //setlocale(LC_ALL, "Russian");
        srand(time(NULL) + rand());
        //printf("player_bank: ");
        while (o < 7) {
            // printf("%c ", using_letters[o].return_value());
            if ((using_letters[o].return_value() == 'z' || using_letters[o].return_locked() == false) && bank.return_bank_count() > 0) {
                c = rand() % bank.return_bank_count();
                using_letters[o] = bank.take_letter(c);
                using_letters[o].change_locked(true);
                bank.low_bank_count();
                //printf("%c ", using_letters[o].return_value());
            }
            else if (bank.return_bank_count() == 0) { break; }
            o += 1;

        }
        // printf("\n")
    }
   
}

void Player::show_player_bank()
{
    setlocale(LC_ALL, "Russian");
    printf("bank of %d player: ", number);
    for (int i = 0; i < 7; i++) {
        if (using_letters[i].return_locked() == true) printf("%c ", using_letters[i].return_value());
    }
    printf("\n");
}

void Player::show_information()
{
    printf("-----information of %d player-----\n", number);
    show_player_score();
    show_player_bank();
    printf("----------------------------------\n");
}

void Player::show_player_score()
{
    printf("%d player score: %d\n", number, score);
}

int Player::make_one_step(Pole& p, Constructor& Constr)
{
    int res = 0;
    pole = p;

    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    while (true) {
        Constr.myOutInterface()->output_choose_move();
      
        res = Constr.myInInterface()->input_choose_move();;
        string s;
       
        if (res == 2 || res == 3) {
            return res;
        }
        else if (res == 1) {
           // char s[20];
            int x=0, y=0,ststr=0;
            
            
            s = Constr.myInInterface()->input_choose_str();
            int i = 0;
            std::stringstream ss(s);
            string s2;
            string s3;
            string s4;
            string s5;
            getline(ss, s2, ' ');
            getline(ss, s3, ' ');
            getline(ss, s4, ' ');
            getline(ss, s5, ' ');
            x = stoi(s3);
            y = stoi(s4);
            ststr = stoi(s5);

            check_func(s2, x, y, ststr, Constr);
        }
        else {

            Constr.myOutInterface()->output("some mistake, please, enter one more time");
            //printf("some mistake, please, enter one more time\n");
        }
    }
}

Pole Player::return_pole()
{
    return pole;
}

int Player::return_score()
{
    return score;
}

int Player::return_number()
{
    return number;
}

Letter Player::return_bank_l(int i)
{
    return using_letters[i];
}

Letter* Player::return_all_bank_l()
{
    return using_letters;
}



/* 
void Player::giving_letters(Bank bank)
{
    int o = 0;
    int c;
    char t;
    //выдача букв игроку 1
    //Bank bank;
    srand(time(NULL) + rand());
    while (o < 7) {
        if (using_letters[o].return_value() == 'z' && bank.return_bank_count() > 0) {
            c = rand() % bank.return_bank_count();
            using_letters[o] = bank.take_letter(c);
            bank.low_bank_count();
        }
        else if (bank.return_bank_count() == 0) { break; }
        o += 1;

    }

}
*/
