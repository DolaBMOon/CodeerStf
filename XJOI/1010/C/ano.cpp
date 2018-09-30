#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1010100;

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

int n, T, r[N], pw[N], f[N];
long long l[N];

namespace Sub1 {

	set<vector<int> > st;

	void Rmain(void) {
		vector<int> id;
		id.resize(n);
		for(int i = 0; i < (1 << n); i++) {
			vector<pair<long long, int> > v;
			for(int j = 1; j <= n; j++)
				if(i >> (j - 1) & 1) {
					v.push_back({l[j] + n, j});
				} else
					v.push_back({l[j], j});
			sort(v.begin(), v.end());
			//      cerr << i << " " << v.size() << endl;
			for(int j = 0; j < n; j++)
				id[j] = v[j].second;
			st.insert(id);
			//      cerr << i << endl;
		}
		cout << st.size() << endl;
	}

}

namespace Sub2 {

	void Rmain(void) {
		puts("1");
	}

}

namespace Sub3 {

	void Rmain(void) {
		f[1] = 1;
		for(int i = 1; i <= n; i++) {
			f[r[i] + 1] = Add(f[r[i] + 1],
					Dec(Mul(f[i], pw[r[i] - i]), f[i]));
			f[i + 1] = Add(f[i + 1], f[i]);
		}
		cout << f[n + 1] << endl;
	}

}

namespace Sub4 {

	void Rmain(void) {
		f[0] = 1;
		for(int i = 1, x = 1; i <= n; i++) {
			while(l[x] < l[i] - n) x++;
			f[i] = Add(f[i], Mul(2, f[i - 1]));
			f[r[i]] = Dec(f[r[i]], f[x - 1]);
		}
		cout << f[n] << endl;
	}

}

int main(void) {
	scanf("%d%d", &n, &T);
	bool flg = 1;
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &l[i]);
		flg &= l[i] == i;
	}
	pw[0] = 1;
	for(int i = 1; i <= n; i++) {
		pw[i] = pw[i - 1] * 2 % MOD;
		r[i] = upper_bound(l + 1, l + n + 1, l[i] + n) - l - 1;
	}
	if(n <= 18) Sub1::Rmain();
	else if(T == 1) Sub2::Rmain();
	else if(flg) Sub3::Rmain();
	else Sub4::Rmain();
	return 0;
}
