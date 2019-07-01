#include <iostream>

using namespace std;

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
		int remain = 0, count =0;
		bool flag = true;
		do
		{
			cout << (a / b);
			remain = a % b;
			if (flag) cout << ".";
			else count += 1;
			a = remain * 10;
			flag = false;
		} while (count <c-1);
		
		//Note: this solution is INCORRECT as far as now because for precision 3, 0.89999 will become 0.8910
		if (((a%b) * 10) / b >= 5)
			cout << (a / b) + 1;
		else
			cout << (a / b);


		 
		cout << "\n";

	}

	return 0;
}