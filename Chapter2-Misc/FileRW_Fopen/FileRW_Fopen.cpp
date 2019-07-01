// FileRW_Fopen.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include <iostream>
#include <stdio.h>
#define INF 1000000000

int main()
{
	FILE *fin, *fout;
	fin = fopen("data.in", "rb");
	fout = fopen("data.out", "wb");
	freopen("data2.in", "r", stdin);
	freopen("data2.out", "w", stdout);

	int x, n = 0, min = INF, max = -INF, s = 0;
	
	while (scanf("%d", &x) == 1)
	{
		printf("%d", x);
	}

	//Note: if opened in solution explorer: in source file location.
	// if opened in folder view: in program location (debug folder)
	
	while (fscanf(fin, "%d", &x) == 1)
	{
		s += x;
		if (x < min)min = x;
		if (x > max)max = x;
		n += 1;
	}
	fprintf(fout, "%d %d %.3f", min, max, (double)s / n);
	fclose(fin);
	fclose(fout);
	return 0;
	//std::cout << "Hello World!\n"; 

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
