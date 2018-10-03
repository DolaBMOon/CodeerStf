
#include<bits/stdc++.h>

using namespace std;

#define int long long

const int N = 5010;

int n, val[N], de[N], ans[N];
int cnt[N], nu[N][N], qu[N];
map<int, int> mp;

int tot, fi[N], a[N << 1], ne[N << 1];
inline void Add(int x, int y) {
	a[++tot] = y; ne[tot] = fi[x]; fi[x] = tot;
}

inline void Merge(vector<int> &a, const vector<int> &b) {
	for (int i = 0; i < (int)a.size(); ++i)
		for (int j = 0; j < (int)b.size(); ++j) {
			if (de[a[i]] < de[b[j]] && val[a[i]] > val[b[j]]) {
				++cnt[a[i]];
				qu[a[i]] += nu[a[i]][val[b[j]]]++;
			}
			if (de[a[i]] > de[b[j]] && val[a[i]] < val[b[j]]) {
				++cnt[b[j]];
				qu[b[j]] += nu[b[j]][val[a[i]]]++;
			}
		}
	a.insert(a.end(), b.begin(), b.end());
}

inline int Calc(const vector<int> &a) {
	int ans = 0;
	for (int i = 0; i < (int)a.size(); ++i)
		ans += (cnt[a[i]] * (cnt[a[i]] - 1) >> 1) - qu[a[i]];
	return ans;
}

inline vector<int> Dfs(int x, int fa) {
	de[x] = de[fa] + 1;
	vector<int> no(1, x);
	for (int i = fi[x]; i; i = ne[i]) if (a[i] != fa) Merge(no, Dfs(a[i], x));
	ans[x] = Calc(no);
	return no;
}

signed main() {
	scanf("%lld", &n);
	for (int i = 1; i <= n; ++i) scanf("%lld", val + i), mp[val[i]] = 1;
	int col_num = 0;
	for (map<int, int>::iterator it = mp.begin(); it != mp.end(); ++it) it->second = ++col_num;
	for (int i = 1; i <= n; ++i) val[i] = mp[val[i]];
	for (int i = 1, x, y; i < n; ++i) {
		scanf("%lld%lld", &x, &y);
		Add(x, y); Add(y, x);
	}
	Dfs(1, 0);
	for (int i = 1; i <= n; ++i) printf("%lld ", ans[i]);
	puts("");
	return 0;
}
