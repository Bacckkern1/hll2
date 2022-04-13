#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include "memory.h"

Cstring::Cstring()
{
	cout << "\nCSTRING: ������ ����������� �� ���������\n" << endl;
	this->str = nullptr;
	this->str_length = 0;
}

Cstring::Cstring(const Cstring& src)
{
	cout << "\nCSTRING: ������ ����������� �����������\n" << endl;
	this->str = src.str;
	this->str_length = src.str_length;
}

Cstring::Cstring(char* str)
{
	cout << "\nCSTRING: ������ ����������� � ���������� (������)\n" << endl;
	str_length_cnt(str);
	this->str = new char[str_length+1];
	strcpy(this->str, str);
}

Cstring::Cstring(char symb)
{
	cout << "\nCSTRING: ������ ����������� � ���������� (������)\n" << endl;
	this->str[0] = symb;
	this->str[1] = '\0';
	this->str_length = 1;
}

Cstring::~Cstring()
{
	cout << "\nCSTRING: ������ ����������\n" << endl;
	str_length = 0;
	delete[] str;
}

int Cstring::type()
{
	return 3;
}

char* Cstring::get_str()
{
	cout << "CSTRING: ������ ������" << endl;
	return str;
}

unsigned int Cstring::get_str_length()
{
	cout << "CSTRING: ������ �����" << endl;
	return str_length;
}

void Cstring::operator=(char* str)
{
	cout << "CSTRING: ���������� ������������" << endl;
	this->str = str;
	str_length_cnt(this->str);
	Cstring(this->str);
}

void Cstring::str_length_cnt(char* str)
{
	cout << "CSTRING: ������� �����" << endl;
	str_length = strlen(str);
}

ostream& operator<<(ostream& out, Cstring& output)
{
	out << "CSTRING: " << output.str << endl;
	return out;
}


