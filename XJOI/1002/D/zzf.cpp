#include <bits/stdc++.h>
using namespace std;

const int N = 1010;

int fa[N], a[N], f[N], n, vis[N], ans;
vector<int> g[N];

bool Check(int x, int lim) {
	int all = 0;
	for(int i = 0; i < g[x].size(); i++)
		all += a[g[x][i]], vis[g[x][i]] = 0;
	if(lim < all) return 0;

	for(int o = 1; o <= g[x].size(); o++) {
		int id = n;
		for(int i = 0; i < g[x].size(); i++) {
			int v = g[x][i];
			if(vis[v]) continue;
			if(lim - all >= f[v] && a[v] > a[id] || (a[v] == a[id] && f[v] > f[id]))
				id = v;
		}
		if(id == n) return 0;
		all -= a[id];
		vis[id] = 1;
	}
	return 1;
}

void Dfs(int x) {
	if(!g[x].size()) {
		ans = max(ans, a[x]);
		return;
	}
	for(int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		Dfs(v);
		f[x] += a[v];
	}

	int l = 0, r = 1e9, now = 0;
	while(l <= r) {
		int mid = l + r >> 1;
		if(Check(x, mid)) now = mid, r = mid - 1;
		else l = mid + 1;
	}
	ans = max(ans, max(f[x] + a[x], now));
}

int main(void) {
	scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		scanf("%d", &fa[i]);
		g[fa[i]].push_back(i);
	}
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	Dfs(0);
	cout << ans;
	return 0;
}
