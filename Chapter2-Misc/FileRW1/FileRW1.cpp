// FileRW1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
//#include <iostream>
#include <stdio.h>
#define INF 1000000000
int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	int x, n = 0, min = INF, max = -INF, s = 0;
	
	// -1 when scanf finished
	while (scanf("%d", &x) == 1)
	{
		s += x;
		if (x < min) min = x;
		if (x > max)max = x;
		n += 1;
	}
	printf("%d %d %.3f", min, max, (double)s / n);


	//std::cout << "Hello World!\n"; 
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
