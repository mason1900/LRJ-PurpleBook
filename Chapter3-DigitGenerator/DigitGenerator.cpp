#define _CRT_SECURE_NO_WARNINGS
#define maxn 100005

#include <cstdio>
#include <cstring>
using namespace std;

int a[maxn];


int main()
{
	memset(a, 0, sizeof(a));
	for (int i = 1; i < maxn; i++)
	{
		int x = i, y = i;
		while (x > 0)
		{
			y += x % 10;
			x = x / 10;
		}
		if(a[y] == 0 || i < a[y]) a[y] = i;
	}

	int T;
	scanf("%d", &T);
	while (T > 0)
	{
		T -= 1;
		int n;
		scanf("%d", &n);
		printf("%d\n", a[n]);
	}


	return 0;
}