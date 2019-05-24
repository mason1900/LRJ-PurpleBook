#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#define maxa 15

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct Square
{
	bool eligible;
	int num;
	bool right;
	bool down;
};


int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	int kase = 0;
	bool firstcase = true;
	while (true)
	{
		int r = 0, c = 0;
		scanf("%d%d", &r, &c);

		if (r == 0) break;
		kase += 1;

		char matrix[maxa][maxa];
		memset(matrix, '\0', sizeof(matrix));
		for (int i = 0; i < r; i++)
		{
			char s[maxa];
			scanf("%s", s);
			strcpy(matrix[i], s);
			//printf("%s\n", matrix[i]);
		}

		int count = 0;
		Square sq[maxa][maxa];		
		//set bool to false, num=0
		memset(&sq, 0, sizeof(sq));

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				sq[i][j].eligible = false;

				if (matrix[i][j] == '*') continue;

				bool flag = true;
				if (((j == 0) && matrix[i][j] !='*') || (matrix[i][j - 1] == '*'))
				{
					if (flag) { flag = false; count += 1;}
					sq[i][j].eligible = true;
					sq[i][j].num = count;
					sq[i][j].right = true;
				}
				if (((i == 0) && matrix[i][j] != '*') || (matrix[i-1][j] == '*'))
				{
					if (flag) { flag = false; count += 1; }
					sq[i][j].eligible = true;
					sq[i][j].num = count;
					sq[i][j].down = true;
				}
			}
		}
		/*
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < r; j++)
			{
				if (matrix[i][j] == '*') printf("*\t");
				else if (sq[i][j].eligible) printf("%d\t", sq[i][j].num);
				else printf("X\t");
			}
			printf("\n");
		}
		*/
		if (firstcase) firstcase = false;
		else printf("\n");
		printf("puzzle #%d:\n", kase);
		printf("Across\n");

		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (sq[i][j].eligible == true && sq[i][j].right == true)
				{
					printf("%3d.", sq[i][j].num);
					for (int k = j; (k < c) && (matrix[i][k] != '*'); k++)
					{
						putchar(matrix[i][k]);
					}
					printf("\n");
				}
			}
		}
		printf("Down\n");
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (sq[i][j].eligible == true && sq[i][j].down == true)
				{
					printf("%3d.", sq[i][j].num);
					for (int k = i; (k < r) && (matrix[k][j] != '*'); k++)
					{
						putchar(matrix[k][j]);
					}
					printf("\n");
				}
			}
		}




	}
	
	return 0;
}
