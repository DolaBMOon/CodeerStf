#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> bool GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */
const int maxn = 20;
int n, a[maxn + 10], f[1 << maxn], deg[maxn + 10], bc[1 << maxn];
inline int sqr(int x) {
	return x * x;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			char c = getchar();
			while (!isgraph(c)) c = getchar();
			if (i != j) {
				if (c == 'W') ++deg[i];
				else if (c == '?') a[i] |= 1 << j;
			}
		}
	for (int i = 1; i < 1 << n; ++i) {
		bc[i] = bc[i >> 1] + (i & 1); f[i] = -0x3f3f3f3f;
	}
	for (int i = 0; i < (1 << n) - 1; ++i)
		for (int j = 0; j < n; ++j)
			if (!(i >> j & 1)) {
				f[i | (1 << j)] = max(f[i | (1 << j)], f[i] + sqr(deg[j] + bc[a[j] & ~i]));
			}
	printf("%.15lf", (f[(1 << n) - 1] - n * (n - 1) * (n - 1) / 4.0) / (n - 1) / (n - 1) / n);
}
