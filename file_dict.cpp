#define _CRT_SECURE_NO_WARNINGS
#include "file_dict.h"
#include "Letter.h"
#include <iostream>
#include <fstream>

bool file_dict::search_word(Letter* sl, int m_slov)
{

    bool find_point = false;
    ifstream file;
    switch (m_slov)
    {
    case 2:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/2_new.txt");
        break;
    case 3:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/3_new.txt");
        break;
    case 4:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/4_new.txt");
        break;
    case 5:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/5_new.txt");
        break;
    case 6:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/6_new.txt");
        break;
    case 7:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/7_new.txt");
        break;
    case 8:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/8_new.txt");
        break;
    case 9:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/9_new.txt");
        break;
    case 10:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/10_new.txt");
        break;
    case 11:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/11_new.txt");
        break;
    case 12:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/12_new.txt");
        break;
    case 13:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/13_new.txt");
        break;
    case 14:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/14_new.txt");
        break;

    case 15:
        file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/15_new.txt");
        break;
    }
    if (m_slov > 15) return false;
    string str;
    int i = 0;
    while (!getline(file, str).eof()) {
        if (str[0] == sl[0].return_value()) {
            int t = 0;

            for (int u = 1; u < m_slov; u++) {

                t += 1;

                if (sl[u].return_value() != (str[u])) {
                    t = -10;
                    break;
                }
            }
            if (t != -10) {
                find_point = true;
                file.close();
                return find_point;
            }
        }
        if ((int)sl[0].return_value() < (int)str[0]) {
            //printf("%d\n", c);
            file.close();
            return find_point;
        }
    }
    file.close();
    return find_point;
}
/*
bool file_dict::return_find_point()
{
    return find_point;
}
*/
string file_dict::find_first_world(int cc)
{
    cc = cc % 7787;
    fstream file;
    file.open("C:/Users/papin/source/repos/oop_project2/oop_lab2/oop_lab2/7_new.txt");
    int c = 0;
    string str;
    while (c != cc) {
        getline(file, str);
        c++;
    }
    file.close();
    return str;
}

