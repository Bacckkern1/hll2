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
	Cstring(); //����������� �� ���������
	Cstring(const Cstring& src); //����������� �����������
	Cstring(char* str); //����������� � �����������
	Cstring(char symb);
	~Cstring(); //����������

	virtual int type();
	char* get_str(); //������� 
	unsigned int get_str_length();

	friend ostream& operator<< (ostream& out, Cstring& output);

	virtual void operator=(char* str);
};
#endif 
