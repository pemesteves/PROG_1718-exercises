// Exercício 3.8.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

void mdc(int m, int n)
{
	if (m%n == 0)
		cout << "O maximo divisor comum e' " << n << endl;
	else
		mdc(n, m%n);
}

int main()
{
	int num1, num2;
	cout << "Indique dois numeros inteiros ! ";
	cin >> num1 >> num2;
	mdc(num1, num2);

	system("pause");

	return 0;
}

