// hanxin.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
//#include <iostream>
#include <stdio.h>

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	int a, b, c, result;
	while (scanf("%d %d %d", &a, &b, &c) == 3)
	{
		result = (70 * a + 21 * b + 15 * c) % (3*5*7);
		if (result >= 10 && result <= 100)
		{
			printf("%d\n", result);
		}
		else
		{
			printf("No answer\n");
		}

	}


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
