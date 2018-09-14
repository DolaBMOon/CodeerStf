%:pragma GCC optimize(3)
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

const int N = 1e5 + 50;

int id[N], le[N], ri[N], he;
set <int> e[N];

inline void Del(int x) {
	le[ri[x]] = le[x];
	ri[le[x]] = ri[x];
	if (x == he) he = ri[x];
}

inline void Solve() {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &id[i]);
		le[i] = i - 1; ri[i] = i + 1;
	}
	he = 1;
	le[n + 1] = ri[n + 1] = 0;
	queue <int> Q;
	int cnt = 0;
	while (he <= n) {
		cnt ++;
		Q.push(id[he]);
		Del(he);
		while (Q.size()) {
			int x = Q.front(); Q.pop();
			for (int i = he; i <= n; i = ri[i])
				if (!e[x].count(id[i])) {
					Del(i); Q.push(id[i]);
				}
		}
	}
	printf("%d\n", cnt);
}

int main() {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1, x, y; i <= m; i ++) {
		scanf("%d%d", &x, &y);
		e[x].insert(y); e[y].insert(x);
	}
	while (q --) Solve();
	return 0;
}
