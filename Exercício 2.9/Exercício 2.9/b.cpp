// Exercício 2.9.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int comprimento;

	cout << "Indique o  comprimento da sequencia: " << endl;
	cin >> comprimento;
	cout << "Escreva a sequencia:" << endl;
	
	int menor, maior, soma;
	int novo_num;
	cin >> novo_num;
	menor = novo_num;
	maior = novo_num;
	soma = novo_num;

	for (int i = 1; i < comprimento; i++)
	{
		if (novo_num < menor)
			menor = novo_num;
		if (novo_num > maior)
			maior = novo_num;
		soma = soma + novo_num;
		cin >> novo_num;
	}

	cout << "Soma: " << soma << endl;
	cout << "Media: " << (double)soma / comprimento<< endl;
	cout << "Menor: " << menor << endl;
	cout << "Maior: " << maior << endl;

	system("pause");

	return 0;
}