// ref: https://github.com/sukhoeing/aoapc-bac2nd-keys/blob/master/ch03/UVa1368.cc

#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <cstdio>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct ChCnt
{
	char c;
	int count;
	void set(char c, char count) { this->c = c; this->count = count; }
	ChCnt(char c = 'A', int count = 0): c(c), count(count){};
	bool operator < (const ChCnt& cc2) const
	{
		return count > cc2.count || (count == cc2.count && c < cc2.c);
	}
};


int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	const int maxm = 64;
	const int maxn = 1024;

	char matrix[maxm][maxn] = {"\0"};
	
	int T = 0;
	scanf("%d", &T);
	while (T)
	{
		T -= 1;
		int m = 0, n = 0;
		scanf("%d %d\n", &m, &n);
		
		memset(matrix, '\0', sizeof(matrix));
		for (int i = 0; i < m; i++)
			scanf("%s", matrix[i]);
		
		// e.g. IDX['T'] = 2
		const char* DNA = "ATGC";
		char IDX[256] = "\0";
		for (int i = 0; i < 4; i++) IDX[DNA[i]] = i;

		int dis = 0;
		ChCnt charCount[4];
		for (int y = 0; y < n; y++)
		{
			//clean up for each col
			for (int i = 0; i < 4; i++)
			{
				charCount[i].set(DNA[i], 0);
			}
			//charCount[the id corresponding to letter].count++
			for (int x = 0; x < m; x++)
			{
				charCount[IDX[matrix[x][y]]].count += 1;
			}
			//<algorithm> sort in ascending order
			//overload the < operator
			sort(charCount, charCount + 4);
			printf("%c", charCount[0].c);
			dis += m - charCount[0].count;
		}
		printf("\n%d\n", dis);
	}

	return 0;
}
