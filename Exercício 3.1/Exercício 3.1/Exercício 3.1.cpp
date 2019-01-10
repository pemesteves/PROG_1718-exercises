// Exercício 3.1.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>


using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
	double lado = 0;
	lado = sqrt((x2 - x1)*(x2-x1) + (y2 - y1)*(y2-y1));

	return lado;
}
double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double semiper = 0, resultado=0;
	double lado1 = distance(x1, y1, x2, y2);
	double lado2 = distance(x2, y2, x3, y3);
	double lado3 = distance(x1, y1, x3, y3);
	semiper = lado1 + lado2 +lado3;
	resultado = sqrt(semiper*(semiper - lado1)*(semiper - lado2)*(semiper - lado3));
	
	return resultado;
}

int main()
{
	double x1, y1, x2, y2, x3, y3;
	double resultado;

	cout << "Primeiro Vertice: ";
	cin >> x1 >> y1;
	cout << "Segundo Vertice: ";
	cin >> x2 >> y2;
	cout << "Terceiro Vertice: ";
	cin >> x3 >> y3;
	resultado = area(x1, y1, x2, y2, x3, y3);
	cout << "A area do seu triangulo e' " << resultado << endl;

	system("pause");

    return 0;
}

