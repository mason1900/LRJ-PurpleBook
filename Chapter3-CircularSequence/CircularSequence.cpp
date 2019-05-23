#define _CRT_SECURE_NO_WARNINGS
#define maxn 105

#include <cstdio>
#include <cstring>
using namespace std;

bool less(char *s, int p, int q)
{
	int n = strlen(s);
	for (int i = 0; i < n; i++)
	{
		if (s[(i + p) % n] != s[(i + q) % n])
			return s[(i + p) % n] < s[(i + q) % n];
	}
	return false;
}

int main()
{
	int T;
	char s[maxn];
	scanf("%d", &T);
	while (T > 0)
	{
		T -= 1;
		scanf("%s", s);
		int ans = 0, n=strlen(s);
		for (int i = 0; i < n; i++)
		{
			if (less(s, i, ans)) ans = i;
		}
		for (int j = 0; j < n; j++)
		{
			putchar(s[(j+ans)%n]);
		}
		putchar('\n');
	}

	return 0;
}