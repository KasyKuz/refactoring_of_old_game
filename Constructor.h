#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "main_interfaces_factory.h"
#include "dictionary_interface.h"
#include "Bank.h"
#include <time.h>
#include <stdio.h>
#include "Letter.h"

using namespace std;

class  Constructor{
private:
    Output* _OutInterface =NULL;
    Input* _InInterface=NULL;
    int N = 0;
    using_dictionary* Dict = NULL;
    string first_word;
   // Bank bank;
    string bank1[40];
    string bank2[40];
    
public: 
   // Constructor() = default;
   
    Constructor(string InterType, string DictType); 
    Input* myInInterface() {
        return _InInterface;
    }
    Output* myOutInterface() {
        return _OutInterface;
    }
    using_dictionary* myDict() {
        return Dict;
    }
    string first_word_return() {
        return first_word;
    }
    
    int return_N() {
        return N;
    }
    //main_interface(string type_interface)=0;
 

};