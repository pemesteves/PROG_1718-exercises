// Exercício 2.7, a.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int angulo = 0;
	
	double seno, cosseno, tangente;
	double const pi = acos(-1);
	
	cout << "ang      sen     cos     tan" << endl;

	while (angulo <= 90)
	{
		if (angulo != 90)
			cout << angulo << fixed << setprecision(5) << " " << sin(angulo*pi /180) << " " << cos(angulo*pi / 180) << " " << tan(angulo*pi / 180) << endl;
		else 
			cout << angulo << fixed << setprecision(5) << " " << sin(angulo*pi / 180) << " " << cos(angulo*pi / 180) << " infinito" << endl;
		
		angulo = angulo + 15;
	}

	system("pause");

    return 0;
}

