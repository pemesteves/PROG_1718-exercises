// Exercício 1.3.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	const double PI = acos(-1) ;
	double p, r, M;

	cout << "p (Kg/m^3) = ";
	cin >> p;
	cout << "r (m) = ";
	cin >> r;
	
	M = (4*p*PI*r*r*r)/3;

	cout << "M (Kg) = " << M << endl;

	system("pause");
	
	
	
	return 0;
}

