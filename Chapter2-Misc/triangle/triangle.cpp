#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	//printf("Hello\n");
	int n = 0;
	scanf("%d", &n);
	for (int i = n; i >= 1; i--)
	{
		//int j = 2 * i - 1;
		//int k = n - i;
		for (int k = n - i; k > 0; k--) printf(" ");
		for (int j = 2 * i - 1; j > 0; j--) printf("#");
		//for (int k = n - i; k > 0; k--) printf(" ");
		printf("\n");
	}
	
	return 0;
}