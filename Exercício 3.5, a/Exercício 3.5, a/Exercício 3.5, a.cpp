// Exercício 3.5, a.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int mdc(int n1, int n2)
{
	int resto = n1 % n2;
	while (resto != 0)
	{
		n1 = n2;
		n2 = resto;
		resto = n1 % n2;
	}
	return n2;
}

int mmc(int n1, int n2)
{
	int a;
	a = mdc(n1, n2);

	return (n1 * n2) / a;
}

bool readFracc(int &numerator, char &operation, int &denominator)
{
	bool fraction = true;
	if (operation != '/')
		fraction = false;
	else if (denominator == 0 || denominator == 1)
		fraction = false;
	else if (!(numerator && denominator))
		fraction = false;
	return fraction;
}

void writeFracc(int numerator, int denominator)
{
	cout << numerator << '/' << denominator << endl;
}

void reduceFracc(int &numerator, int &denominator)
{
	int n2 = mdc (numerator, denominator);
	numerator = numerator / n2;
	denominator = denominator / n2;
}


void sum_frac(int numerator1, int denominator1, int numerator2, int denominator2)
{
	if (denominator1 == denominator2)
	{
		int numerator = numerator1 + numerator2;
		reduceFracc(numerator, denominator1);
		writeFracc(numerator, denominator1);
	}
	else
	{
		int denominator = mmc(denominator1, denominator2);
		int numerator = (denominator / denominator1) * numerator1 + (denominator / denominator2) * numerator2;
		reduceFracc(numerator, denominator);
		writeFracc(numerator, denominator);
	}
}

void sub_frac(int numerator1, int denominator1, int numerator2, int denominator2)
{
	if (denominator1 == denominator2)
	{
		int numerator = numerator1 + numerator2;
		reduceFracc(numerator, denominator1);
		writeFracc(numerator, denominator1);
	}
	else
	{
		int denominator = mmc(denominator1, denominator2);
		int numerator = (denominator / denominator1) * numerator1 - (denominator / denominator2) * numerator2;
		reduceFracc(numerator, denominator);
		writeFracc(numerator, denominator);
	}
}

void mult_frac(int numerator1, int denominator1, int numerator2, int denominator2)
{
	int numerator = numerator1 * numerator2;
	int denominator = denominator1 * denominator2;
	reduceFracc(numerator, denominator);
	writeFracc(numerator, denominator);
}

void div_frac(int numerator1, int denominator1, int numerator2, int denominator2)
{
	mult_frac(numerator1, denominator1, denominator2, numerator2);
}

int main()
{
	int num, denom;
	char operation;

	cout << "Indique uma fracao (formato Numerador/Denominador - ambos inteiros): ";
	cin >> num >> operation >> denom;

	while (!readFracc(num, operation, denom))
	{
		cout << "Indique uma fracao (formato Numerador/Denominador - ambos inteiros): ";
		cin >> num >> operation >> denom;
	}

	reduceFracc(num, denom);
	writeFracc(num, denom);

	bool do_cicle = true, valid_operation;

	while (do_cicle)
	{
		char oper; //we will do this operation
		do
		{
			cout << "O que pretende fazer? Somar(+), subtrair(-), multiplicar(*) ou dividir(/) outra fracao?" << endl;
			cin >> oper;
			if (oper == '+' || oper == '-' || oper == '*' || oper == '/')
				valid_operation = true;
			else
			{
				valid_operation = false;
				cerr << "Nao e' valida." << endl;
			}
		} while (!valid_operation);

		cout << "Que fracao quer adicionar 'a sua operacao?" << endl;

		int other_numerator, other_denominator;
		char other_operation;

		cin >> other_numerator >> other_operation >> other_denominator;
		while (!readFracc(other_numerator, other_operation, other_denominator))
		{
			cout << "Indique outra fracao";
			cin >> other_numerator >> other_operation >> other_denominator;
		}
		reduceFracc(other_numerator, other_denominator);

		switch (oper)
		{
		case '+':
			sum_frac(num, denom, other_numerator, other_denominator);
			break;
		case '-':
			sub_frac(num, denom, other_numerator, other_denominator);
			break;
		case '*':
			mult_frac(num, denom, other_numerator, other_denominator);
			break;
		case '/':
			div_frac(num, denom, other_numerator, other_denominator);
			break;
		}

		char another_operation;

		cout << "Pretende realizar outra operacao?(N -> Nao continuar) " << endl;
		cin >> another_operation;
		if (another_operation == 'N' || another_operation == 'n')
			do_cicle = false;
	}

	return 0;
}

