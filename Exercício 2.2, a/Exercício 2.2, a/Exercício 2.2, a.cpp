// Exercício 2.2, a.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int numero1, numero2, numero3, menor;
	
	cout << "Escreva 3 numeros: ";
	cin >> numero1 >> numero2 >> numero3;

	if (numero1 > numero2)
	{ 
		if (numero1 > numero3)
		{
			cout << "O maior numero e " << numero1 << endl;
			if (numero2 > numero3)
				cout << "O menor numero e " << numero3 << endl;
			else
				cout << "O menor numero e " << numero2 << endl;
		}
		else 
		{
			cout << "O maior numero e " << numero1 << endl;
			cout << "O menor numero e " << numero2 << endl;
		}
	}
	else if (numero2 > numero1)
		{
			if (numero2 > numero3)
			{
				cout << "O maior numero e " << numero2 << endl;
				if (numero1 > numero3)
					cout << "O menor numero e " << numero3 << endl;
				else
					cout << "O menor número e " << numero1 << endl;
			}
			else
			{
				cout << "O maior numero e " << numero3 << endl;
				cout << "O menor numero e " << numero1 << endl;
			}
		}
	else
	{
		cout << "O maior numero e " << numero3 << endl;
		if (numero1 > numero2)
			cout << "O menor numero e " << numero2 << endl;
		else
			cout << "O menor numero e " << numero1 << endl;
	}


	system("pause");

    return 0;

	
}

