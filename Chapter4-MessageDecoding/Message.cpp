#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <cstdio>
#include <cstring>
#include <cstdlib>

using namespace std;

int code[8][1 << 8];

int readchar();
int readint(int c);
bool readcodes();
void printcodes();

int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL

	while (readcodes())
	{
		//printcodes();
		while (true)
		{
			int len = readint(3);
			if (len == 0) break;
			while (true)
			{
				int v = readint(len);
				if (v == (1 << len) - 1) break;
				putchar(code[len][v]);
			}
		}
		putchar('\n');
	}
	
	return 0;
}

int readchar()
{
	while (true)
	{
		int ch = getchar();
		if (ch != '\n' && ch != '\r') return ch;
	}
}


int readint(int c)
{
	int v = 0;
	while (c)
	{
		v = v * 2 + readchar() - '0';
		c-=1;
	}
	return v;
}

bool readcodes()
{
	memset(code, 0, sizeof(code));
	code[1][0] = readchar();
	for (int len = 2; len <= 7; len++)
	{
		for (int i = 0; i < (1 << len) - 1; i++)
		{
			int ch = getchar();
			if (ch == EOF) return false;
			if (ch == '\n' || ch == '\r') return true;
			code[len][i] = ch;
		}
	}
	return true;

}

void printcodes()
{
	for (int len = 1; len <= 7; len++)
	{
		for (int i = 0; i < (1 << len) - 1; i++)
		{
			if (code[len][i] == 0) return;
			printf("code[%d][%d] = %c\n", len, i, code[len][i]);
		}
	}
}