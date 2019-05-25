#define _CRT_SECURE_NO_WARNINGS
#define LOCAL

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;


struct Pallet
{
	int w;
	int h;
	void set(int _w = 0, int _h = 0)
	{
		if (_w < _h)
		{
			w = _h;
			h = _w;
		}
		else
		{
			w = _w;
			h = _h;
		}
	}
	bool operator != (const Pallet& rhs) const
	{
		return w != rhs.w || h != rhs.h;
	}
	bool operator < (const Pallet& rhs) const
	{
		// descending order
		return w > rhs.w || (w == rhs.w && h > rhs.h);
	}
};


// Note: for a>b>c sorted edge length must be: 
// ab ab ac ac bc bc
// ref: http://acm.zzkun.com/archives/122
bool check(Pallet *p)
{
	if ((p[0] != p[1]) || (p[2] != p[3]) || (p[4] != p[5]))
		return false;
	if ((p[0].w != p[2].w) || (p[0].h != p[4].w) || (p[2].h != p[4].h)) 
		return false;
	return true;
}


int main()
{
#ifdef LOCAL
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif // LOCAL
	const int maxn = 6;
	Pallet p[maxn];
	while (true)
	{
		for (int i = 0; i < maxn; i++)
		{
			int a, b;
			if (scanf("%d%d", &a, &b) != 2) return 0;
			p[i].set(a, b);
		}
		sort(p, p + 6);
		printf("%s\n", check(p) ? "POSSIBLE" : "IMPOSSIBLE");
	}

	return 0;
}