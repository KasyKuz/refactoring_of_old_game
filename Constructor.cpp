#include "Constructor.h"


Constructor::Constructor(string InterType, string DictType)
{
    srand(time(NULL) + rand());
    int cc = rand();
    //Bank bank;
    if (InterType == "keyboard") {
        main_interfaces_factory* newInterface1 = new keyboard_interface_factory();
        _InInterface = newInterface1->createInputInterface();

        main_interfaces_factory* newInterface2 = new keyboard_interface_factory();
        _OutInterface = newInterface2->createOutputInterface();
        N = 1;
       
    }

    
    else if (InterType == "ComputerManage") {
        N = 10;
        main_interfaces_factory* newInterface1 = new computer_manage_interface_factory();
        _InInterface = newInterface1->createInputInterface();

        main_interfaces_factory* newInterface2 = new computer_manage_interface_factory();
        _OutInterface = newInterface2->createOutputInterface();

        string answers[5] = { "автор 4 7 1", "ад 8 8 1","язык 8 11 1","вол 5 7 0","арка 8 5 1" };
        int steps[8] = {1,1,2,1,1,2,1,3};
        string letters[3] = { "автодтл","языколм","арклмно" };
        _InInterface->make_all_banks(letters,3);
        _InInterface->make_all_words(answers,5);
        _InInterface->make_choose_move_mas(steps,8);
        cc = 10;
    }
    
    if (DictType == "file dict") {
        dictionary_factory* newdict = new file_dictionary_factory();
        Dict = newdict->createDictionary();
    }

   
    first_word = Dict->find_first_world(cc);
    
    /* 
    for (int i = 0; i < 7; i++) {
        first_word[i] = f[i];
    }
    */
}
