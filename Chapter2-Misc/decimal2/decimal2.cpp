#define maxn 110

#include <iostream>
using namespace std;

int num[maxn];

int main()
{
	int a, b, c;
	//double result;
	while (cin >> a >> b >> c)
	{
		//incorrect
		/*
		cout.precision(c);
		result = (double)a / b;
		cout << result << "\n";
		*/
		if ((a == 0) && (b == 0) && (c == 0)) break;
		int remain = 0, count = 0, cur=0;
		bool flag = true;
		
		do
		{
			num[cur] = a / b;
			remain = a % b;
			if (flag) flag = false;
			else count += 1;
			a = remain * 10;
			cur += 1;
		} while (count <c);
		if (remain * 10 / b >= 5) num[cur-1] += 1;
		while (cur -1 >0 && num[cur-1] == 10)
		{
			num[cur - 1] = 0;
			num[cur - 2] += 1;
			cur -= 1;
		}
		for (int i = 0; i <= c; i++)
		{
			printf("%d", num[i]);
			if (i == 0) printf(".");
		}

		/*

		do
		{
			cout << (a / b);
			remain = a % b;
			if (flag) cout << ".";
			else count += 1;
			a = remain * 10;
			flag = false;
		} while (count < c - 1);

		*/
		//Note: this solution is INCORRECT as far as now because for precision 3, 0.89999 will become 0.8910
		/*
		if (((a%b) * 10) / b >= 5)
			cout << (a / b) + 1;
		else
			cout << (a / b);
		*/
		cout << "\n";

	}

	return 0;
}