#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), i##_end_ = (b); i < i##_end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

const double pi = acos(-1.);

struct point
{
	LL x, y;
	int id;

	point() { }
	point(const LL &_x, const LL &_y): x(_x), y(_y) { }

	friend point operator+(const point &x, const point &y) { return point(x.x + y.x, x.y + y.y); }
	friend point &operator+=(point &x, const point &y) { x.x += y.x, x.y += y.y; return x; }
	friend point operator-(const point &x, const point &y) { return point(x.x - y.x, x.y - y.y); }
	friend point &operator-=(point &x, const point &y) { x.x -= y.x, x.y -= y.y; return x; }
	friend bool operator<(const point &x, const point &y) { if (x.x == y.x) return x.y < y.y; return x.x < y.x; }
	friend LL operator*(const point &x, const point &y) { return x.x * y.x + x.y * y.y; }
	friend LL operator^(const point &x, const point &y) { return x.x * y.y - x.y * y.x; }

	double angle() { return atan2(y, x); }

};

const int maxn = 110;

int n, m;
point p[maxn + 5];
point poly[maxn + 5];

double ans[maxn + 5];

void convex()
{
	sort(p, p + n);
	if (!n) 
	{
		m = 0;
		return;
	}
	int top = 0;
	poly[top++] = p[0];
	REP(i, 1, n)
	{
		while (top > 1 && ((p[i] - poly[top - 1]) ^ (p[i] - poly[top - 2])) >= 0) --top;
		poly[top++] = p[i];
	}
	int tmp = top;
	for (int i = n - 2; i >= 0; --i)
	{
		while (top > tmp && ((p[i] - poly[top - 1]) ^ (p[i] - poly[top - 2])) >= 0) --top;
		poly[top++] = p[i];
	}
	if (top > 1) --top;
	m = top;
}

int main()
{
#ifdef matthew99
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d", &n);
	REP(i, 0, n) cin >> p[i].x >> p[i].y, p[i].id = i;
	convex();
	REP(i, 0, m)
	{
		point u = poly[(i + m - 1) % m] - poly[i];
		point v = poly[(i + 1) % m] - poly[i];
		double tmp = (u.angle() - v.angle());
		if (tmp < 0) tmp += 2 * pi;
		ans[poly[i].id] = (pi - tmp) / (2 * pi);
	}
	REP(i, 0, n) printf("%.15f\n", ans[i]);
	return 0;
}
