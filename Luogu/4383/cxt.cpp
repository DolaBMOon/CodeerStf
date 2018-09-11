#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int N = 3e5 + 10;
int n, k;
int tot, fi[N], ne[N << 1], a[N << 1], c[N << 1];
inline void Add(int x, int y, int z) {
	a[++tot] = y; ne[tot] = fi[x]; fi[x] = tot; c[tot] = z;
}
pll f[N][2];
inline int Abs(int x) { return x < 0 ? -x : x; }
inline pll operator+(pll x, pll y) { return pll(x.first + y.first, x.second + y.second); }
inline pll operator-(pll x, pll y) { return pll(x.first - y.first, x.second - y.second); }
inline pll operator+(pll x, int y) { return pll(x.first + y, x.second); }
inline pll Dec(pll x, ll y) { return pll(x.first - y, x.second + 1); }
inline void Dp(int x, int fa, ll co) {
	pll sgm(0, 0), m1(0, 0), m2(0, 0);
	for (int i = fi[x]; i; i = ne[i]) if (a[i] != fa) {
		Dp(a[i], x, co);
		sgm = sgm + f[a[i]][1];
		pll tmp(f[a[i]][0] - f[a[i]][1] + c[i]);
		if (tmp > m1) m2 = m1, m1 = tmp;
		else if (tmp > m2) m2 = tmp;
	}
	f[x][0] = sgm + m1;
	f[x][1] = max(Dec(sgm + m1 + m2, co), sgm);
}
int main() {
	scanf("%d%d", &n, &k); ++k;
	ll sm = 0;
	for (int i = 1, x, y, z; i < n; ++i) {
		scanf("%d%d%d", &x, &y, &z);
		Add(x, y, z); Add(y, x, z);
		sm += Abs(z);
	}
	ll ans = 0;
	for (ll l = -sm, r = sm; l <= r; ) {
		ll mid = (l + r) >> 1;
		Dp(1, 0, mid);
		pll bt = f[1][1];
		if (bt.second <= k) ans = bt.first + k * mid, r = mid - 1; else l = mid + 1;
	}
	printf("%lld\n", ans);
	return 0;
}
