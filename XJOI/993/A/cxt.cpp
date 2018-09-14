%:pragma GCC optimize(2)

#include<bits/stdc++.h>

using namespace std;

const int N = 105;

int n, m, k, tot;

struct Node {
	int x, y, v;
	int rd;
}a[N];

inline bool NodeCmp(Node u, Node v) {
	return u.v == v.v ? u.rd > v.rd : u.v > v.v;
}

inline int Dis(Node u, Node v) {
	return abs(u.x - v.x) + abs(u.y - v.y);
}

inline bool Rnd(int per) {
	return rand() <= RAND_MAX * double(per) / 100;
}

int main()
{
	srand(517);
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1, x; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			scanf("%d", &x);
			if (x) a[++tot] = (Node){j, i, x};
		}
	int ans = 0;
	for (int tm = 150; --tm; ) {
		for (int per = 0; per <= 100; ++per) {
			for (int i = 1; i <= tot; ++i) a[i].rd = rand();
			sort(a + 1, a + tot + 1, NodeCmp);
			int nk = k;
			Node no = (Node){a[1].x, 0, 0, 0};
			for (int i = 1; i <= tot; ++i) {
				for (int j = i + 1; a[j].v == a[i].v; ++j)
					if (Dis(no, a[j]) <= Dis(no, a[i]) && Rnd(per))
						swap(a[i], a[j]);
				if (Dis(no, a[i]) + 1 + a[i].y > nk) break;
				nk -= Dis(no, a[i]) + 1;
				no.v += a[i].v;
				no.x = a[i].x;
				no.y = a[i].y;
			}
			ans = max(ans, no.v);
		}
	}
	printf("%d\n", ans);
	return 0;
}
