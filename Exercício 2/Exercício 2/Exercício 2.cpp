// Exercício 2.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	double media, a_media, b_media, c_media, numeroA, numeroB, numeroC;
	cout << "A ? ";
	cin >> numeroA;
	cout << "B ? ";
	cin >> numeroB;
	cout << "C ? ";
	cin >> numeroC;

	media = (numeroA + numeroB + numeroC) / 3;

	a_media = numeroA - media;
	b_media = numeroB - media;
	c_media = numeroC - media;

	cout << "media   = " << media << endl;
	cout << "A-media = " << a_media << endl;
	cout << "B-media = " << b_media << endl;
	cout << "C-media = " << c_media << endl;

	system("pause");

    return 0;
}

