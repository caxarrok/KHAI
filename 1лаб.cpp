// ConsoleApplication4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
using namespace std;
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE); 

int main()
{
	SetConsoleTitle(L"Oskorbina Masha 117");
	setlocale(LC_ALL, "Russian");
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_BLUE |
		FOREGROUND_INTENSITY);
	cout << "Hello,student\n";
	double x, y;
	cout << "Type your number ";
	cin >> x;
	cout << "Type other number ";
	cin >> y;
	int sum = x + y;
	cout << "\nSum is:" << sum;
	int sub = x - y;
	cout << "\nSubtraction is:"<< sub;
	int mult = x * y;
	cout << "\nMultiplication is:" << mult;
	int div = x / y;
	cout << "\nDivision is:" << div;
	system("pause");
	SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN);
	cout << "Chto-to" << endl;
	_getch();
	return 0;
	
	




		
}