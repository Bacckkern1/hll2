#ifndef COMPLEX_H
#define COMPLEX_H
#include "cstring.h"
class Complex :
    public Cstring
{
public:
    Complex();
    Complex(char* str);
    Complex(char symb) :Cstring(symb){};
    Complex(Complex& obj);
    ~Complex();

    int type();
    float vector();
    float real, virt;//для тестов все равно не работает
    float get_real();
    float get_virt();
    unsigned int get_str_lentgh();
    char* get_str();
    void operator+(Complex &obj);
    void operator/(Complex& obj);
    void operator=(char* str);
};
#endif 