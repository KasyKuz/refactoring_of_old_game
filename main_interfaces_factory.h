#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "Output.h"
#include "Input.h"
#include "keyboard_Output.h"
#include "keyboard_Input.h"
#include "computer_manage_Output.h"
#include "computer_manage_Input.h"

using namespace std;
class main_interfaces_factory {


public:
    virtual  Input* createInputInterface() = 0;
    virtual  Output* createOutputInterface() = 0;

};

class keyboard_interface_factory : public  main_interfaces_factory {


public:
    /* 
    main_interfaces* createMainInterface() override {
        return new  keyboard_main_interface();
    }
    */

    Output* createOutputInterface() override {
        return new keyboard_Output();
    }

    Input* createInputInterface() override {
        return new keyboard_Input();
    }

};
class computer_manage_interface_factory : public  main_interfaces_factory {


public:
    /*
    main_interfaces* createMainInterface() override {
        return new  keyboard_main_interface();
    }
    */

    Output* createOutputInterface() override {
        return new computer_manage_Output();
    }

    Input* createInputInterface() override {
        return new computer_manage_Input();
    }

};
/* 
class computer_manage_interface_factory : public  main_interfaces_factory {


public:
    main_interfaces* createMainInterface() override {
        return new  computer_manage_interface_factory();
    }

};
*/