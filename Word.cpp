#include "Word.h"
#include "Pole.h"
#include "file_dict.h"
#include "dictionary_interface.h"


Word::Word(string s, int len, int xx, int yy, int st, Pole& pol, Letter l[7])
{
    pole = pol;
    x = xx - 1;
    y = yy - 1;
    ststr = st;
    lens = len;
    num_z = 0;
    for (int i = 0; i < 7; i++) { bank[i] = l[i]; }
    for (int i = 0; i < len; i++) {
        Letter a(s[i]);
        int n = x + i * ((ststr) % 2);
        int m = y + i * ((ststr + 1) % 2);
        if (pole.return_letter_from(n, m) == 'z') {
            a.change_locked(false);

        }
        mas[i] = a;
    }
}

int Word::check_alphs()
{

    int c = 0;
    for (int i = 0; i < lens; i++) {
        c = 0;
        if (mas[i].return_locked() == false) {

            for (int j = 0; j < 7; j++) {
                if (bank[j].return_value() == mas[i].return_value() && bank[j].return_locked() == true) {
                    bank[j].change_locked(false);
                    c += 1;
                    break;
                }
            }
            if (c == 0) return -1;
            num_z += 1;
        }

    }
    return 1;
}

int Word::pirog()
{
    int num = x * ((ststr + 1) % 2) + y * ((ststr) % 2);
    int I = x * ((ststr) % 2) + y * ((ststr + 1) % 2);
    int J = I + lens - 1;
    int t1 = 0;
    int t2 = 0;
    int t3 = 0;
    if (ststr == 0) {//если строка
        
        if (I != 0 && pole.return_letter_from(num, I - 1) != 'z') {
            return 0;

        }
        if (J != 14 && pole.return_letter_from(num, J + 1) != 'z') {
            // printf("%c\n", pole.return_letter_from(num, J + 1));
            return 0;

        }
        
        for (int i = I; i <= J; i++) {
            if (num != 0 && pole.return_letter_from(num - 1, i) != 'z' && t1 == 1) {
                return 0;
            }
            if (num != 0 && pole.return_letter_from(num - 1, i) != 'z' && t1 == 0) {
                //t1 = 1;

                if (pole.return_letter_from(num, i) != 'z') {
                    t1 = 1;
                }
                else {
                    return 0;
                }

            }
            if (num != 0 && pole.return_letter_from(num - 1, i) == 'z') {
                t1 = 0;
            }
            if (num != 14 && pole.return_letter_from(num + 1, i) != 'z' && t2 == 1) {
                return 0;
            }
            if (num != 14 && pole.return_letter_from(num + 1, i) != 'z' && t2 == 0) {
                // t2 = 1;

                if (pole.return_letter_from(num, i) != 'z') {
                    t2 = 1;
                }
                else {
                    return 0;
                }

            }
            if (num != 14 && pole.return_letter_from(num + 1, i) == 'z') {
                t2 = 0;
            }
            //чтобы не записывал поверх одного слова другое (условеи ниже)                                               
            if (pole.return_letter_from(num, i) == 'z') {
                t3 += 1;
            }

        }
        if (t3 != num_z) { return 0; }
        return 1;
    }
    else {
        
        if (I != 0 && pole.return_letter_from(I - 1, num) != 'z') {
            return 0;

        }
        if (J != 14 && pole.return_letter_from(J + 1, num) != 'z') {
            // printf("%c\n", pole.return_letter_from(J + 1, num));
            return -1;

        }
       
        for (int i = I; i <= J; i++) {
            if (num > 0 && pole.return_letter_from(i, num - 1) != 'z' && t1 == 1) {
                return -2;
            }
            if (num > 0 && pole.return_letter_from(i, num - 1) != 'z' && t1 == 0) {
                // t1 = 1;

                if (pole.return_letter_from(i, num) != 'z') {
                    t1 = 1;
                }
                else {
                    return -3;
                }
            }
            if (num != 0 && pole.return_letter_from(i, num - 1) == 'z') {
                t1 = 0;
            }
            if (num < 14 && pole.return_letter_from(i, num + 1) != 'z' && t2 == 1) {
                return -4;
            }
            if (num < 14 && pole.return_letter_from(i, num + 1) != 'z' && t2 == 0) {
                //t2 = 1;

                if (pole.return_letter_from(i, num) != 'z') {
                    t2 = 1;
                }
                else {
                    return -5;
                }
            }
            if (num != 14 && pole.return_letter_from(i, num + 1) == 'z') {
                t2 = 0;
            }
            //ан-но случаю строки (if)
            if (pole.return_letter_from(i, num) == 'z') {
                t3 += 1;
            }

        }
        if (t3 != num_z) { return 0; }
        return 1;
    }
    return 1;

}

int Word::get_weight()
{
    int num = x * ((ststr+1) % 2) + y * ((ststr) % 2);
    int I = x * ((ststr) % 2) + y * ((ststr+1) % 2);
    int J = I + lens - 1;

    int m = 0;//масса всего слова
    int c = 1;// на нее домножается буква
    int c2 = 1;// на нее домножается итоговое слово 

    // не играет значение рассматриваем мы слово в строке или столбце, поле симметрично
    for (int i = I; i <= J; i++) {
        c = 1;
        //условие на синюю клетку
        if ((num == i && ((i >= 1 && i <= 4) || (i >= 10 && i <= 13))) || (num == 15 - 1 - i && ((i >= 1 && i <= 4) || (i >= 10 && i <= 13)))) {
            c2 = 2;
        }
        //условие на красную клетку
        if (((num == 0 || num == 14) && (i == 0 || i == 7 || i == 14)) || (num == 7 && (i == 0 || i == 14))) {
            c2 = 3;
        }
        //условие на зеленую
        if (((num == 0 || num == 14) && (i == 3 || i == 11)) || ((num == 2 || num == 12) && (i == 6 || i == 8)) || ((num == 3 || num == 11) && (i == 0 || i == 7 || i == 14)) || ((num == 6 || num == 8) && (i == 2 || i == 6 || i == 8 || i == 12)) || (num == 7 && (i == 4 || i == 11))) {
            c = 2;
        }
        //желтая клетка
        if (((num == 1 || num == 13) && (i == 5 || i == 9)) || ((num == 5 || num == 9) && (i == 1 || i == 13))) {
            c = 3;
        }
        m += mas[i - I].return_weight() * c;

    }
    m *= c2;
    return m;

}

int Word::dict_check(Constructor& Constr)
{
    //dictionary_factory* newdict = new file_dictionary_factory();
    //using_dictionary* file_dictionary = newdict->createDictionary();
    bool res = Constr.myDict()->search_word(mas,lens);
    return res;
}

void Word::return_bank(Letter* u)
{
    for (int i = 0; i < 7; i++) {
        u[i] = bank[i];
    }
}







int Word::all_check(Constructor& Constr)
{
    if (check_alphs() == 1) {      
        if (pirog () == 1) {
            if (dict_check(Constr) == 1) {
                //set_word();
                return get_weight();
            }
            else Constr.myOutInterface()->output("dict_check failed");
        }
        else Constr.myOutInterface()->output("check pirog failed");
    }
    else Constr.myOutInterface()->output("check_alphs failed");
    return -1;
}
