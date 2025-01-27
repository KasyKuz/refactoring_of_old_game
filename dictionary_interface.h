#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include "file_dict.h"

using namespace std;
class dictionary_factory {
  

public:
    virtual using_dictionary* createDictionary() = 0;

};

class file_dictionary_factory: public dictionary_factory {


public:
    using_dictionary* createDictionary() override{
        return new file_dict();
    }

};


/* 
Pizza* createCheesePizza() override
{
    return new NewYorkCheesePizza();
}
*/