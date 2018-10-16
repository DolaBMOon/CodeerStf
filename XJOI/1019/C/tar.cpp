#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#define fo(i, x, y) for(int i = x; i <= y; i ++)
#define mem(a) memset(a, 0, sizeof a)
#define min(a, b) ((a) < (b) ? (a) : (b))
#define fd(i, x, y) for(int i = x; i >= y; i --)
using namespace std;

const int N = 4e5 + 5;

int T, n, m, Q, x, y, td;
int dfn[N], low[N], d[N], z[N], tt, z0;

struct edge {
	int final[N], to[N], next[N], tot;
	void link(int x, int y) {
		cout<<x<<","<<y<<endl;
		next[++ tot] = final[x], to[tot] = y, final[x] = tot;
		next[++ tot] = final[y], to[tot] = x, final[y] = tot;
	}
	void cl() {
		mem(final); mem(next); tot = 1;
	}
} e, e2;

void tar(int x, int la) {
	dfn[x] = low[x] = ++ tt;
	z[++ z[0]] = x;
	for(int i = e.final[x]; i; i = e.next[i]) {
		int y = e.to[i];
		if(!dfn[y]) {
			tar(y, i);
			low[x] = min(low[x], low[y]);
			if(low[y] >= dfn[x]) {
				td ++;
				while(z[z[0]] != y) e2.link(z[z[0] --], td);
				e2.link(z[z[0] --], td); e2.link(x, td);
				cout<<z[z[0]]<<")"<<endl;
			}
		} else if(i != (la ^ 1)) low[x] = min(low[x], dfn[y]);
	}
}

int bz[N], fa[18][N], dep[N], s[N], p[N], q[N], tp;

void dfs(int x) {
	bz[x] = 1;
	s[x] += (x <= n);
	p[x] = ++ tp;
	for(int i = e2.final[x]; i; i = e2.next[i]) {
		int y = e2.to[i]; if(bz[y]) continue;
		fa[0][y] = x; dep[y] = dep[x] + 1; s[y] = s[x];
		dfs(y);
	}
	q[x] = tp;
	bz[x] = 0;
}

int lca(int x, int y) {
	if(dep[x] < dep[y]) swap(x, y);
	fd(i, 17, 0) if(dep[fa[i][x]] >= dep[y]) x = fa[i][x];
	if(x == y) return x;
	fd(i, 17, 0) if(fa[i][x] != fa[i][y]) x = fa[i][x], y = fa[i][y];
	return fa[0][x];
}

int cmp(int x, int y) {
	return p[x] < p[y];
}

int ff[N];

int main() {
	//freopen("game.in", "r", stdin);
	//freopen("game.out", "w", stdout);
	//for(scanf("%d", &T); T; T --) {
		e.cl(); e2.cl();
		scanf("%d %d", &n, &m);
		fo(i, 1, m) {
			scanf("%d %d", &x, &y);
			e.link(x, y);
		}
		mem(dfn);
		cout<<"!!!!!!"<<endl;
		td = n; tt = 0; tar(1, 0);
		cout<<td<<"!!"<<endl;
		//dep[1] = 1; s[1] = 0; tp = 0;
		//mem(bz); dfs(1);
		//fo(i, 1, 17) fo(j, 1, td) fa[i][j] = fa[i - 1][fa[i - 1][j]];
		//for(scanf("%d", &Q); Q; Q --) {
		//	int k; scanf("%d", &k);
		//	fo(i, 1, k) scanf("%d", &d[i]), bz[d[i]] = Q;
		//	sort(d + 1, d + k + 1, cmp);
		//	int d0 = k;
		//	fo(i, 2, k) d[++ d0] = lca(d[i - 1], d[i]);
		//	sort(d + 1, d + d0 + 1, cmp);
		//	k = 0; fo(i, 1, d0) if(i == 1 || d[i] != d[i - 1]) d[++ k] = d[i];
		//	z0 = 0;
		//	fo(i, 1, k) {
		//		int x = d[i];
		//		if(x == 1) {z[++ z0] = 1; continue;}
		//		while(z0 && (p[x] < p[z[z0]] || p[x] > q[z[z0]]))
		//			ff[z[z0]] = z[z0 - 1], z0 --;
		//		z[++ z0] = x;
		//	}
		//	while(z0) ff[z[z0]] = z[z0 - 1], z0 --;
		//	int ans = 0;
		//	fo(i, 1, k) {
		//		int x = d[i];
		//		if(i == 1) {ans += (bz[x] != Q && x <= n); continue;}
		//		ans += s[x] - s[ff[x]] - (bz[x] == Q && x <= n);
		//	}
		//	printf("%d\n", ans);
		//}
	//}
}
