#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
int n, m, k, px[N], py[N], tp_id_to_x[N], tp_x_to_id[N];
int va1[N], va2[N];
struct Graph {
	vector<int> fr[N], ou[N];
	int rd[N], f[N];
	queue<int> q;

	inline void Add(int x, int y) {
		fr[y].push_back(x);
		ou[x].push_back(y);
	}
	inline void Solve() {
		for (int i = 1; i <= n; ++i) if ((rd[i] = fr[i].size()) == 0) q.push(i);
		int tot = 0;
		while (!q.empty()) {
			int u = q.front(); q.pop();
			++tot;
			tp_id_to_x[tot] = u;
			tp_x_to_id[u] = tot;
			f[u] = 0;
			for (int i = 0; i < (int)fr[u].size(); ++i)
				f[u] = max(f[u], f[fr[u][i]] + 1);
			for (int i = 0; i < (int)ou[u].size(); ++i)
				if (--rd[ou[u][i]] == 0) q.push(ou[u][i]);
		}
	}
}g, gi;
namespace Seg {
	const int xb = N - 5;
	int f[N << 1];
	inline void SetMax(int l, int r, int z) {
		for (l = xb + l - 1, r = xb + r + 1; l ^ r ^ 1; l >>= 1, r >>= 1) {
			if (~l & 1) f[l ^ 1] = max(f[l ^ 1], z);
			if ( r & 1) f[r ^ 1] = max(f[r ^ 1], z);
		}
	}
	inline int Ask(int x) {
		int ans = 0;
		for (int i = xb + x; i; i >>= 1) ans = max(ans, f[i]);
		return ans;
	}
}
int main() {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", px + i, py + i);
		g.Add(px[i], py[i]);
		gi.Add(py[i], px[i]);
	}
	gi.Solve();
	g.Solve();
	for (int i = 1; i <= m; ++i)
		Seg::SetMax(tp_x_to_id[px[i]] + 1, tp_x_to_id[py[i]] - 1, g.f[px[i]] + gi.f[py[i]] + 1);
	for (int i = 1; i <= n; ++i) va1[i] = max(va1[i - 1], g.f[tp_id_to_x[i]]);
	for (int i = n; i; --i) va2[i] = max(va2[i + 1], gi.f[tp_id_to_x[i]]);
	for (int i = 1, opt, x; i <= k; ++i) {
		scanf("%d%d", &opt, &x);
		if (opt == 1) {
			int no = tp_x_to_id[x];
			printf("%d\n", max(Seg::Ask(no), max(va1[no - 1], va2[no + 1])));
		} else if (opt == 2) {
			printf("%d\n", g.f[x] + gi.f[x]);
		} else if (opt == 3) {
			printf("%d\n", g.f[px[x]] + gi.f[py[x]] + 1);
		}
	}
	return 0;
}
