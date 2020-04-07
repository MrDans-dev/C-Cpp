#include <iostream>
#include <math.h>
#include <vector>
#include <Windows.h>
#include <string.h>
#include <algorithm>

using namespace std;

const vector<char>hex_list = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7', '8' , '9' , 'A' , 'B', 'C' , 'D' , 'E' , 'F' };

vector<char> string_2_vec(string con)
{
	transform(con.begin(), con.end(), con.begin(), toupper);
	vector<char>convered;
	for (int i = 0; con[i] != NULL; i++)
	{
		convered.push_back(con[i]);
	}
	return convered;
}

void wypisz(vector<int>t)
{
	int o;
	for (int i = t.size()-1; i >=0; i--)
	{
		o = t[i];
		cout << hex_list[o];
	}
	cout << endl;
}

int index(char n)
{
	for (int i = 0; i <= 15; i++)
	{
		if (n == hex_list[i])
		{
			return i;
		}
	}
	return -1;
}

int hex_2_dec(string hex)
{
	vector<char>test = string_2_vec(hex);
	int m = test.size() - 1,wynik =0;
	for (int o = 0; o < test.size(); o++)
	{
		wynik += (index(test[o]) * (pow(16, m)));
		m--;
	}
	return wynik;
}


vector<int> reszta(int n)
{
	vector<int>r;
	int temp=0;
	while (n>=16)
	{
		if (n > 240)
		{	
			if (n % 16 == 0)
			{
				r.push_back(0);
				n = n / 16;
			}
			else
			{
				temp = (int)n / 16;
				r.push_back(n - (temp * 16));
				n = temp;
			}	
		}
		else
		{
			if (n % 16 == 0)
			{
				r.push_back(0);
				r.push_back(n/16);
				//n /= 16;
				break;
			}
			else
			{
				temp = (int)(n / 16);
				r.push_back(n - (temp * 16));
				n = n - (temp * 16);
			}
			
		}
	}
	if(n <16&&temp!=0) r.push_back(temp);
	else if(n<=15) r.push_back(n);
	return r;
}


void dec_2_hex(int dec)
{
	vector<int>r = reszta(dec);
	wypisz(r);
}

void dzialania(int op, string hex1, string hex2)
{
	int a = hex_2_dec(hex1);
	int b = hex_2_dec(hex2);
	switch (op)
	{
		case 1:
		{
			cout << endl;
			cout << "HEX: "; dec_2_hex(a + b);
			cout << "DEC: " << a + b;
			break;
		}
		case 2:
		{
			cout << endl;
			cout << "HEX: "; dec_2_hex(a - b);
			cout << "DEC: " << a - b;
			break;
		}
		case 3:
		{
			cout << endl;
			cout << "HEX: "; dec_2_hex(a * b);
			cout << "DEC: " << a * b;
			break;
		}
		case 4:
		{
			cout << endl;
			if (b == 0) cout << 0;
			else
			{
				cout << "HEX (INT): "; dec_2_hex((int)(a/b));
				cout << "DEC (INT): " << (int)(a/b);
			}
		}
		default: break;
	}
}

void nr_er()
{
	printf("Nie ma takiej opcji!");
	Sleep(1000);
	system("cls");
}

int main()
{
	while (1)
	{
		int op;
		cout << "1. Hex to Dec" <<endl;
		cout << "2. Dec to Hex"<<endl;
		cout <<"3. Hex calc" << endl << endl;
		cout << "4. Exit" << endl;
		cout << "Wybor: "; cin >> op;
		switch (op)
		{
		case 1:
		{
			system("cls");
			string hex;
			printf("Podaj liczbe Hex: "); cin >> hex;
			cout << hex_2_dec(hex);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			int dec=0;
			printf("Podaj liczbe Dec: "); cin >> dec;
			dec_2_hex(dec);
			cout << endl;
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			string hex1, hex2;
			cout << "1.Dodawanie" << endl;
			cout << "2.Odejmowanie" << endl;
			cout << "3.Mnozenie" << endl;
			cout << "4.Dzielenie" << endl<<endl;
			cout << "Wybor: "; cin >> op;
			if (op > 4) nr_er();
			else
			{
				cout << "Pierwsza liczba hex:"; cin >> hex1;
				cout << "Druga liczba hex:"; cin >> hex2;
				dzialania(op, hex1, hex2);
				cout << endl;
				system("pause");
			}
			system("cls");
			break;
		}
		case 4:
		{
			return 0;
		}
		default: nr_er();
		}
	}
}