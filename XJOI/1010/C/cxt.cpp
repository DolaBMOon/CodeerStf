%:pragma GCC optimize(2)
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 10;
const int p = 1e9 + 7;

int n, sp, rp[N];
map<int, int> f[N];
ll a[N];

inline int Fix(int x) {
	return x >= p ? x - p : x;
}

inline void A(int &x, int y) {
	x = (x + y >= p ? x + y - p : x + y);
}

int main() {
	scanf("%d%d", &n, &sp);

	for (int i = 1; i <= n; ++i) scanf("%lld", a + i);
	for (int i = n, ri = n; i; --i) {
		while (a[i] + n <= a[ri]) --ri;
		rp[i] = ri;
	}

	f[0][0] = 1;
	for (int i = 0; i < n; ++i) {
		int np = rp[i + 1];
		for (map<int, int>::iterator it = f[i].begin(); it != f[i].end(); ++it) {
			int j = it->first;
			A(f[i + 1][max(j, i)], it->second);
			A(f[i + 1][np], it->second);
			if (i + 1 > j) A(f[np][rp[np]], p - it->second);
		}
		// cerr << f[i].size() << endl;
	}
	int ans = 0;
	for (map<int, int>::iterator it = f[n].begin(); it != f[n].end(); ++it) A(ans, it->second);
	printf("%d\n", ans);
	return 0;
}
