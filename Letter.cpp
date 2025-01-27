#include "Letter.h"


Letter::Letter()
{
    value = -1;
    weight = -1;
    nums = -1;
    locked = true;
}

Letter::Letter(char c)
{
    value = c;
    weight = cost[c];
    nums = ostatok[c];
    locked = true;
}

Letter::Letter(char v, int w, int n)
{
    value = v;
    weight = w;
    nums = n;
    locked = true;
}

char Letter::return_value()
{
    return value;
}

int Letter::return_nums()
{
    return nums;
}

void Letter::delete_one_letter()
{
    if (nums>0) nums -= 1;
}

void Letter::change_locked(bool b)
{
    locked = b;
}

int Letter::return_weight()
{
    return weight;
}

bool Letter::return_locked()
{
    return locked;
}
