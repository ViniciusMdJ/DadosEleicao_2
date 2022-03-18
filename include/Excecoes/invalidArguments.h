#ifndef INVALIDARGUMENTS_H
#define INVALIDARGUMENTS_H

#include <iostream>
#include <string>

using namespace std;

class invalidArgs
{
public:
    friend ostream &operator<<(ostream &out, const invalidArgs &e);
};

ostream &operator<<(ostream &out, const invalidArgs &e)
{
    return out << "Argumentos inválidos\n";
}

#endif