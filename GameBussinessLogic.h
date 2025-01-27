#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "main_interfaces_factory.h"
#include "dictionary_interface.h"
#include "Constructor.h"
#include "main_interface.h"
#include "Pole.h"
#include "Player.h"
#include "Bank.h"
#include <Windows.h>

using namespace std;

class  GameBussinessLogic {
private:
    int result_pl1;
    int result_pl2;
public:
    GameBussinessLogic(Constructor& curGame) {
        //printf("welcome to keyboard_interface\n");
        curGame.myOutInterface()->output("welcome to keyboard_interface");
        Pole pole_play(curGame.first_word_return());
        //pole_play.pole_print();
        curGame.myOutInterface()->all_pole_output(pole_play);
        int a = 0;
        Bank bank;
        Player pl1(1);
        Player pl2(2);
        while (a == 0) {
            pl1.giving_letters(bank, curGame);
            //pl1.show_player_bank();
           // curGame.givin_letters(pl1);
          //  bank = curGame.return_bank();
            curGame.myOutInterface()->player_bank_output(pl1.return_all_bank_l(), pl1.return_number());
            if (pl1.make_one_step(pole_play, curGame) == 3) break;

            pole_play = pl1.return_pole();
            //pole_play.pole_print();
            curGame.myOutInterface()->all_pole_output(pole_play);
            cout << pl1.return_score() << endl;


            pl2.giving_letters(bank,curGame);
            //pl2.show_player_bank();
           
            curGame.myOutInterface()->player_bank_output(pl2.return_all_bank_l(), pl2.return_number());
            if (pl2.make_one_step(pole_play,curGame) == 3) break; 

            pole_play = pl2.return_pole();
           // pole_play.pole_print();
            curGame.myOutInterface()->all_pole_output(pole_play);
            cout << pl2.return_score() << endl;
            //pl1.show_information();
            //pl2.show_information();
            curGame.myOutInterface()->player_information_output(pl1.return_number(), pl1.return_all_bank_l(), pl1.return_score());
            curGame.myOutInterface()->player_information_output(pl2.return_number(), pl2.return_all_bank_l(), pl2.return_score());
        }
        printf("\n-----------------GAME OVER-----------------\n");
        result_pl1 = pl1.return_score();
        result_pl2 = pl2.return_score();
        //return 0;
    }
    int ret_res1() {
        return  result_pl1;
    }
    int ret_res2() {
        return  result_pl2;
    }

};

