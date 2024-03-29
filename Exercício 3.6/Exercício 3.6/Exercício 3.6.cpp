// Exercício 3.6.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>

using namespace std;

bool bissexto(int ano)
{
	bool bis = false;
	if (ano % 4 == 0)
	{
		if (ano % 400 == 0)
			bis = true;
		else if (ano % 100 == 0);
		else
			bis = true;
	}

	return bis;
}

int num_dias(int mes, int ano)
{
	int dias;

	if (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)
		dias = 31;
	else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
		dias = 30;
	else if (bissexto(ano))
		dias = 29;
	else
		dias = 28;

	return dias;
}

int codigo(int mes, int ano)
{
	int c;
	if (mes == 3 || mes == 11)
		c = 3;
	else if (mes == 4 || mes == 7)
		c = 6;
	else if (mes == 5)
		c = 1;
	else if (mes == 6)
		c = 4;
	else if (mes == 8)
		c = 2;
	else if (mes == 9 || mes == 12)
		c = 5;
	else if (mes == 10)
		c = 0;
	else if (bissexto(ano))
	{
		if (mes == 1)
			c = 6;
		else
			c = 2;
	}
	else
	{
		if (mes == 1)
			c = 0;
		else
			c = 3;
	}

	return c;
}

/*
void dia_semana(int dia, int mes, int ano)
{
	int ds; //dia da semana
	int s = ano / 100; //primeiros digitos do ano
	int a = ano % 100; //ultimos 2 digitos do ano
	int c = codigo(mes, ano); //codigo do mes
	int b = (5 * a) / 4; //operador "contido em"

	ds = (b + c + dia - 2*(s % 4) + 7) % 7;

	switch (ds)
	{
	case 0:
		cout << "Sabado";
		break;
	case 1:
		cout << "Domingo";
		break;
	case 2:
		cout << "Segunda-feira";
		break;
	case 3:
		cout << "Terça-feira";
		break;
	case 4:
		cout << "Quarta-feira";
		break;
	case 5:
		cout << "Quinta-feira";
		break;
	case 6:
		cout << "Sexta-feira";
		break;
	}

	return;
}
*/

int dia_semana(int dia, int mes, int ano)
{
	int ds; //dia da semana
	int s = ano / 100; //primeiros digitos do ano
	int a = ano % 100; //ultimos 2 digitos do ano
	int c = codigo(mes, ano); //codigo do mes
	int b = (5 * a) / 4; //operador "contido em"

	ds = (b + c + dia - 2 * (s % 4) + 7) % 7;

	if (ds == 0)
		ds = 7;

	return ds;
}

void mostra_mes(int m)
{
	if (m == 1)
		cout << "Janeiro";
	else if (m == 2)
		cout << "Fevereiro";
	else if (m == 3)
		cout << "Marco";
	else if (m == 4)
		cout << "Abril";
	else if (m == 5)
		cout << "Maio";
	else if (m == 6)
		cout << "Junho";
	else if (m == 7)
		cout << "Julho";
	else if (m == 8)
		cout << "Agosto";
	else if (m == 9)
		cout << "Setembro";
	else if (m == 10)
		cout << "Outubro";
	else if (m == 11)
		cout << "Novembro";
	else
		cout << "Dezembro";
}

void mes_calendario(int mes, int ano)
{
	int dia_inicial = 1; //dia do mes

	//Linha Inicial
	cout << setw(4);
	mostra_mes(mes);
	cout << "/" << ano << endl;
	//

	//Linha dos Dias da Semana
	cout << setw(4) << "Dom" << setw(4);
	cout << "Seg" << setw(4);
	cout << "Ter" << setw(4);
	cout << "Qua" << setw(4);
	cout << "Qui" << setw(4);
	cout << "Sex" << setw(4);
	cout << "Sab" << endl;
	//Fim Linha Dias

	//Inicio da Tabela
	dia_inicial = dia_semana(dia_inicial, mes, ano);

	int dia = 1;
	cout << setw(dia_inicial * 4);

	while (dia_inicial <= 7)
	{
		cout << dia << setw(4);
		dia++;
		dia_inicial++;
	}
	cout << endl;
	//Fim

	int dia_final = num_dias(mes, ano);

	//Outras Linhas
	while (dia <= dia_final)
	{
		dia_inicial = 1;
		cout << setw(4);

		while (dia_inicial <= 7)
		{
			if (dia > dia_final)
				break;
			cout << dia << setw(4);
			dia++;
			dia_inicial++;
		}

		cout << endl;
	}

}

int main()
{
	int mes = 1;
	int ano;
	cout << "Indique o ano ! ";
	cin >> ano;

	while (mes <= 12)
	{
		cout << endl << endl << endl;
		mes_calendario(mes, ano);
		mes++;
	}

	system("pause");

	return 0;
}

