#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	int T = 0;
	scanf("%d", &T);
	while (T)
	{
		T -= 1;
		int n = 0;
		scanf("%d", &n);
		int count[10] = {0};
		for (int i = 1; i <= n; i++)
		{
			int j = i;
			do
			{
				count[j % 10] += 1;
				j = j / 10;
			} while (j);
		}
		bool first = true;
		for (int k = 0; k < 10; k++)
		{
			if (first) first = false;
			else printf(" ");
			printf("%d", count[k]);
		}
		printf("\n");
	}


	return 0;
}