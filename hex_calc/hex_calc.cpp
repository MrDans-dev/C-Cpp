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

void hex_2_dec(string hex)
{
	vector<char>test = string_2_vec(hex);
	int m = test.size() - 1,wynik =0;
	cout << "HEX " << hex << " = ";
	for (int o = 0; o < test.size(); o++)
	{
		printf("(%i *16^%i)", index(test[o]), m);
		if (m > 0) cout << " + ";
		wynik += (index(test[o]) * (pow(16, m)));
		m--;
	}
	cout << " = " << wynik << " D" << endl;
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
	if(n <16) r.push_back(temp);
	return r;
}


void dec_2_hex(int dec)
{
	vector<int>r = reszta(dec);
	wypisz(r);
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
			hex_2_dec(hex);
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
		case 4:
		{
			return 0;
		}
		default: nr_er();
		}
	}
}