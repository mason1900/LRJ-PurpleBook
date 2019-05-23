#define _CRT_SECURE_NO_WARNINGS
#define LOCAL
#include <cstdio>
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
		int score = 0;
		char c;
		bool flag = true;
		int count = 0;
		while (true)
		{
			c = getchar();
			if (c != '\n' && c != 'r') break;
		}
		while (true)
		{
			if (c == '\n' || c == '\r'|| c==EOF) break;
			if (c == 'O') {
				count += 1;
				score += count;
			}
			else count = 0;
			c = getchar();
		}
		printf("%d\n", score);
	}

	return 0;
}