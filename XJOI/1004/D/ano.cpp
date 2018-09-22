#include <bits/stdc++.h>
using namespace std;

int n, val[55], vis[55], pnt;
pair<int, int> e[55];
vector<int> g[55];
char s[55];

void Dfs(int x) {
	pnt += val[x];
	vis[x] = 1;
	for(auto v : g[x])
		Dfs(v);
}

int main(void) {
	scanf("%d", &n);
	for(int i = 1, x; i < n; i++) {
		scanf("%d", &x);
		e[i] = make_pair(x, i);
	}
	scanf("%s", s + 1);
	for(int i = 1; i < n; i++)
		if(s[i] == '1')
			val[e[i].first] ^= 1,
				val[e[i].second] ^= 1;
	scanf("%s", s + 1);
	for(int i = 1; i < n; i++)
		if(s[i] == '1')
			val[e[i].first] ^= 1,
				val[e[i].second] ^= 1;
		else
			g[e[i].first].push_back(e[i].second);

	int ans = 0;
	for(int i = 0; i < n; i++)
		if(!vis[i]) {
			pnt = 0;
			Dfs(i);
			ans += pnt & 1;
		}
	cout << ans / 2;
	return 0;
}
