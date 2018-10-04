#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const double eps = 1e-6;

int fcmp(double x, double y) {
	return fabs(x - y) < eps ? 0 : (x > y ? 1 : -1);
}

double Sqr(double x) {
	return x * x;
}

struct Point {
	double x, y;
	void Read(void) {
		scanf("%lf%lf", &x, &y);
	}
	double Dist(const Point &rhs) const {
		return Sqr(x - rhs.x) + Sqr(y - rhs.y);
	}
}S, T;

struct Circle {
	Point p;
	double r;
	void Read(void) {
		p.Read();
		scanf("%lf", &r);
	}
}Cx, Cy;

bool operator < (const Point &a, const Point &b) {
	return !fcmp(a.x, b.x) ? a.y < b.y : a.x < b.x;
}

set<Point> st;
queue<Point> q;

bool In(Point x, Circle C) {
	return fcmp(x.Dist(C.p), Sqr(C.r)) <= 0;
}

Point Move(Point x, Point y, double d1, double d2) {
	return (Point){x.x + (y.x - x.x) * d1 / d2,
		x.y + (y.y - x.y) * d1 / d2};
}

void Insert(Point x) {
	if(!st.count(x))
		st.insert(x), q.push(x);
}

bool Check(Point x, double d, Circle C) {
	double dis = x.Dist(C.p);
	if(dis < eps) return d <= C.r;
	if(In(x, C)) {
		if(!fcmp(dis, Sqr(C.r)) && (d > C.r && !fcmp(dis, Sqr(d - C.r))))
			return Insert(Move(x, C.p, d, d - C.r)), 0;
		return !(d > C.r && !~fcmp(dis, Sqr(d - C.r)));
	}
	int eqx, eqy;
	if(!(eqx = fcmp(dis, Sqr(d + C.r))))
		return Insert(Move(x, C.p, d, d + C.r)), 0;
	if(!(eqy = fcmp(dis, Sqr(d - C.r))))
		return Insert(Move(x, C.p, d, d - C.r)), 0;
	return !~eqx && ~eqy;
}

bool Infinity(double d, Point y) {
	st.clear();
	while(!q.empty()) q.pop();
	q.push(y);
	st.insert(y);
	while(!q.empty()) {
		Point x = q.front(); q.pop();
		if(Check(x, d, Cx)) return 1;
		if(Check(x, d, Cy)) return 1;
	}
	return 0;
}

bool Solve(double d) {
	if(Sqr(Cx.p.x - Cy.p.x) + Sqr(Cx.p.y - Cy.p.y) > Sqr(Cx.r + Cy.r + d) && In(S, Cx) == In(T, Cy)) return 0;
	if(Infinity(d, S)) return Infinity(d, T);
	return st.find(T) != st.end();
}

int Q;

int main(void) {
	scanf("%*d%d", &Q);
	int Ans = 0, coe = 1;
	while(Q--) {
		double d;
		Cx.Read(), Cy.Read(), S.Read(), T.Read();
		scanf("%lf", &d);
		int t = Solve(d);
		Ans = (Ans + coe * t) % MOD;
		coe = (coe * 2) % MOD;
	}
	cout << Ans << endl;
	return 0;
}
