// Exerício 2.2, c.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double lado1;
	double lado2;
	double lado3;

	cout << "Quais sao os lados do seu triangulo?" << endl;
	cin >> lado1 >> lado2 >> lado3;

	if ((lado1 + lado2) <= lado3)
		cout << "Nao e' possivel construir um triangulo com esses lados." << endl;
	else if ((lado2 + lado3) <= lado1)
		cout << "Nao e' possivel construir um triangulo com esses lados." << endl; 
	else if ((lado1 + lado3) <= lado2)
		cout << "Nao e' possivel construir um triangulo com esses lados." << endl;
	else
		cout << "E' possivel construir um triangulo." << endl;

	system("pause");

    return 0;
}

