#include <iostream>
using namespace std;

//ref: https://blog.csdn.net/luomingjun12315/article/details/44940035

int main()
{
	int a, b, c, num[10] = { 0 }, count;
	for (a = 100; a < 333; a++)
	{
		b = 2 * a;
		c = 3 * a;
		num[a / 100] = num[a / 10 %10] = num[a%10] = 1;
		num[b / 100] = num[b / 10 %10] = num[b%10] = 1;
		num[c / 100] = num[c / 10 %10] = num[c%10] = 1;
		count = 0;
		for (int i = 0; i < 10; i++)
		{
			if (num[i]) count += 1;
		}
		if (count == 9)
			cout << a << " " << b << " " << c << "\n";
	}
	return 0;

}