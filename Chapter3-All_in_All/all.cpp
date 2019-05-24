#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
using namespace std;

struct Chr
{
	char c;
	bool bUsed;
	Chr(char c='\0', bool bUsed = false) : c(c), bUsed(bUsed){}
};



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
		Chr seqT[maxlen] = {};
		bool isSub = true;
		if (lenS > lenT) { isSub = false; }
		else
		{
			for (int i = 0; i < lenT; i++)
			{
				seqT[i].c = t[i];
			}
			int lastPos = -1;
			for (int i = 0; i < lenS; i++)
			{
				bool found = false;
				for (int j = 0; j < lenT; j++)
				{
					if (seqT[j].c == s[i] && !seqT[j].bUsed && j>lastPos)
					{
						seqT[j].bUsed = true;
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