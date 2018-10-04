%:pragma GCC optimize(2)
#include<bits/stdc++.h>

using namespace std;

const int N = 35, M = 55;
const int MN = 420;
const int p = 1e9 + 7;
const int pri[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int pmax[] = {32, 27, 25, 49, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
const int pnum = sizeof(pri) / sizeof(*pri);

int n, len[N], mlen[N], all, inv[M];
char s[N][M];
vector<int> g[M];

inline void A(int &x, int y) {
	x = (x + y >= p ? x + y - p : x + y);
}

inline int Qmi(int x, int y = p - 2) {
	int ans = 1;
	for (; y; y >>= 1, x = 1ll * x * x % p) if (y & 1) ans = 1ll * ans * x % p;
	return ans;
}

int cnt[N], ans[N], f[N], _f[N];
bool fl[N];
inline void Count(int pr, int pm, int md) {
	memset(cnt, 0, sizeof cnt);
	for (int i = 0; i < pm; ++i) {
		int tot = 0;
		for (int j = 0; j < (int)g[pr].size(); ++j) {
			int no = g[pr][j];
			tot += (s[no][(i * MN + md) % len[no]] == 'O');
		}
		++cnt[tot];
	}
}

inline void Update(int m, int _pmax) {
	memcpy(_f, f, sizeof f);
	memset(f, 0, sizeof f);
	for (int j = 0; j <= n; ++j) if (_f[j])
		for (int k = 0; k <= m; ++k)
			A(f[j + k], 1ll * _f[j] * cnt[k] % p * inv[_pmax] % p);
}

int main() {
	all = 1;
	for (int i = 1; i <= 50; ++i) all = 1ll * all * i % p;
	inv[0] = inv[1] = 1;
	for (int i = 2; i <= 50; ++i) inv[i] = 1ll * inv[p % i] * (p - p / i) % p;
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%s", len + i, s[i]);
		mlen[i] = len[i] / __gcd(len[i], MN);
		for (int j = 0; j < pnum; ++j)
			if (mlen[i] % pri[j]== 0) {
				g[j].push_back(i);
				fl[i] = 1;
				break;
			}
	}
	for (int md = 0; md < MN; ++md) {
		memset(f, 0, sizeof f);
		f[0] = all;
		for (int i = 1; i <= n; ++i) if (!fl[i]) {
			cnt[0] = cnt[1] = 0;
			++cnt[s[i][md % len[i]] == 'O'];
			Update(1, 1);
		}
		for (int i = 0; i < pnum; ++i) if (g[i].size()) {
			Count(i, pmax[i], md);
			Update(g[i].size(), pmax[i]);
		}
		for (int j = 0; j <= n; ++j) A(ans[j], f[j]);
	}
	for (int i = 1; i <= n; ++i) printf("%lld\n", 1ll * Qmi(MN) * ans[i] % p);
	return 0;
}
