// Exercício 2.6, c.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;


int main()
{
	int n = 2;

	cout << n << endl;

	while (n <= 10000)
	{
		int teste;

		teste = floor(sqrt(n));

		int i = 2;
		bool flag = true;

		if (n < 2)
			flag = false;

		do
		{
			if (flag == false)
				break;

			if ((n % i) == 0)
				flag = false;

			i++;
		} while (i <= teste);

		if (flag == true)
			cout << n << endl;
		n++;
	}

	system("pause");

	return 0;
}