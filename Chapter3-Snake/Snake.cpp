#define maxn 20
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>

int matrix[maxn][maxn];

int main()
{
	int n, x, y, tot = 0;
	scanf("%d", &n);
	memset(matrix, 0, sizeof(matrix));
	tot = matrix[x = 0][y = n - 1] = 1;
	while (tot < n*n)
	{
		while (x + 1 < n && !matrix[x + 1][y]) matrix[++x][y] = ++tot;
		while (y - 1 >= 0 && !matrix[x][y - 1]) matrix[x][--y] = ++tot;
		while (x - 1 >= 0 && !matrix[x - 1][y]) matrix[--x][y] = ++tot;
		while (y + 1 < n && !matrix[x][y + 1]) matrix[x][++y] = ++tot;
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