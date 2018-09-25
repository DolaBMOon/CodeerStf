#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 501010;

int n, K, f[N][3];
vector<int> g[N];

void Dfs(int x, int fa) {
	int els = 0, sum = 0;
	vector<int> tmp;
	for(int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		if(v == fa) continue;
		Dfs(v, x);
		els += max(f[v][0], f[v][2]);
		sum += f[v][0];
		tmp.push_back(max(f[v][1], f[v][2]) - f[v][0]);
	}
	f[x][0] = -1e9, f[x][1] = f[x][2] = els;
	sort(tmp.rbegin(), tmp.rend());
	for(int l = -1; l <= 0; l++) {
		if(tmp.size() < K + l) continue;
		int now = 0;
		for(int i = 0; i < K + l; i++)
			now += tmp[i];
		f[x][l + 1] = max(f[x][l + 1], now + 1 + sum);
	}
	//cerr << x << " " << f[x][0] << " " << f[x][1] << " " << f[x][2] << endl;
}

main(void) {
	scanf("%lld%lld", &n, &K);
	for(int i = 1, u, v; i < n; i++) {
		scanf("%lld%lld", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	Dfs(1, 0);
	cout << f[1][1] << endl;
	return 0;
}
