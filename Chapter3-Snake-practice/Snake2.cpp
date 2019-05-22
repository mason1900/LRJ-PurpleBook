/*
n=4
2	4	6	8
24	26	28	10
22	32	30	12
20	18	16	14
*/

#define maxn 20
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

using namespace std;

int matrix[maxn][maxn];

int main() {
	int n, x, y, tot;
	memset(matrix, 0, sizeof(matrix));
	scanf("%d", &n);
	tot = matrix[x=0][y=0] = 2;
	while (tot < 2 * n*n)
	{
		while (y + 1 < n && !matrix[x][y + 1])
		{
			tot += 2;
			matrix[x][++y] = tot;
		}
		while (x + 1 < n && !matrix[x + 1][y])
		{
			tot += 2;
			matrix[++x][y] = tot;
		}
		while (y - 1 >= 0 && !matrix[x][y-1])
		{
			tot += 2;
			matrix[x][--y] = tot;
		}
		while (x - 1 > 0 && !matrix[x - 1][y])
		{
			tot += 2;
			matrix[--x][y] = tot;
		}
	}
	
	for (int i = 0; i < n; i++)
	{
		bool first = true;
		for (int j = 0; j < n; j++)
		{
			if (first) first = false;
			else printf("\t");
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}

	return 0;
}
