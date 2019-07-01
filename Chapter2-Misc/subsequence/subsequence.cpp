#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <stdio.h>

int main()
{
	//double a = 1.23456789123;
	//printf("%.5f", a);
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	
	long long n, m;
	double result;

	while (scanf("%lld%lld", &n, &m) == 2)
	{
		if ((n == 0) && (m == 0))
			break;
		result = 0;
		for (long long k = n; k <= m; k++)
		{
			result += 1.0 / (k*k);
		}
		printf("%.5f\n", result);
	}


	return 0;
}