#ifndef ARQNOTFOUND_H
#define ARQNOTFOUND_H

#include <iostream>

using namespace std;

class arqNotFound
{

public:
    friend ostream &operator<<(ostream &out, const arqNotFound &e);
};
ostream &operator<<(ostream &out, const arqNotFound &e)
{
    return out << "Não foi possível encontrar o arquivo!\n";
}

#endif