// Exercício 2.9.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	cout << "Escreva uma sequencia de carateres (acabe com 0)" << endl;

	int menor, maior = 0, soma = 0, num_car = 0;
	int novo_num;
	cin >> novo_num;
	menor = novo_num;

	while (true)
	{
		if (novo_num == 0)
			break;
		if (novo_num < menor)
			menor = novo_num;
		if (novo_num > maior)
			maior = novo_num;
		soma = soma + novo_num;
		num_car = num_car + 1;
		cin >> novo_num;
	}

	cout << "Soma: " << soma << endl;
	cout << "Media: " << (double) soma / num_car << endl;
	cout << "Menor: " << menor << endl;
	cout << "Maior: " << maior << endl;

	system("pause");

    return 0;
}

