#define _CRT_SECURE_NO_WARNINGS
#include "complex.h"
#include "cstring.h"
#define _USE_MATH_DEFINES
#include "math.h"

Complex::Complex()
{
    this->str = new char[4];
    this->str[0] = '0';
    this->str[1] = 'i';
    this->str[2] = '0';
    this->str[3] = '\0';
    str_length = 4;
    real = 0;
    virt = 0;
}

Complex::Complex(char* str)
{
    cout << "\nCOMPLEX: Вызван конструктор с параметром (строка)\n" << endl;
    str_length = strlen(str);
    int chk_i = 0, chk_n = 0, chk_z = 0, chk_all = 1, i_pos;
    int i = 0;
    if ((str[i] >= 48 && str[i] <= 57) || (str[i] == '+' || str[i] == '-'))
    {
        for (i = 0; i < str_length; i++)
        {
            if (str[i] == 'i')     
            {
                chk_i++;
                i_pos = i;
            }
        }
        if (chk_i == 1)
        {
            for (i = 1; i < i_pos; i++)
            {
                if ((str[i] < 48 || str[i] > 57) && str[i] != ',')
                    chk_n++;
                if (str[i] == ',')
                    chk_z++;
            }
            if (chk_n == 0 && chk_z <= 1&& (str[i_pos+1] >= 48 && str[i_pos+1] <= 57) || (str[i_pos+1] == '+' || str[i_pos+1] == '-'))
            {
                for (i = i_pos+2; i < str_length; i++)
                {
                    if ((str[i] < 48 || str[i] > 57)&& str[i] !=',')
                        chk_n++;
                    
                    if (str[i] == ',')
                        chk_z++;
                }
                if (chk_i == 1 && chk_n == 0 && chk_z <= 2)
                    chk_all = 0; 
            }
        }
    }
    if (chk_all == 0)
    {
        this->str = new char[str_length + 1];
        strcpy(this->str, str);
        int pos_i = 1, i;
        //float f = 0;
        for (i = 0; i < str_length; i++)
        {
            if (this->str[i] == 'i')
                pos_i = i;
        }
        char* str1 = new char[pos_i + 1];
        char* str2 = new char[str_length - pos_i + 1];
        for (i = 0; i < pos_i; i++)
        {
            str1[i] = this->str[i];
        }
        int k = 0;
        for (i = pos_i + 1; i < str_length; i++)
        {
            str2[k] = str[i];
            k++;
        }
        this->real = float(atof(str1));
        this->virt = float(atof(str2));
        delete[] str1;
        delete[] str2;
        cout << real;
    }
    else
    {
        this->str = new char[4];
        this->str[0] = '0';
        this->str[1] = 'i';
        this->str[2] = '0';
        this->str[3] = '\0';
        str_length = 4;
        virt = 0;
        real = 0;
    }
}

Complex::Complex(Complex& obj)
{
    cout << "\COMPLEX: Вызван конструктор копирования\n" << endl;
    this->str = obj.str;
    this->str_length = obj.str_length;
}

Complex::~Complex()
{
    cout << "\COMPLEX: Вызван деструктор\n" << endl;
    this->str_length = 0;
}

int Complex::type()
{
    return 1;
}

float Complex::vector()
{
    int pos_i=1, i;
    float p1, p2, f=0;
    for (i = 0; i < str_length; i++)
    {
        if (this->str[i] == 'i')
            pos_i = i;
    }
    char* str1 = new char[pos_i + 1];
    char* str2 = new char[str_length - pos_i + 1];
    for (i = 0; i < pos_i; i++)
    {
        str1[i] = this->str[i];
    }
    int k = 0;
    for (i = pos_i+1; i < str_length; i++)
    {
        str2[k] = str[i];
        k++;
    }
    p1 = atof(str1);
    p2 = atof(str2);
    delete[] str1;
    delete[] str2;
    if (p1 > FLT_EPSILON && p2 > FLT_EPSILON)
        f = (180/M_PI) * asinf(p2 / sqrtf(p1 * p1 + p2 * p2));
    return f;
}

float Complex::get_real()
{
    return real;
}

float Complex::get_virt()
{
    return virt;
}

unsigned int Complex::get_str_lentgh()
{
    return strlen(str);
}

char* Complex::get_str()
{
    return str;
}

void Complex::operator+(Complex &obj)//я просто в ахуе
{
    float res1 = this->real + (obj.real);
    float res2 = this->virt + (obj.virt);
    cout << "Результат сложения: " << res1 << "i" << res2 << endl;
}

void Complex::operator=(char* str)
{
    cout << "COMPLEX: перегрузка присваивания" << endl;
    this->str = str;
    str_length_cnt(this->str);
    Complex(this->str);
}
