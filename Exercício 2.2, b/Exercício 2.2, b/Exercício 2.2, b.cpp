// Exercício 2.2, b.cpp : define o ponto de entrada para o aplicativo do console.
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
			cout << numero1 << " > ";
			if (numero2 > numero3)
				cout << numero2 << " > " << numero3 << endl;
			else 
				cout << numero3 << " > " << numero2 << endl;
		}
		else
			cout << numero3 << " > " << numero1 << " > " << numero2 << endl;
			
	}
	else if (numero2 > numero1)
	{
		if (numero2 > numero3)
		{
			cout << numero2 << " > ";
			if (numero1 > numero3)
				cout << numero1 << " > " << numero3 << endl;
			else
				cout << numero3 << " > " << numero1 << endl;
		}
		else
			cout <<  numero3 << " > " << numero2 << " > " << numero1 << endl;
	}
	else
	{
		cout << numero3 << " > ";
		if (numero1 > numero2)
			cout << numero1 << " > " << numero2 << endl;
		else
			cout << numero2 << " > " << numero1 << endl;
	}

	system("pause");

    return 0;
}

