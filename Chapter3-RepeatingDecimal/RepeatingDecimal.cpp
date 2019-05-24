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
	// NOT a very good solution but AC
	const int maxdigit = 100100;
	int a = 0, b = 0;
	bool firstcase = true;
	while (scanf("%d%d", &a, &b)==2)
	{
		int num[maxdigit];
		int res[maxdigit];
		memset(num, 0, sizeof(num));
		memset(res, 0, sizeof(res));

		int a_ = a;
		int b_ = b;
		int start = 1;
		int end = -1;
		bool found = false;
		for (int i = 0; i <= 100000; i++)
		{
			num[i] = a / b;
			int remain = a % b;
			res[i] = remain;
			for (int j = 1; j < i; j++)
			{
				if (res[j] == remain)
				{
					if (i - j == 1 && num[i] != num[j])
					{
						start = i;
						end = i;
						found = true;
						break;
					}
					else if(num[i] == num[j])
					{
						start = j;
						end = i - 1;
						found = true;
						break;
					}
					else
					{
						start = j + 1;
						end = i;
						found = true;
						break;
					}
				}
			}
			if (found) break;
			a = remain * 10;
		}
		//if (firstcase) firstcase = false;
		//else printf("\n");

		printf("%d/%d = ", a_, b_);
		for (int i = 0; i <= 50; i++)
		{
			bool stop = false;
			if (i == 0)
			{
				printf("%d.", num[0]);
			}
			else if (i== start && start == end)
			{
				printf("(%d)", num[i]);
				stop = true;
			}
			else if (i == start)
			{
				printf("(%d", num[i]);
			}
			else if (i == end)
			{
				printf("%d)", num[i]);
				stop = true;
			}
			else if (i == 50)
			{
				printf("%d...)", num[i]);
			}
			else
			{
				printf("%d", num[i]);
			}

			if (stop) break;
		}
		printf("\n");
		printf("   %d = number of digits in repeating cycle\n\n", end - start + 1);
	}


	return 0;
}