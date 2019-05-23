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
		int len = strlen(s);
		for (int i = 1; i < len + 1; i++)
		{
			bool flag = true;
			for (int j = 0; j < len; j++)
			{
				if (s[j] != s[(j+i) % len]) flag = false;
			}
			if (flag)
			{
				printf("%d\n", i);
				break;
			}
		}
		if (T) printf("\n");
	}

	return 0;
}