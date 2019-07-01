// daffodil.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include <iostream>
#include <stdio.h>
#include <math.h>

int main()
{
    //std::cout << "Hello World!\n"; 
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				int abc = i * i * i + j * j * j + k * k * k;
				if (abc % 10 == k)
				{
					abc = abc / 10;
					if (abc % 10 == j)
					{
						abc = abc / 10;
						if (abc % 10 == i)
						{
							printf("%d%d%d ", i, j, k);
						}
					}
				}
			}
		}
	}
	printf("\n");
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
