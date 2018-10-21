#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>
#define prev _________
using namespace std;

const int maxm = 18, maxn = 1e5, clen = 6;
int n, m, dist[1 << maxm], prev[1 << maxm], a[maxn];
vector< tuple<int, int, int> > ans;

void Init(void) {
	queue<int> q;
	memset(dist, -1, sizeof dist);
	dist[0] = 0;
	q.push(0);
	while (!q.empty()) {
		int s = q.front(); q.pop();
		// for (int i = 0; i < m; ++i) putchar((s >> i & 1) + '0');
		// printf(" %d\n", dist[s]);
		for (int i = 0; i < m; ++i) {
			for (int d = 1; i + d * 2 < m; ++d) {
				int t = s ^ 1 << i ^ 1 << i + d ^ 1 << i + d * 2;
				if (dist[t] == -1) {
					dist[t] = dist[s] + 1;
					prev[t] = s;
					q.push(t);
				}
			}
		}
	}
}

void Make(int i, int j, int k) {
	ans.push_back({i, j, k});
	a[i] ^= 1;
	a[j] ^= 1;
	a[k] ^= 1;
}

void Solve2(int l, int r) {
	if (l == r) return;
	int left = l, right = n - r;
	int offset = 0;
	if (left >= clen && right >= clen) {
		offset = l - clen;
	} else if (right < clen) {
		offset = max(0, n - maxm);
	}
	m = min(n - offset, maxm);
	Init();

	int s = 0;
	for (int i = 0; i < m; ++i) {
		s |= a[offset + i] << i;
	}
	if (dist[s] == -1) {
		puts("NO");
		exit(0);
	}
	while (s) {
		int t = prev[s];
		vector<int> op;
		for (int i = 0; i < m; ++i) {
			if ((s >> i & 1) != (t >> i & 1)) {
				op.push_back(offset + i);
			}
		}
		s = t;
		Make(op[0], op[1], op[2]);
	}
}

void Solve(int l, int r) {
	while (true) {
		while (l < r && a[l] == 0) ++l;
		while (l < r && a[r - 1] == 0) --r;
		if (r - l < 7) {
			Solve2(l, r);
			return;
		}
		int x2 = a[l + 1], x3 = a[l + 2];
		int y2 = a[r - 2], y3 = a[r - 3];
		if (x2 == 0) {
			if (x3 == 0) {
				Make(l, l + 3, l + 6);
			} else {
				Make(l, l + 2, l + 4);
			}
		} else if (y2 == 0) {
			if (y3 == 0) {
				Make(r - 1, r - 1 - 3, r - 1 - 6);
			} else {
				Make(r - 1, r - 1 - 2, r - 1 - 4);
			}
		} else if (x3 == 1) {
			Make(l, l + 1, l + 2);
		} else if (y3 == 1) {
			Make(r - 1, r - 2, r - 3);
		} else {
			if (~(r - 1 - l) & 1) {
				int mid = l + r - 1 >> 1;
				Make(l, mid, r - 1);
				Make(l + 1, mid, r - 2);
			} else {
				int mid = l + r - 2 >> 1;
				Make(l, mid, r - 2);
				Make(l + 1, mid + 1, r - 1);
			}
		}
	}
}

int main(void) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	Solve(0, n);
	puts("YES");
	printf("%d\n", (int)ans.size());
	for (auto p : ans) {
		int a, b, c;
		tie(a, b, c) = p;
		printf("%d %d %d\n", a + 1, b + 1, c + 1);
	}
	return 0;
}
