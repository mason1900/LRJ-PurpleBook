#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <functional>
#include <algorithm>
using namespace std;


int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	
	const int maxn = 256;

	while (true)
	{
		char input[maxn];
		char result[maxn];
		int stat_i[maxn];
		int stat_r[maxn];
		memset(stat_i, 0, sizeof(stat_i));
		memset(stat_r, 0, sizeof(stat_r));
		
		if (scanf("%s", input) != 1) return 0;
		scanf("%s", result);

		for (int i = 0; input[i] && result[i]; i++)
		{
			stat_i[input[i] - 'A'] += 1;
			stat_r[result[i] - 'A'] += 1;
		}
		sort(stat_i, stat_i + maxn, greater<int>());
		sort(stat_r, stat_r + maxn, greater<int>());
		
		bool same = true;
		for (int i = 0; stat_i[i] && stat_r[i]; i++)
		{
			if (stat_i[i] != stat_r[i]) same = false;
		}

		printf("%s", same ? "YES\n" : "NO\n");

	}

	return 0;
}