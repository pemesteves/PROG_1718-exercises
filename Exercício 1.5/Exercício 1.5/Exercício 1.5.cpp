// Exercício 1.5.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int main()
{
	int hora1, min1, seg1;
	int hora2, min2, seg2;
	int result_dias, result_horas, result_min, result_seg;
	cout << "Tempo 1 (horas minutos segundos) ? ";
	cin >> hora1 >> min1 >> seg1;
	cout << "Tempo 2 (horas minutos segundos) ? ";
	cin >> hora2 >> min2 >> seg2;

	result_dias = result_horas = result_min = result_seg = 0;

	result_seg = seg1 + seg2;
	
	if (result_seg >= 60)
	{
		result_seg = result_seg - 60;
		result_min = 1;
	}

	result_min = result_min + min1 + min2;

	if (result_min >= 60)
	{
		result_min = result_min - 60;
		result_horas = 1;
	}

	result_horas = result_horas + hora1 + hora2;

	if (result_horas >= 24)
	{
		result_horas = result_horas - 24;
		result_dias = 1;
	}

	cout << "Soma dos tempos: ";
	cout << result_dias << " dia, ";
	cout << result_horas << " horas, ";
	cout << result_min << " minutos e ";
	cout << result_seg << " segundos" << endl;

	system("pause");

    return 0;
}

