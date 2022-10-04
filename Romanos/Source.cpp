#include <iostream>

using namespace std;

class Numeros
{
private:
	int ar1;
	string ro1;
public:
	Numeros(int numAra, string numRo)
	{
		ar1 = numAra;
		ro1 = numRo;
	}
	int value(char roman)
	{
		switch (roman)
		{
			case 'I':return 1;
			case 'V':return 5;
			case 'X':return 10;
			case 'L':return 50;
			case 'C':return 100;
			case 'D':return 500;
			case 'M':return 1000;
			/*case 'i':return 1;
			case 'v':return 5;
			case 'x':return 10;
			case 'l':return 50;
			case 'c':return 100;
			case 'd':return 500;
			case 'm':return 1000;*/
		}
	}

	void romanToInt()
	{
		string A = ro1;
		int i, n, ans = 0, p = 0;
		n = A.length() - 1;

		for (i = n; i >= 0; i--)
		{
			if (value(A[i]) >= p)
				ans = ans + value(A[i]);
			else
				ans = ans - value(A[i]);

			p = value(A[i]);
		}
		if (ans >= 4000)
		{
			cout << "\nError dato erroneo, no existe este numero romano";
		}
		else
		{
			cout << ans;
		}
	}

	void Arabigos_Ro()
	{
		int unidades = 0, decenas = 0, centenas = 0, millares = 0;

		if (ar1 >= 4000)
		{
			cout << "Por falta de caracteres no es posible hacer la conversion" << endl;
		}
		else
		{
			unidades = ar1 % 10; ar1 /= 10;
			decenas = ar1 % 10; ar1 /= 10;
			centenas = ar1 % 10; ar1 /= 10;
			millares = ar1 % 10; ar1 /= 10;

			cout << "la conversion es: ";

			switch (millares)
			{
				case 1: cout << "M"; break;
				case 2: cout << "MM"; break;
				case 3: cout << "MMM"; break;
			}

			switch (centenas)
			{
				case 1: cout << "C"; break;
				case 2: cout << "CC"; break;
				case 3: cout << "CCC"; break;
				case 4: cout << "CD"; break;
				case 5: cout << "D"; break;
				case 6: cout << "DC"; break;
				case 7: cout << "DCC"; break;
				case 8: cout << "DCCC"; break;
				case 9: cout << "CM"; break;
			}

			switch (decenas)
			{
				case 1: cout << "X"; break;
				case 2: cout << "XX"; break;
				case 3: cout << "XXX"; break;
				case 4: cout << "XL"; break;
				case 5: cout << "L"; break;
				case 6: cout << "LX"; break;
				case 7: cout << "LXX"; break;
				case 8: cout << "LXXX"; break;
				case 9: cout << "XC"; break;
			}

			switch (unidades)
			{
				case 1: cout << "I"; break;
				case 2: cout << "II"; break;
				case 3: cout << "III"; break;
				case 4: cout << "IV"; break;
				case 5: cout << "V"; break;
				case 6: cout << "VI"; break;
				case 7: cout << "VII"; break;
				case 8: cout << "VIII"; break;
				case 9: cout << "IX"; break;
			}
		}
	}
};
class Inicio
{
private:
	int ar, op1, op2;
	string ro;
public:
	Inicio()
	{
		ar = 0;
		ro = "";
		op1 = 0; 
		op2 = 0;
	}
	void run()
	{
		do {
			cout << "Bienvenido introduzca la opcion que desea seleccionar\n1. Romanos a Arabigos\n2. Arabigos a romanos" << endl;
			cin >> op1;
			system("cls");
			Numeros* num1;
			Numeros* num2;
			switch (op1)
			{
			case 1:
				cout << "Introduzca un numero Romano del 1 al 3999 'USE SOLO LETRAS MAYUSCULAS' : " << endl;
				cin >> ro;

				num1 = new Numeros(ar, ro);
				num1->romanToInt();

				break;

			case 2:
				cout << "Introduzca un numero Arabigo del 1 al 3999: " << endl;
				cin >> ar;

				num2 = new Numeros(ar, ro);
				num2->Arabigos_Ro();

				break;
			}
			cout << "\n\nIntroduzca la opcion\n1. Seguir en el programa\n2. Salir del programa" << endl;
			cin >> op2;
			system("cls");
		} while (op2 != 2);
	}
};
int main()//llama a todas las funciones
{
	Inicio menu;
	menu.run();
}