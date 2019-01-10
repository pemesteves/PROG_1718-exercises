// Exercício 2.6, a.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int n, teste;

	cout << "Indique um numero." << endl;
	cin >> n;

	teste = floor(sqrt(n));

	int i = 2;
	bool flag = true;

	if (n < 2)
		flag = false;

	do
	{
		if (flag == false)
		{
			cout << n << " nao e' primo." << endl;
			break;
		}
		
		if ((n % i) == 0)
			flag = false;

		i++;
	} while (i <= teste);

	if (flag == true)
		cout << n << " e' primo." << endl;
	else
		cout << n << " nao e' primo." << endl;

	system("pause");

    return 0;
}

