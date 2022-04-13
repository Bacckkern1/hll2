
#include "cstring.h"
#include "identifier.h"
#include "complex.h"
#include <iostream>
#include <locale.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int n = 4, menu = 0, type, chk_type=0, chk_type_j=0, start = 0, i = 0, j = 0, chs = 0;
	char exit, symb;
	char* stri = new char[100];
	cout << "Введите количество элементов(4-6 шт.)" << endl;
	cin >> n;
	Cstring** p = new Cstring*[n];
	while (menu == 0)
	{
		if (start == 0)
		{
			for (i = 0; i < n; ++i)
			{
				cout << "Элемент номер " << i << endl;
				cout << "Введите 1 для создания Комплексного числа" << endl;
				cout << "Введите 2 для создания Идентификатора" << endl;
				cout << "Введите 3 для создания Систроки" << endl;
				cin >> type;
				if (type == 1)
				{
					cin >> stri;
					p[i] = new Complex(stri);
				}
				if (type == 2)
				{
					cin >> stri;
					p[i] = new Identifier(stri);
				}
				if (type == 3)
				{
					cin >> stri;
					p[i] = new Cstring(stri);
				}
			}
			start++;
		}
		system("pause");
		system("cls");
		cout << "Выберите пункт меню" << endl;
		cout << "1.Методы Комплексного числа" << endl;
		cout << "2.Методы Идентификатора" << endl;
		cout << "3.Методы Систроки" << endl;
		cout << "4.Заново задать элементы" << endl;
		cout << "5.Вывод всех строк" << endl;
		cout << "6.Выход" << endl;
		cin >> type;
		system("cls");
		switch (type)
		{
			case 1:
				while (chk_type != 1)
				{
					cout << "Введите номер элемента" << endl;
					cin >> i;
					chk_type = p[i]->type();
					if (chk_type != 1)
					{
						cout << "Элемент не Комплексное число, если хотите выйти введите 'Y'" << endl;
						cin >> exit;
						if (exit == 'Y')
						{
							exit = 'N';
							break;
						}
					}
				}
				system("cls");
				cout << "Выберите пункт меню" << endl;
				cout << "1.Ввести строку" << endl;
				cout << "2.Посчитать угол между радиус векторами" << endl;
				cout << "3.Сложение" << endl;
				cout << "4.Деление" << endl;
				cin >> chs;
				switch(chs)
				{ 
					case 1:
						cout << "Введите комплексное число" << endl;
						cin >> stri;
						(p[i])->operator=(stri);
						break;
					case 2:
						cout <<"Угол = " <<((Complex*)(p[0]))->vector() << endl;
						break;
					case 3:
						while (chk_type_j != 1)
						{
							cout << "Введите номер элемента" << endl;
							cin >> j;
							chk_type_j = p[j]->type();
							if (chk_type_j != 1)
							{
								cout << "Элемент не Комплексное число, если хотите выйти введите 'Y'" << endl;
								cin >> exit;
								if (exit == 'Y')
								{
									exit = 'N';
									break;
								}
							}
						}
						((Complex*)p[i])->operator+((Complex&)p[j]);//пиздец
						chk_type_j = 0;
						break;
					case 4:
						break;
				}
				break;
			case 2:
				while (chk_type != 2)
				{
					cout << "Введите номер элемента" << endl;
					cin >> i;
					chk_type = p[i]->type();
					if (chk_type != 2)
					{
						cout << "Элемент не Идентификатор, если хотите выйти введите 'Y'" << endl;
						cin >> exit;
						if (exit == 'Y')
						{
							exit = 'N';
							break;
						}
					}
				}
				system("cls");
				cout << "Выберите пункт меню" << endl;
				cout << "1.Ввести строку" << endl;
				cout << "2.Первое вхождение символа в строку" << endl;
				cout << "3.Сравнение строк >" << endl;
				cout << "4.Вычитание строк" << endl;
				cin >> chs;
				switch (chs)
				{
				case 1:
					cout << "Введите Идентификатор" << endl;
					cin >> stri;
					(p[i])->operator=(stri);
					break;
				case 2:
					cout << "Введите символ " << endl;
					cin >> symb;
					cout << "Первое вхождение - " << ((Identifier*)(p[i]))->symb_search(symb)<< " (-1 - вхождения нет)"<< endl;
					break;
				case 3:
					while (chk_type_j != 2)
					{
						cout << "Введите номер элемента" << endl;
						cin >> j;
						chk_type_j = p[j]->type();
						if (chk_type_j != 2)
						{
							cout << "Элемент не Идентификатор, если хотите выйти введите 'Y'" << endl;
							cin >> exit;
							if (exit == 'Y')
							{
								exit = 'N';
								break;
							}
						}
					}
					cout << ((Identifier*)(p[i]))->operator>((Identifier&)(p[j])) << endl;
					chk_type_j = 0;
					break;
				case 4:
					cout << "Введите номер элемента для вычитания" << endl;
					cin >> j;
					while (chk_type_j != 2)
					{
						cout << "Введите номер элемента" << endl;
						cin >> j;
						chk_type_j = p[j]->type();
						if (chk_type_j != 2)
						{
							cout << "Элемент не Идентификатор, если хотите выйти введите 'Y'" << endl;
							cin >> exit;
							if (exit == 'Y')
							{
								exit = 'N';
								break;
							}
						}
					}
					((Identifier*)(p[i]))->operator-((Identifier&)(p[j]));
					cout << p[i] <<endl;
					chk_type_j = 0;
					break;
				}
				chk_type = 0;
				break;
			case 3:
				system("cls");
				cout << "Выберите пункт меню" << endl;
				cout << "1.Ввести строку" << endl;
				cin >> chs;
				switch (chs)
				{
				case 1:
					cout << "Введите элемент" << endl;
					cin >> i;
					cout << "Введите строку" << endl;
					cin >> stri;
					(p[i])->operator=(stri);
					break;
				}
				break;
			case 4:
				start = 0;
				break;
			case 5:
				for (i = 0; i < n; i++)
				{
					cout << p[i]->get_str() << endl;
				}
				break;
			case 6:
				menu++;
				break;
		}
	}
}

