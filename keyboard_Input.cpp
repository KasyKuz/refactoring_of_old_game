#define _CRT_SECURE_NO_WARNINGS
#include "keyboard_Input.h"
#include "Word.h"
#include <Windows.h>
#include <iostream>
#include <stdio.h>
#include <sstream>
int keyboard_Input::input_choose_move()
{
    int c;
    string ss;
    std::cin >> ss;
    return ss[0] - '0';
}


string keyboard_Input::input_choose_str()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string ss1,ss2,ss3,ss4;
    //std::cin >> ss >> endl;
   // std::getline(cin, ss);
    cin >> ss1 >> ss2 >> ss3 >> ss4;
    string ss = ss1;
    ss.insert(ss.length() , " ");
    ss.insert(ss.length(), ss2);

    ss.insert(ss.length(), " ");
    ss.insert(ss.length(), ss3);

    ss.insert(ss.length(), " ");
    ss.insert(ss.length(), ss4);

    return ss;
}
