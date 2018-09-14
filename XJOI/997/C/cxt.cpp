#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int n, k, q, lcnt, opt[N], sv[N];
struct P{ int x, y; } p[N], tp[N], A, B, lx[N], ly[N];
inline P operator-(P u, P v) { return (P){u.x - v.x, u.y - v.y}; }
inline int SgnCross(P u, P v) {
	long long tmp = 1ll * u.x * v.y - 1ll * u.y * v.x;
	return tmp < 0 ? -1 : tmp > 0;
}
inline bool CmpY(P u, P v) {
	int d = SgnCross(A, v - u);
	return d ? d > 0 : (u.x < v.x || u.y < v.y);
}
inline bool CmpX(P u, P v) {
	int d = SgnCross(v - u, B);
	return d ? d > 0 : (u.x < v.x || u.y < v.y);
}
pii ip[N];
set<pii> sxy, syx;
struct Seg {
	static const int xb = N - 5;
	int f[N << 1];
	inline void Set(int x, int y) {
		f[xb + x] = y;
		for (int i = (xb + x) >> 1; i; i >>= 1) f[i] = max(f[i << 1], f[i << 1 | 1]);
	}
	inline int Ask(int x, int y) {
		int ans = 0;
		for (int l = xb + x - 1, r = xb + y + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if (~l & 1) ans = max(ans, f[l ^ 1]);
			if ( r & 1) ans = max(ans, f[r ^ 1]);
		}
		return ans;
	}
}Tx, Ty;
int main() {
	scanf("%d%d", &n, &k);
	scanf("%d%d", &A.x, &A.y);
	scanf("%d%d", &B.x, &B.y);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &p[i].x, &p[i].y);
		++lcnt; tp[lcnt] = lx[lcnt] = ly[lcnt] = p[i];
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; ++i) {
		scanf("%d", opt + i);
		if (opt[i] == 1) {
			scanf("%d", sv + i);
		} else {
			sv[i] = ++lcnt;
			scanf("%d%d", &p[lcnt].x, &p[lcnt].y);
			lx[lcnt] = ly[lcnt] = p[lcnt];
		}
	}
	sort(lx + 1, lx + lcnt + 1, CmpX);
	sort(ly + 1, ly + lcnt + 1, CmpY);
	sort(tp + 1, tp + n + 1, CmpX);
	for (int i = 1; i <= n; ++i) {
		int x = lower_bound(lx + 1, lx + lcnt + 1, tp[i], CmpX) - lx;
		int y = lower_bound(ly + 1, ly + lcnt + 1, tp[i], CmpY) - ly;
		int ans = Ty.Ask(1, y - 1) + 1;
		Tx.Set(x, ans); Ty.Set(y, ans);
		sxy.insert(pii(x, y)); syx.insert(pii(y, x));
	}
	for (int i = 1; i <= q; ++i) {
		int x = lower_bound(lx + 1, lx + lcnt + 1, p[sv[i]], CmpX) - lx;
		int y = lower_bound(ly + 1, ly + lcnt + 1, p[sv[i]], CmpY) - ly;
		if (opt[i] == 1) {
			printf("%d\n", Tx.Ask(x, x));
		} else if (opt[i] == 2) { //y
			int tot = 0;
			for (set<pii>::reverse_iterator it = syx.rbegin(); it != syx.rend() && it->first > y; ++it) {
				ip[++tot] = pii(it->second, it->first);
				Tx.Set(ip[tot].first, 0);
			}
			assert(tot <= k);
			ip[++tot] = pii(x, y);
			while (tot) {
				int x = ip[tot].first, y = ip[tot].second;
				int ans = Tx.Ask(1, x - 1) + 1;
				Tx.Set(x, ans); Ty.Set(y, ans);
				--tot;
			}
			sxy.insert(pii(x, y)); syx.insert(pii(y, x));
		} else if (opt[i] == 3) { //x
			int tot = 0;
			for (set<pii>::reverse_iterator it = sxy.rbegin(); it != sxy.rend() && it->first > x; ++it) {
				ip[++tot] = pii(it->first, it->second);
				Ty.Set(ip[tot].second, 0);
			}
			assert(tot <= k);
			ip[++tot] = pii(x, y);
			while (tot) {
				int x = ip[tot].first, y = ip[tot].second;
				int ans = Ty.Ask(1, y - 1) + 1;
				Tx.Set(x, ans); Ty.Set(y, ans);
				--tot;
			}
			sxy.insert(pii(x, y)); syx.insert(pii(y, x));
		} else assert(0);
	}
	return 0;
}
