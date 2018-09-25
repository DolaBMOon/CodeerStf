#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#define MEM(a) memset(a,0,sizeof(a))
using namespace std;
typedef long long LL;
const int INF = 999999999;
const int N = 400040;
const double eps = 1e-8;

int G()
{
	int k = 1, tmp = 0;
	char ch = getchar();
	for (; ch > '9' || ch < '0'&&ch != '-'; ch = getchar());
	if (ch == '-') k = -1, ch = getchar();
	for (; '0' <= ch && ch <= '9'; ch = getchar()) tmp = tmp * 10 + int(ch) - 48;
	return tmp*k;
}

int zero(double a)
{
	if (fabs(a) < eps) return 0;
	else return (a>0) ? 1 : -1;
}

struct point
{
	double x, y;
	point(){}
	point(double a, double b){ x = a; y = b; }
	friend point operator+(const point&a, const point&b){ return point(a.x + b.x, a.y + b.y); }
	friend point operator -(const point&a, const point&b){ return point(a.x - b.x, a.y - b.y); }
	friend point operator *(const double&k, const point&a){ return point(k*a.x, k*a.y); }//数乘
	friend point operator /(const point&a, const double&b){ return point(a.x / b, a.y / b); }
	friend double operator *(const point&a, const point&b){ return a.x*b.x + a.y*b.y; }//点积
	friend double operator /(const point&a, const point&b){ return a.x*b.y - a.y*b.x; }//叉积,用^优先级有问题
	friend bool operator <(const point&a, const point&b){ return (a.x - b.x < -eps) || (fabs(a.x - b.x) < eps && (a.y - b.y) < -eps); }
	friend bool operator ==(const point&a, const point&b){ return zero(a.x - b.x) && zero(a.y - b.y); }
	double dis(){ return (sqrt(x*x + y*y)); }
	void input(){ /*scanf("%lf%lf",&x,&y)*/x = G(), y = G(); }
	void output(){ printf("%lf %lf\n", x, y); }
}p[N];

struct angle
{
	double poi, cro;
	bool operator ==(angle a){ return (zero(poi - a.poi) == 0 && zero(cro - a.cro) == 0); }
}s[N];
int f[N];
void work()
{
	MEM(f); MEM(s);
	int i, j, n, id, maxn, nn, ans = 0;
	scanf("%d", &n); nn = 4 * n - 1;
	for (i = 1; i <= n; ++i) p[i].input();
	p[0] = p[n], p[n + 1] = p[1], s[0].cro = s[0].poi = INF;
	for (i = 1; i <= n; ++i)
	{
		s[2 * i - 1].poi = (p[i - 1] - p[i]) * (p[i + 1] - p[i]);
		s[2 * i - 1].cro = (p[i - 1] - p[i]) / (p[i + 1] - p[i]);
		s[2 * i - 1 + n * 2] = s[2 * i - 1];
	}
	for (f[1] = id = maxn = i = 1; i <= nn; ++i)
	{
		if (maxn > i) f[i] = min(f[2 * id - i], maxn - i);
		else f[i] = 1;
		for (; s[i + f[i]] == s[i - f[i]]; ++f[i]);
		if (f[i] + i>maxn) maxn = f[i] + i, id = i;
	}
	for (i = n + 1; i <= 3 * n; ++i) if (f[i] >= n - (!(n & 1))) ++ans;
	printf("%d\n", ans / 2);
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--) work();
	return 0;
}
