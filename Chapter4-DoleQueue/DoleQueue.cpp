#define _CRT_SECURE_NO_WARNINGS
//#define LOCAL

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <functional>
#include <algorithm>
using namespace std;


const int maxn = 25;
int n, k, m, a[maxn];

int go(int p, int d, int t)
{
	while (t)
	{
		t -= 1;
		do
		{
			// -1 +1 because for backward, 0 is not a valid number
			p = (p + d + n -1) % n + 1; 
		} while (a[p]==0);
	}
	return p;
}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	while (scanf("%d%d%d", &n, &k, &m) == 3 && n)
	{
		for (int i = 1; i <= n; i++) a[i] = i;
		int left = n;
		// note: start from 1 but p1 = n. Read instructions
		int p1 = n, p2 = 1; 
		while (left)
		{
			p1 = go(p1, 1, k);
			p2 = go(p2, -1, m);
			printf("%3d", p1);
			left -= 1;
			if(p2 != p1)
			{
				printf("%3d", p2);
				left -= 1;
			}
			a[p1] = a[p2] = 0;
			if (left) printf(",");
		}
		printf("\n");

	}

	return 0;
}