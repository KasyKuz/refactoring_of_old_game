#define _CRT_SECURE_NO_WARNINGS
#include "main_interface.h"
#include "Pole.h"
#include "Player.h"
#include "Bank.h"

#include "Bank.h"
#include <Windows.h>


int keyboard_main_interface::run_interface()
{
    printf("welcome to keyboard_interface\n");
    Pole pole_play;
    pole_play.pole_print();
    int a = 0;
    Bank bank;
    Player pl1(1);
    Player pl2(2);
    while (a == 0) {
        pl1.giving_letters(bank);
        pl1.show_player_bank();
        if (pl1.make_one_step(pole_play)==3) break ;

        pole_play = pl1.return_pole();
        pole_play.pole_print();

        pl2.giving_letters(bank);
        pl2.show_player_bank();
        if (pl2.make_one_step(pole_play) == 3) break;

        pole_play = pl2.return_pole();
        pole_play.pole_print();

        pl1.show_information();
        pl2.show_information();
    }
    printf("\n-----------------GAME OVER-----------------\n");
    return 0;
}

char* keyboard_main_interface::input()
{
    char ss[20];
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    scanf("%s", ss);
    return ss;
}

void keyboard_main_interface::output(const char* s)
{
    printf("%s", s);
}

