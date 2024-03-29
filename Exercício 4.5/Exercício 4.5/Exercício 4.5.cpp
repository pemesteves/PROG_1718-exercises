// Exercício 4.5.cpp : define o ponto de entrada para o aplicativo do console.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Fraction {
	int numerator;
	int denominator;
};

Fraction readFracc()
{
	Fraction f;
	cout << "Numerator? ";
	cin >> f.numerator;
	cout << "Denominator? ";
	cin >> f.denominator;

	return f;
}

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

Fraction reduceFracc(Fraction f)
{
	int max_div;
	max_div = mdc(f.numerator, f.denominator);
	f.numerator = f.numerator / max_div;
	f.denominator = f.denominator / max_div;

	return f;
}

void writeFracc(Fraction f)
{
	cout << f.numerator << '/' << f.denominator << endl;
}

int mmc(int n1, int n2)
{
	int a;
	a = mdc(n1, n2);

	return (n1 * n2) / a;
}


void sum_frac(Fraction f1, Fraction f2)
{
	if (f1.denominator == f2.denominator)
	{
		f1.numerator = f1.numerator + f2.numerator;
		reduceFracc(f1);
		writeFracc(f1);
	}
	else
	{
		int min_mult;
		min_mult = mmc(f1.denominator, f2.denominator);
		f1.numerator = f1.numerator * (min_mult / f1.denominator);
		f2.numerator = f2.numerator * (min_mult / f2.numerator);
		f1.numerator = f1.numerator + f2.numerator;
		f1.denominator = min_mult;
		reduceFracc(f1);
		writeFracc(f1);
	}
}

void sub_frac(Fraction f1, Fraction f2)
{
	if (f1.denominator == f2.denominator)
	{
		f1.numerator = f1.numerator - f2.numerator;
		reduceFracc(f1);
		writeFracc(f1);
	}
	else
	{
		int min_mult;
		min_mult = mmc(f1.denominator, f2.denominator);
		f1.numerator = f1.numerator * (min_mult / f1.denominator);
		f2.numerator = f2.numerator * (min_mult / f2.numerator);
		f1.numerator = f1.numerator - f2.numerator;
		f1.denominator = min_mult;
		reduceFracc(f1);
		writeFracc(f1);
	}
}

void mult_frac(Fraction f1, Fraction f2)
{
	f1.numerator = f1.numerator * f2.numerator;
	f1.denominator = f1.denominator * f2.denominator;
	reduceFracc(f1);
	writeFracc(f1);
}

void div_frac(Fraction f1, Fraction f2)
{
	int num = f2.numerator;
	f2.numerator = f2.denominator;
	f2.denominator = num;
	mult_frac(f1, f2);
}

int main()
{
	Fraction fraction1;

	fraction1 = readFracc();

	reduceFracc(fraction1);
	writeFracc(fraction1);\

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

		Fraction fraction2; 

		fraction2 = readFracc();

		switch (oper)
		{
		case '+':
			sum_frac(fraction1, fraction2);
			break;
		case '-':
			sub_frac(fraction1, fraction2);
			break;
		case '*':
			mult_frac(fraction1, fraction2);
			break;
		case '/':
			div_frac(fraction1, fraction2);
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

