#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 101000, M = 1010100, MOD = 998244353;

namespace {
	int Add(int x, int y) { return (x += y) >= MOD ? x - MOD : x; }
	int Dec(int x, int y) { return (x -= y) < 0 ? x + MOD : x; }
	int Mul(int x, int y) { return 1LL * x * y % MOD; }
	int Kissme(int x, int y) {
		int c = 1;
		while(y) {
			if(y & 1) c = Mul(c, x);
			x = Mul(x, x);
			y >>= 1;
		}
		return c;
	}
}

namespace Sub2 {

	int n, a[M], Q, b[M], miu[M], phi[M], f[M], g[M], inv[M], val[N];
	vector<int> vv[M];
	set<pair<int, int> > st;

	void Init(int lim) {
		for(int i = 1; i <= lim; i++)
			miu[i] = 1, phi[i] = i;
		for(int i = 2; i <= lim; i++) {
			if(!b[i]) {
				for(int j = i, k = 1; j <= lim; j += i, k++) {
					b[j] = 1;
					miu[j] = !(k % i) ? 0 : -miu[j];
					phi[j] = phi[j] / i * (i - 1);
				}
			}
		}
		for(int i = 1; i <= lim; i++)
			for(int j = i; j <= lim; j += i)
				vv[j].push_back(i);
	}

	void Split(int x) {
		if(x > n) return;
		auto ix = st.upper_bound({x, n}); --ix;
		if(x > (*ix).first) {
			int l = (*ix).first, r = (*ix).second;
			st.insert({l, x - 1});
			st.insert({x, r});
			val[x] = val[l];
			st.erase(ix);
		}
	}

	void Update(int &Ans, int id, int val) {
		int now =  Add(Mul(2 * f[id], val), Mul(val, val));
		f[id] = Add(f[id], val);
		Ans = Add(Ans, Mul(g[id], now));
	}

	void Rmain(void) {
		scanf("%d", &n);
		int mx = 1e6;
		for(int i = 1, x; i <= n; i++) {
			scanf("%d", &x), a[x] = Add(a[x], x), mx = max(mx, x);
			st.insert({i, i});
			val[i] = x;
		}
		Init(mx);
		int Ans = 0;
		for(int d = 1; d <= mx; d++) {
			int now = 0;
			for(int i = d, k = 1; i <= mx; i += d, k++)
				now = Add(now, a[i]);
			f[d] = now;
		}

		inv[1] = 1;
		for(int i = 2; i <= mx; i++)
			inv[i] = Mul(MOD / i, MOD - inv[MOD % i]);

		for(int p = 1; p <= mx; p++) {
			for(int i = p; i <= mx; i += p)
				g[i] = Add(g[i], !~miu[i / p] ? MOD - inv[p] : Mul(miu[i / p], inv[p]));
		}
		for(int d = 1; d <= mx; d++)
			Ans = Add(Ans, Mul(g[d], Mul(f[d], f[d])));
		//cout << Ans << endl;
		printf("%d\n", Ans);

		scanf("%d", &Q);
		while(Q--) {
			int l, r, v;
			scanf("%d%d%d", &l, &r, &v);
			Split(l);
			Split(r + 1);

			auto ix = st.upper_bound({l, n}); --ix;
			while(ix != st.end() && (*ix).first <= r) {
				int now = val[(*ix).first], lim = sqrt(now);
				for(auto i : vv[now])
					Update(Ans, i, MOD - Mul((*ix).second - (*ix).first + 1, now));
				st.erase(ix++);
			}
			st.insert({l, r});
			val[l] = v;
			for(auto i : vv[v])
				Update(Ans, i, Mul((r - l + 1), v));

			printf("%d\n", Ans);

		}
	}

}

int Ty;

int main(void) {
	scanf("%d", &Ty);
	Sub2::Rmain();
}
