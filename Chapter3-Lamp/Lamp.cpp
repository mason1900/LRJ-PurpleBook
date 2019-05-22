#define maxn 1010
#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>



using namespace std;


int lamp[maxn];

int main()
{
	int n, k;
	memset(lamp, 0, sizeof(lamp));
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= k; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (j % i == 0) lamp[j] = !lamp[j];
		}
	}
	bool first = true;
	for (int k = 1; k <= n; k++)
	{
		if (lamp[k]) 
		{ 
			if (first) first = false;
			else printf(" ");
			printf("%d", k); 
		}
	}


	return 0;
}