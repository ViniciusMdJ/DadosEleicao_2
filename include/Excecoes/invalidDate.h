#ifndef INVALIDDATE_H
#define INVALIDDATE_H

#include <iostream>

using namespace std;

class invalidDate
{

public:
    friend ostream &operator<<(ostream &out, const invalidDate &e);
};

ostream &operator<<(ostream &out, const invalidDate &e)
{
    return out << "Data no formato inválido\n";
}

#endif