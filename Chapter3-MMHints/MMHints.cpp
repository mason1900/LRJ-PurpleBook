#define _CRT_SECURE_NO_WARNINGS
#define maxn 1010
#define LOCAL


#include <cstdio>
using namespace std;

int a[maxn], b[maxn];


int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	int n = 0;
	int kase = 1;
	while (scanf("%d", &n) == 1 && n)
	{
		printf("Game %d:\n", kase);
		kase += 1;
		// correct answers
		for (int i = 0; i < n; i++)
		{
			scanf("%d", &a[i]);
		}
		//guesses
		while (true)
		{
			int A = 0, B = 0;
			for (int j = 0; j < n; j++)
			{
				scanf("%d", &b[j]);
				if (a[j] == b[j]) A++;
			}
			if (b[0] == 0) break;
			for (int d = 1; d <= 9; d++)
			{
				int c1 = 0, c2 = 0;
				for (int k = 0; k < n; k++)
				{
					if (a[k] == d) c1++;
					if (b[k] == d) c2++;
				}
				if (c1 < c2) B += c1;
				else B += c2;
			}
			printf("    (%d,%d)\n", A, B - A);
		}
	}

	return 0;
}
