#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <functional>
#include <algorithm>
using namespace std;

void guess(char c, int& left, int& chance, bool& win, bool& lose, char* s1)
{
	bool bad = true;
	for (int i = 0; i < (int)strlen(s1); i++)
	{
		if (s1[i] == c)
		{
			left -= 1;
			s1[i] = ' ';
			bad = false;
		}
	}
	if (bad) chance -= 1;
	if (chance <= 0) lose = true;
	if (left <= 0) win = true;

}

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	const int maxn = 100;
	int rnd = 0;
	char s1[maxn];
	char s2[maxn];


	while (scanf("%d%s%s", &rnd, s1, s2) == 3 && rnd != -1)
	{
		
		int left = strlen(s1);
		int chance = 7;
		bool win = false, lose = false;
		for (int i = 0; i < (int)strlen(s2); i++)
		{
			guess(s2[i], left, chance, win, lose, s1);
			if (win || lose) break;
		}
		printf("Round %d\n", rnd);
		if (win)printf("You win.\n");
		else if (lose) printf("You lose.\n");
		else printf("You chickened out.\n");

	}

	return 0;
}