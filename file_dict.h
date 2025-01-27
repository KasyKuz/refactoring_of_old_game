#pragma once
#include <iostream>
#include <string.h>
#include <string>
//#include "dictionary_interface.h"
#include "Letter.h"
using namespace std;

class using_dictionary {
public:
    virtual bool search_word(Letter* sl, int m_slov) = 0;
    virtual string find_first_world(int cc) = 0;
};


class file_dict  : public using_dictionary
{


public:
   // ~file_dict();
  //  file_dict(void);
    bool search_word(Letter* sl, int m_slov) override;// override;
   // bool return_find_point();
    string find_first_world(int cc) override;// override;

};



