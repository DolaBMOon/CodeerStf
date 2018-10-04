#include<bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
#define x first
#define y second
const double eps = 1e-6;
int Case, d;
struct P{ int x, y; }s, t;
struct Cir{ int x, y, r; }c1, c2;
template<typename T> inline T Sqr(T x) { return x * x; }
inline bool In(P u, Cir c) { return Sqr(c.x - u.x) + Sqr(c.y - u.y) <= Sqr(c.r); }
inline bool Equ(double x, double y) { return abs(x - y) < eps; }
inline bool operator<(pdd u, pdd v) { return Equ(u.x, v.x) ? u.y < v.y - eps : u.x < v.x; }
set<pdd> st;
queue<pdd> q;
inline bool GetCross(pdd u, int d, Cir c) {//1 if the the cross is a arc; else push the node into the set and the queue
	if (Equ(u.x, c.x) && Equ(u.y, c.y)) return d <= c.r;
	double dis_2 = Sqr(u.x - c.x) + Sqr(u.y - c.y);
	if (Equ(dis_2, Sqr(d + c.r))) {
		double nx = u.x + (c.x - u.x) * d / double(d + c.r);
		double ny = u.y + (c.y - u.y) * d / double(d + c.r);
		if (!st.count(pdd(nx, ny))) {
			q.push(pdd(nx, ny));
			st.insert(pdd(nx, ny));
		}
		return 0;
	} else if (Equ(dis_2, Sqr(d - c.r))) {
		if (d <= c.r) return 1;
		double nx = u.x + (c.x - u.x) * d / double(d - c.r);
		double ny = u.y + (c.y - u.y) * d / double(d - c.r);
		if (!st.count(pdd(nx, ny))) {
			q.push(pdd(nx, ny));
			st.insert(pdd(nx, ny));
		}
		return 0;
	} else if (dis_2 > Sqr(d + c.r)) {
		return 0;
	} else if (dis_2 > Sqr(d - c.r)) {
		return 1;
	} else if (dis_2 < Sqr(d - c.r)) {
		return d <= c.r;
	} else assert(0);
}
inline bool GetSet(P u) {//0 if the set is st. 1 if the set is big set.
	while (!q.empty()) q.pop();
	st.clear();
	st.insert(pdd(u.x, u.y));
	q.push(pdd(u.x, u.y));
	while (!q.empty()) {
		pdd u = q.front(); q.pop();
		if (GetCross(u, d, c1)) return 1;
		if (GetCross(u, d, c2)) return 1;
	}
	return 0;
}
int ans = 0;
inline void AddAns(int x) {
	static const int p = 998244353;
	static int qu = 1;
	ans = (ans + 1ll * qu * x) % p;
	qu = qu * 2 % p;
}
inline void CheckIfIsInSameSet() {//make there is only one small set.
	if (!GetSet(s)) AddAns(st.count(pdd(t.x, t.y)) ? 1 : 0);
	else AddAns(GetSet(t) ? 1 : 0);
}
int main() {
	scanf("%*d%d", &Case);
	while (Case--) {
		scanf("%d%d%d%d%d%d", &c1.x, &c1.y, &c1.r, &c2.x, &c2.y, &c2.r);
		scanf("%d%d%d%d", &s.x, &s.y, &t.x, &t.y);
		scanf("%d", &d);
		// assert(d > 0 && c1.r > 0 && c2.r > 0);
		if (Sqr(c1.x - c2.x) + Sqr(c1.y - c2.y) > Sqr(c1.r + c2.r + d) && In(s, c1) != In(t, c1)) AddAns(0);
		else CheckIfIsInSameSet();
	}
	printf("%d\n", ans);
	return 0;
}
