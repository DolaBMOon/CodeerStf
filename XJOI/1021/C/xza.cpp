#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
#define rint register int
#define rep(i,a,b) for (rint i=(a),_E=(b); i<=_E; ++i)
#define per(i,a,b) for (rint i=(a),_E=(b); i>=_E; --i)
#define REP(i,n) for (rint i=0,_E=(n); i<_E; ++i)
#define pb push_back
using namespace std;
typedef vector<int> vi;

/*
	 设查询字符串阀值为T

	 1.若|s|<=T
	 显然只用建出深度<=T的Trie树
	 对于每个节点，维护动态开点线段树，标记永久化以减小常数
	 查询暴力，复杂度O(nTlogn)

	 2.若|s|>T
	 每次重构当前点到根的AC自动机
	 暴力走一遍，最后统计答案
	 复杂度O(n^2/T)

	 取T=sqrt(n/logn)
	 复杂度O(nsqrt(nlogn))
	 常数极小。
 */

inline int read() {
	char ch = getchar(); int x = 0, op = 0;
	while (!isdigit(ch)) op |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch -'0', ch = getchar();
	return op ? -x : x;
}
#define _(x) (x = read())


inline int decode(char ch) {
	if (ch == 'A') return 0;
	if (ch == 'G') return 1;
	if (ch == 'C') return 2;
	if (ch == 'T') return 3;
	return 4;
}

const int N = 200005;
namespace AC {
	int tr[N<<1][5], fail[N<<1], q[N<<1], f[N<<1], g[N<<1], tot, l, r;
	inline void init() {
		memset(tr, 0, (sizeof tr[0][0]) * (tot + 1) * 5);
		tot = 1; l = r = 0;
	}
	inline void add(char s[], int w) {
		rint o = 1, t;
		for (rint i=0; s[i]; ++i) {
			t = decode(s[i]);
			if (!tr[o][t]) tr[o][t] = ++tot, f[tot] = g[tot] = 0;
			o = tr[o][t];
		}
		g[o] += w;
	}
	inline int solve(char s[]) {
		rint u;
		rep (i, 0, 4)
			if (tr[1][i]) fail[q[r++] = tr[1][i]] = 1;
			else tr[1][i] = 1;
		while (l < r) {
			u = q[l++];
			rep (i, 0, 4)
				if (tr[u][i]) fail[q[r++] = tr[u][i]] = tr[fail[u]][i];
				else tr[u][i] = tr[fail[u]][i];
		}
		rint o = 1, t;
		for (rint i=0; s[i]; ++i) {
			t = decode(s[i]);
			o = tr[o][t];
			++f[o];
		}
		per (i, r - 1, 0)
			f[fail[q[i]]] += f[q[i]];
		rint res = 0;
		rep (i, 1, tot) res += f[i] * g[i];
		return res;
	}
}
int w[N], p[N], len[N], tr[N<<1][5], cur[N], rt[N<<1];
int in[N], out[N], fa[N][20], d[N];
int T[N<<5], lc[N<<5], rc[N<<5];
int n, Q, TT, tot, tp, ans, Tc;
int clk, a, b, c, le, cnt = 1;
char s[N<<2], t[N<<1];
vi e[N];

inline void dfs(int u) {
	in[u] = ++clk;
	int sz = e[u].size(), v;
	rep (i, 1, 18) fa[u][i] = fa[fa[u][i-1]][i-1];
	REP (i, sz) if ((v = e[u][i]) != fa[u][0]) {
		d[v] = d[u] + 1; fa[v][0] = u; dfs(v);
	}
	out[u] = clk;
}

inline int lca(int a, int b) {
	if (d[a] < d[b]) swap(a, b);
	rint t = d[a] - d[b];
	rep (i, 0, 18) if (t >> i & 1)
		a = fa[a][i];
	if (a == b) return a;
	per (i, 18, 0)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	return fa[a][0];
}

#define mid ((l + r) >> 1)
inline void upd(int &o, int l, int r, int x, int y, int z) {
	if (!o) o = ++Tc;
	if (l == x && y == r) { T[o] += z; return; }
	if (x <= mid) upd(lc[o], l, mid, x, min(y, mid), z);
	if (mid < y) upd(rc[o], mid + 1, r, max(mid + 1, x), y, z);
}
#undef mid

inline void ins(char s[], int id) {
	rint o = 1, t;
	for (rint i=0; s[i]; ++i) {
		t = decode(s[i]);
		if (!tr[o][t]) tr[o][t] = ++cnt;
		o = tr[o][t];
	}
	cur[id] = o;
	upd(rt[o], 1, n, in[id], out[id], w[id]);
}

inline int qry(int o, int l, int r, int x) {
	rint res = 0, m;
	while (o && l < r) {
		m = (l + r) >> 1; res += T[o];
		if (x <= m) o = lc[o], r = m;
		else o = rc[o], l = m + 1;
	}
	res += T[o];
	return res;
}

inline int ask(char s[], int tim) {
	if (!tim) return 0;
	rint res = 0, o, t;
	rep (i, 0, le - 1) {
		o = 1;
		rep (j, i, le - 1) if (o) {
			t = decode(s[j]);
			if (tr[o][t]) {
				o = tr[o][t];
				res += qry(rt[o], 1, n, tim);
			}
			else o = 0;
		}
	}
	return res;
}

int main() {
	_(n), _(tp);
	TT = 300;
	rep (i, 1, n) {
		p[i] = ++tot;
		scanf("%s", s + p[i]);
		len[i] = strlen(s + p[i]);
		tot += len[i];
	}
	rep (i, 1, n) _(w[i]);
	rep (i, 1, n - 1) _(a), _(b), e[a].pb(b), e[b].pb(a);
	d[1] = 1; dfs(1);
	rep (i, 1, n)
		if (len[i] <= TT) ins(s + p[i], i);
	_(Q);
	while (Q--)
		if (read() == 1) {
			_(a), _(b);
			if (tp) a ^= ans, b ^= ans;
			c = lca(a, b);
			if (d[a] > d[b]) swap(a, b);
			scanf("%s", t);
			le = strlen(t);
			ans = 0;
			if (le <= TT) {
				if (a == c) ans = ask(t, in[b]) - ask(t, in[fa[c][0]]);
				else {
					ans = ask(t, in[a]) + ask(t, in[b])
						- ask(t, in[fa[c][0]]) - ask(t, in[c]);
				}
			}
			else {
				AC::init();
				while (a != b) {
					if (d[a] < d[b]) swap(a, b);
					AC::add(s + p[a], w[a]);
					a = fa[a][0];
				}
				AC::add(s + p[a], w[a]);
				ans = AC::solve(t);
			}
			printf("%d\n", ans);
		}
		else {
			_(a), _(b);
			if (tp) a ^= ans, b ^= ans;
			upd(rt[cur[a]], 1, n, in[a], out[a], b - w[a]);
			w[a] = b;
		}
	return 0;
}
