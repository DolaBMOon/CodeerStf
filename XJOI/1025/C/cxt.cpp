#include<bits/stdc++.h>
using namespace std;
typedef list<int>::iterator Lit;
const int N = 1e5 + 10, BLO = 400;
int n, m, num[N / BLO + 10][N];
Lit fs[N / BLO + 10];
list<int> va;
inline Lit FindRank(int k) {
	Lit ans = fs[k / BLO];
	k %= BLO;
	while (k--) ++ans;
	return ans;
}
int main() {
	scanf("%d", &n);
	for (int i = 0, x; i < n; ++i) {
		scanf("%d", &x);
		va.push_back(x);
		if (i % BLO == 0) fs[i / BLO] = --va.end();
		++num[i / BLO][x];
	}
	scanf("%d", &m);
	va.push_back(2333);
	for (int id = 0, ans = 0, opt, l, r, k; id < m; ++id) {
		scanf("%d%d%d", &opt, &l, &r); --l; --r;

		l = (l + ans) % n;
		r = (r + ans) % n;
		if (l > r) swap(l, r);

		if (opt == 1) {
			if (l == r) continue;
			Lit pos_r = FindRank(r);
			Lit pos_l = FindRank(l);
			va.insert(pos_l, *pos_r);
			if (r % BLO == 0) ++fs[r / BLO];
			if (l % BLO == 0) --fs[l / BLO];
			++num[l / BLO][*pos_r];
			--num[r / BLO][*pos_r];
			va.erase(pos_r);
			for (int i = r / BLO; i * BLO > l; --i) {
				--fs[i];
				++num[i][*fs[i]];
				--num[i - 1][*fs[i]];
			}
		} else {
			scanf("%d", &k);

			k = (k + ans - 1) % n + 1;

			Lit pos_r = ++FindRank(r);
			Lit pos_l = FindRank(l);
			int l_bel = l / BLO, r_bel = r / BLO;
			ans = 0;
			if (l_bel == r_bel) {
				for (Lit i = pos_l; i != pos_r; ++i) ans += (*i == k);
			} else {
				for (int i = l_bel + 1; i != r_bel; ++i) ans += num[i][k];
				while (pos_l != fs[l_bel + 1]) ans += (*(pos_l++) == k);
				for (Lit i = fs[r_bel]; i != pos_r; ++i) ans += (*i == k);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}
