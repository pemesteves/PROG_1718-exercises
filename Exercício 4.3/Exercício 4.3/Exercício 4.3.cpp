// Exercício 4.3.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

void decompose(string compound)
{
	bool flag=0;
	string nova_string;

	for (int i = 0; i < compound.length(); i++)
	{
		if (flag)
		{
			if (compound[i] >= 97 && compound[i] <= 122)
				nova_string = nova_string + compound[i];
			else if (compound[i] >= 48 && compound[i] <= 57)
			{
				cout << nova_string << endl;
				flag = 0;
			}
			else
			{
				cout << nova_string << endl;
				nova_string = compound[i];
			}
		}
		else
		{
			nova_string = compound[i];
			flag = 1;
		}
	}
	
	if (flag)
		cout << nova_string << endl;
}

int main()
{
	string element;
	cout << "Indique um elemento quimico: ";
	cin >> element;
	decompose(element);

	system("pause");

    return 0;
}

