%:pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int, int> pii;
const int N = 3e5 + 10;
int n, m, k, a[N];
pii p[N];
inline void FixP() {
	sort(p + 1, p + m + 1, greater<pii>());
	int top = 1;
	for (int i = 2; i <= m; ++i)
		if (p[i].second > p[top].second)
			p[++top] = p[i];
	m = top;
	p[m + 1] = pii(0, 0);
}
map<int, int> f;
inline int NumToKill(int i, int height) {
	if (height > p[i].first) return 2e18;
	if (f.count(height)) return f[height];
	for (int l = i, r = m + 1; l <= r; ) {
		int mid = (l + r) >> 1;
		if (p[mid].first >= height) i = mid, l = mid + 1;
		else r = mid - 1;
	}
	if (i == m + 1) return 0;
	int nd = height - p[i + 1].first;
	int cost = (nd + p[i].second - 1) / p[i].second;
	return f[height] = cost + NumToKill(i + 1, height - cost * p[i].second);
}
signed main() {
	scanf("%lld%lld%lld", &n, &m, &k);
	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	reverse(a + 1, a + n + 1);
	for (int i = 1; i <= m; ++i) scanf("%lld%lld", &p[i].first, &p[i].second);
	FixP();
	for (int i = 1; i <= n; ++i) {
		int tmp = NumToKill(1, a[i]);
		if (tmp <= k) {
			k -= tmp;
		} else {
			printf("%lld %lld\n", i - 1, k);
			return 0;
		}
	}
	printf("%lld %lld\n", n, k);
	return 0;
}
