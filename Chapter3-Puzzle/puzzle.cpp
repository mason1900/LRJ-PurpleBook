#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#define maxa 10
#define maxb 200

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>

const int lencase = 5;

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	char matrix[maxa][maxa];
	bool end = false;
	int count = 0;
	memset(matrix, '\0', sizeof(matrix));
	bool firstcase = true;
	while (true)
	{
		int x = -1, y=-1;
		for (int i = 0; i < 5; i++)
		{
			char *s = matrix[i];
			// note: some test cases in udebug has redundant trailing blank space.
			// this solution does not deal with illegal inputs but you can get an AC.
			fgets(s, lencase + 2, stdin);
			if (s[0] && s[0] == 'Z')
			{
				end = true;
				break;
			}
			if ((int)strlen(s) == lencase) //'\n'
			{
				s[lencase - 1] = ' ';
				s[lencase] = '\n';
			}

			for (int j = 0; j < (int)strlen(s); j++)
			{
				if (s[j] == ' ')
				{
					x = i;
					y = j;
				}
			}
			//for (int i = 0; i < 10; i++) printf("%c", s[i]);
			//printf("%s", matrix[i]);
		}
		if (end) break;

		char order[maxb] = "\0";
		char s[maxb] = "\0";
		bool flag = true;
		scanf("%s", order);
		while (true)
		{
			if (order[strlen(order) - 1] == '0') break;
			scanf("%s", s);
			strcat(order, s);
		}
		//Eliminate remaining '\n' after scanf
		getchar();

		//printf("%s", order);
		for (int i = 0; i < (int)(strlen(order)-1); i++)
		{
			if (order[i] == 'A')
			{
				if ((x - 1) < 0)
				{
					flag = false;
					break;
				}
				char temp = matrix[x - 1][y];
				matrix[x - 1][y] = ' ';
				matrix[x][y] = temp;
				x = x - 1;
			}
			else if (order[i] == 'B')
			{
				if ((x + 1) >= lencase)
				{
					flag = false;
					break;
				}
				char temp = matrix[x + 1][y];
				matrix[x + 1][y] = ' ';
				matrix[x][y] = temp;
				x = x + 1;
			}
			else if (order[i] == 'L')
			{
				if ((y - 1) < 0)
				{
					flag = false;
					break;
				}
				char temp = matrix[x][y - 1];
				matrix[x][y - 1] = ' ';
				matrix[x][y] = temp;
				y = y - 1;
			}
			else if (order[i] == 'R')
			{
				if ((y + 1) >= lencase)
				{
					flag = false;
					break;
				}
				char temp = matrix[x][y + 1];
				matrix[x][y + 1] = ' ';
				matrix[x][y] = temp;
				y = y + 1;
			}
			else
			{
				flag = false;
				break;
			}
		}
		if (flag)
		{
			count += 1;
			if (firstcase) firstcase = false;
			else printf("\n");
			printf("Puzzle #%d:\n", count);
			
			for (int i = 0; i < lencase; i++)
			{
				bool first = true;
				for (int j = 0; j < lencase; j++)
				{
					if (first) first = false;
					else printf(" ");
					printf("%c", matrix[i][j]);
				}
				printf("\n");
			}
		}
		else
		{
			count += 1;
			if (firstcase) firstcase = false;
			else printf("\n");
			printf("Puzzle #%d:\n", count);
			printf("This puzzle has no final configuration.\n");
		}



		memset(matrix, '\0', sizeof(matrix));
		memset(order, '\0', sizeof(order));
		memset(s, '\0', sizeof(s));
	}



	return 0;
}