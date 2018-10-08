//#pragma GCC optimize("Ofast")
//#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define rep(i,a,b) for (register int i=(a),_E=(b); i<=_E; i++)
#define per(i,a,b) for (register int i=(a),_E=(b); i>=_E; i--)
#define REP(i,n) for (register int i=(0),_E=(n); i<n; i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

inline int read() {
	char ch = getchar(); int x = 0, op = 1;
	while (ch < '0' || '9' < ch) { if (ch == '-') op = -1; ch = getchar(); }
	while ('0' <= ch && ch <= '9') { x = x * 10 + ch -'0'; ch = getchar(); }
	return op * x;
}

const int maxn = 515, maxm = 10005;
int pr[maxm], flag[maxm], n, N = 1, cnt;
vi p[maxn]; ll ans;

void init() {
	rep (i, 2, maxm - 1) {
		if (!flag[i]) pr[++cnt] = i;
		for (int j=1; j<=cnt&&i*pr[j]<maxm; j++) {
			flag[i*pr[j]] = 1;
			if (i % pr[j] == 0) break;
		}
	}
}

void solve(int l, int r, int s, int base) {
	if (r - l <= 1) return;
	int mid = (l + r) >> 1, a, b;
	if (s) {
		a = mid + 2, b = mid - 1;
		if (a <= r && b >= l) {
			for (int i=a; i<=r; i+=2) p[i].pb(base);
			for (int i=b; i>=l; i-=2) p[i].pb(base);
		}
		a = mid + 3, b = mid;
		if (a <= r && b >= l) {
			for (int i=a; i<=r; i+=2) p[i].pb(base + 1);
			for (int i=b; i>=l; i-=2) p[i].pb(base + 1);
		}
		a = mid - 2;
		if (a >= l) {
			for (int i=a; i>=l; i-=2) p[i].pb(base + 2);
			p[mid+1].pb(base + 2);
		}
	}
	else {
		a = mid + 2, b = mid - 1;
		if (a <= r && b >= l) {
			for (int i=a; i<=r; i+=2) p[i].pb(base + 1);
			for (int i=b; i>=l; i-=2) p[i].pb(base + 1);
		}
		a = mid - 2; b = mid + 1;
		if (l <= a && b <= r) {
			for (int i=a; i>=l; i-=2) p[i].pb(base);
			for (int i=b; i<=r; i+=2) p[i].pb(base);
		}
		a = mid + 3;
		if (a <= r) {
			for (int i=a; i<=r; i+=2) p[i].pb(base + 2);
			p[mid].pb(base + 2);
		}
	}
	solve(l, mid, 0, base + 3);
	solve(mid + 1, r, 1, base + 3);
}

int main() {
	cin >> n; init();
	rep (i, 1, n)
		if (i & 1) p[i].pb(1);
		else p[i].pb(2);
	while (N < n) N *= 2;
	solve(1, N, 0, 3);
	rep (i, 1, n) {
		ans = 1;
		REP (j, p[i].size())
			ans = 1ll * ans * pr[p[i][j]];
		printf("%lld ", ans);
	}
	return 0;
}
