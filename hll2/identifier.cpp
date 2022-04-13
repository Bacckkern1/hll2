#define _CRT_SECURE_NO_WARNINGS
#include "identifier.h"

Identifier::Identifier()
{
    cout << "\nIDENTIFIER: Вызван конструктор по умолчанию\n" << endl;
    this->str = nullptr;
    this->str_length = 0;
}

Identifier::Identifier(char* str)
{
    cout << "\nIDENTIFIER: Вызван конструктор с параметром (строка)\n" << endl;
    str_length = strlen(str);
    this->str = new char[str_length + 1];
    strcpy(this->str, str);
    if (str[0] == '_' || (str[0] >= 65 && str[0] <= 90))
    {
        for (int i = 0; i < str_length; i++)
        {
            if (str[i] < 48 || (str[i] > 57 && str[i] < 65) || (str[i] > 90 && str[i] < 97) || str[i]>122)
            {
                strcpy(this->str, "");
                str_length = 0;
                i = str_length;
            }

        }
    }
    else
    {
        strcpy(this->str, "\0");
        //str_length = strlen("\0");
    }
}

Identifier::Identifier(char symb)
{
    cout << "\IDENTIFIER: Вызван конструктор с параметром (символ)\n" << endl;
    this->str[0] = symb;
    this->str[1] = '\0';
    this->str_length = 1;
}

Identifier::Identifier(Identifier& obj)
{
    cout << "\IDENTIFIER: Вызван конструктор копирования\n" << endl;
    this->str = obj.str;
    this->str_length = obj.str_length;
}

Identifier::~Identifier()
{
    cout << "\IDENTIFIER: Вызван деструктор\n" << endl;
    this->str_length = 0;
    //delete[] this->str;
}
int Identifier::type()
{
    return 2;
}
int Identifier::symb_search(char symb)
{
    int i;
    for (i = 0; i < str_length;i++)
    {
        if (str[i] == symb)
            return i;
    }
    return -1;
}

int Identifier::operator>(Identifier& obj)
{
    unsigned int str2len = obj.get_str_length();
    if (this->str_length > str2len)
        return 1;
    else
        return 0;
}

void Identifier::operator-(Identifier& obj)
{
    int str2_length = obj.get_str_length();
    int f;
    char* str2 = obj.str;
    for (int i = 0; i < str_length; i++)
    {
        for (int j = 0; j < str2_length; j++)
        {
            if (str[i] == str2[j])
            {
                f = i+1;
                for (int k = i; k < str_length-i; k++)
                {
                    this->str[k] = this->str[f];
                    f++;
                }
                this->str[f-1] = '\0';
            }
        }
    }
}

void Identifier::operator=(char* str)
{
    cout << "COMPLEX: перегрузка присваивания" << endl;
    this->str = str;
    str_length_cnt(this->str);
    Identifier(this->str);
}
