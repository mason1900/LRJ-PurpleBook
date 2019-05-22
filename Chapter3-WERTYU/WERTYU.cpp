#include <cstdio>
#include <cstring>
using namespace std;

char s[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";

int main() 
{
	int i, c;
	while ((c = getchar())!=EOF)
	{
		//for (i = 1; s[i] && s[i] != c; i++);
		char * pch = strchr(s, c);
		//if (s[i]) putchar(s[i - 1]);
		//else putchar(c);
		if (pch != NULL) putchar(*(pch-1));
		else putchar(c);

	}

	return 0;
}