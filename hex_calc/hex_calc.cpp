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

void hex_2_dec(string hex)
{
	vector<char>test = string_2_vec(hex);
	int i, o, wynik=0, m = test.size()-1;
	cout << "HEX " << hex << " = ";
	for (i = 0; i <= 15; i++)
	{
		for (o = 0; o < test.size(); o++)
		{
			if (test[o] == hex_list[i])
			{
				printf("(%i *16^%i)", i, m);
				if (m > 0) cout << " + ";
				wynik += (i * (pow(16, m)));
				m--;
			}
		}
	}
	cout << " = " << wynik << "D" << endl;
}
/*static vector<int>res;
int reszta(int n)
{
	if (n == 0)
	{
		//res.push_back(n);
		return 0;
	}
	if (n % 15 != 0)
	{
		res.push_back(n % 15);
		return reszta(n - 1);
	}
	else
	{
		res.push_back(n-15);
		return reszta(n-15);
	}
	for (int i = 1; i * 15 < n; i++)
	{
		//cout << i << "\t" << n-i << endl;
		dziel = i;
	}
	
}*/

void dec_2_hex(int dec)
{
	//TODO
	/*reszta(dec);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << "\t";
	}
	//cout << reszta[0];
	*/
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