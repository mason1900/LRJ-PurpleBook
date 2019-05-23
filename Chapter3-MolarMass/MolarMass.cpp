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
	double C = 12.01, H=1.008, O=16.00, N=14.01;
	int T = 0;
	scanf("%d", &T);
	while (T)
	{
		T -= 1;
		double mass = 0;
		char s[90] = "\0";
		scanf("%s", s);
		for (int i = 0; i < strlen(s); i++)
		{
			if (isalpha(s[i])) 
			{
				if (isalpha(s[i + 1]) || s[i+1]=='\0')
				{
					if (s[i] == 'C') mass += C;
					else if (s[i] == 'H') mass += H;
					else if (s[i] == 'O') mass += O;
					else if (s[i] == 'N') mass += N;
				}
				else
				{
					int count = atoi((s + i + 1));
					if (s[i] == 'C') mass += C * count;
					else if (s[i] == 'H') mass += H * count;
					else if (s[i] == 'O') mass += O * count;
					else if (s[i] == 'N') mass += N * count;
				}
			}
		}
		printf("%.3f\n", mass);
	}
	
	/*
	char test[100];
	scanf("%s", test);
	printf("%d", atoi(test));
	*/
	return 0;
}