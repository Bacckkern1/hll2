#ifndef CSTRING_H
#define CSTRING_H
#include "iostream"
using namespace std;

class Cstring
{
protected:
	char* str;
	unsigned int str_length;
	void str_length_cnt(char* str);
public:
	Cstring(); //конструктор по умолчанию
	Cstring(const Cstring& src); //конструктор копирования
	Cstring(char* str); //конструктор с параметрами
	Cstring(char symb);
	~Cstring(); //деструктор

	virtual int type();
	char* get_str(); //геттеры 
	unsigned int get_str_length();

	friend ostream& operator<< (ostream& out, Cstring& output);

	virtual void operator=(char* str);
};
#endif 
