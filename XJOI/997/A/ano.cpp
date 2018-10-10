#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

set<int> s[101010], now;

int n, m, Q, L, q[101010];

int main(void) {
	scanf("%d%d%d", &n, &m, &Q);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		s[u].insert(v);
		s[v].insert(u);
	}
	while(Q--) {
		scanf("%d", &L);
		for(int i = 1, x; i <= L; i++)
			scanf("%d", &x), now.insert(x);

		int Ans = 0;
		while(!now.empty()) {
			int x = *now.begin(); Ans++;
			// cerr << x << endl;
			int h = 0, t = 0;
			q[++t] = x;
			now.erase(x);
			while(h < t) {
				int x = q[++h];
				//now.erase(x);
				for(auto u : now) {
					//cerr << x << " " << u << endl;
					if(s[x].find(u) == s[x].end()) {
						q[++t] = u;
						now.erase(u);
					}
				}
			}
		}

		printf("%d\n", Ans);
	}
	return 0;
}
