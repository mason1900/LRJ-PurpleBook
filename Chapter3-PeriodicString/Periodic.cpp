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
		char s[100];
		scanf("%s", s);
		int result = 0;
		for (int i = 1; i < (int)strlen(s); i++)
		{
			bool equal = true;
			if (s[i] == s[0])
			{
				int  j = i;
				int  start = 0;
				while (j< (int)strlen(s))
				{
					if (j - start == 1)
					{
						if (s[j] != s[start]) equal = false;
					}
					for (int k = 1; k < j - start; k++)
					{
						if ((j+k) >= (int)strlen(s)) equal = false;
						else if (s[start + k] != s[j + k]) equal = false;
					}
					if (equal)
					{
						start = j;
						j = j + i;
					}
					else break;
				}
				if (equal) {
					result = i;
					printf("%d\n", i);
					break;
				}
			}

		}

		if (result == 0) printf("%d\n", strlen(s));
		if (T) printf("\n");
	}

	return 0;
}