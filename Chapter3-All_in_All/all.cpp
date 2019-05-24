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
	const int maxlen = 100000;
	char s[maxlen], t[maxlen];
	
	

	while (scanf("%s %s", s, t) == 2)
	{
		int lenS = strlen(s);
		int lenT = strlen(t);
		bool isSub = true;
		if (lenS > lenT) { isSub = false; }
		else
		{
			int lastPos = -1;
			for (int i = 0; i < lenS; i++)
			{
				bool found = false;
				for (int j = 0; j < lenT; j++)
				{
					if (t[j] == s[i] && j>lastPos)
					{
						lastPos = j;
						found = true;
						break;
					}
				}
				if (!found) { isSub = false; break; }
			}

		}
		
		if (isSub) printf("Yes\n");
		else printf("No\n");


	}


	return 0;
}