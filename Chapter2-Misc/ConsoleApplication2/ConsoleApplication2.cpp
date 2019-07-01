// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#define _CRT_SECURE_NO_WARNINGS

//#include "pch.h"
//#include <iostream>
#include <stdio.h>

//#include  <iomanip>
//#include  <cmath>
//#include <math.h>
//using namespace std;

int main()
{
	//double sum = 0;
	//cin >> a >> b;
	//cout << fixed;
	//cout.precision(0);
	//cout << double(pow(a, b)-1);
	//cout << sqrt(-10);
	//std::cout << "Hello World 1!\n"; 
	//scanf("%f%f", &a, &b);
	//a++;
	//printf("%.2f", a / b);
	//scanf("%lld", &n);
	//for (int i = 1; i <= n; i++)
		//printf("%d\n", i);
	//printf("\n%d\n", i);
	/*
	while (n > 1)
	{
		if (n % 2 == 1) n = 3 * n + 1;
		else n = n / 2;
		count = count + 1;
	}
	printf("%lld\n", count);
	*/
	
	double sum = 0, term =0;
	int i = 0;
	do
	{
		//term = ((i % 2) * (-2) + 1) * (-1) * 1.0 / (2 * i - 1);
		//sum += term;
		term = 1.0 / (2 * i + 1);
		if (i % 2 == 0) sum += term;
		else sum -= term;
		i += 1;
	} while (term > 1e-6);
	printf("%.6f\n", 4 * sum);
	
	
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
