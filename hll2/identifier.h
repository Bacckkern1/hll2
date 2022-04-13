#ifndef IDENTIFIER_H
#define IDENTIFIER_H
#include "cstring.h"
class Identifier :
    public Cstring
{
public:
    Identifier();
    Identifier(char *str);
    Identifier(char symb);
    Identifier(Identifier& obj);
    ~Identifier();

    int type();
    int symb_search(char symb);

    int operator>(Identifier& obj);
    void operator-(Identifier& obj);
    void operator=(char* str);
};
#endif 

