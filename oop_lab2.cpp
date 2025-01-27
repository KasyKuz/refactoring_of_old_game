// oop_lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "main_interfaces_factory.h"
#include "dictionary_interface.h"
#include "file_dict.h"
#include <iostream>
#include "Constructor.h"
#include "GameBussinessLogic.h"
#include <sstream>
using namespace std;

int main()
{
    //string inter = "keyboard_interface";
    //main_interface INTERFACE("keyboard_interface");
    /* 
    setlocale(LC_ALL, "Russian");
    dictionary_factory* newdict = new file_dictionary_factory();
    using_dictionary* file_dictionary = newdict->createDictionary();
    char *ss = file_dictionary->find_first_world(5);
    printf("%s ", ss);
    */
    /* 
    main_interfaces_factory* newInterface = new keyboard_interface_factory();
    main_interfaces* keyboarinterface = newInterface->createMainInterface();
    int res = keyboarinterface->run_interface();
    */

    /* 
    
    string inter = "keyboard";
    string dicti = "file dict";
    Constructor cons(inter,dicti);
    GameBussinessLogic game(cons);
    */
    string inter = "ComputerManage";
    string dicti = "file dict";
    Constructor cons(inter, dicti);
    GameBussinessLogic game(cons);
    cout << game.ret_res1()<<" " << game.ret_res2() << endl;
    
    /* 
    string s, str;
    s = "I love to read articles on Favtutor.";

    // ss is an object of stringstream that references the S string.  
    stringstream ss(s);

    // Use while loop to check the getline() function condition.  
    while (getline(ss, str, ' '))
        // `str` is used to store the token string while ' ' whitespace is used as the delimiter.
        cout << str << endl;

    return 0;
    
   */
}

/*

PizzaFactory* newYorkFactory
        = new NewYorkPizzaFactory();
    Pizza* newYorkCheesePizza
        = newYorkFactory->createCheesePizza();
*/