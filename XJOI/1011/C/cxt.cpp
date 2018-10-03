#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 1e6 + 10;
int n, P;
int pri[N / 10], pnum;
bool np[N];

inline void GetPri() {
	for (int i = 2; i <= P; ++i) if (!np[i]) {
		pri[++pnum] = i;
		for (int j = i * i; j <= P; j += i) np[j] = 1;
	}
}

inline int Dfs(int x, int val) {
	if (val * pri[x] > n) return 1;
	if (val * pri[x] * pri[x] > n) {
		int p = lower_bound(pri + 1, pri + pnum + 1, n / val) - pri;
		if (p <= pnum && pri[p] * val <= n) p++;
		return p - x + 1;
	}
	int ans = Dfs(x + 1, val);
	val *= pri[x];
	ans += Dfs(x + 1, val);
	int n_div = n / (pri[x] * pri[x]);
	while (val <= n_div) {
		val = val * pri[x] * pri[x];
		ans += Dfs(x + 1, val);
	}
	return ans;
}

signed main() {
	scanf("%lld%lld", &n, &P);
	GetPri();
	pri[++pnum] = n + 1;
	printf("%lld\n", Dfs(1, 1));
	return 0;
}
