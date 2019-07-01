// Factorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include <iostream>
#include <stdio.h>
#include <time.h>

int main()
{
    //std::cout << "Hello World!\n"; 
	const int MOD = 1000000;
	
	int n, S=0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int f = 1;
		for (int j = 1; j <= i; j++)
		{
			f = f * j % MOD;
		}
		S = (S + f) % MOD;
	}
	
	
	printf("%d\n", S);


	printf("Time used = %.2f\n", (double)clock() / CLOCKS_PER_SEC);
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
