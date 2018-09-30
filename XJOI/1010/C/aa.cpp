#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
typedef long long LL;
const int MAXN = 1e6 + 10;
const int MOD = 1e9 + 7;

int n, t;
LL a[MAXN];
namespace {
	inline int add(int x) { return x >= MOD ? x - MOD : x; }
	inline int sub(int x) { return x < 0 ? x + MOD : x; }
	inline int mul(int x, int y) { return 1ll * x * y % MOD; }
	inline int pwr(int x, int y) {
		int ans = 1;
		for (; y; y >>= 1, x = mul(x, x)) {
			if (y & 1) ans = mul(ans, x);
		}
		return ans;
	}
}
namespace solver1 {
	int f[MAXN][3];
	void main() {
		if (n <= 1) {
			puts("1");
			return;
		}
		f[2][0] = 1;
		f[2][1] = (a[1] + n > a[2]);
		for (int i = 3; i <= n; i++) {
			if (a[i - 1] + n > a[i]) {
				f[i][0] = add(f[i - 1][0] + f[i - 1][1]);
				f[i][1] = f[i - 1][0];
			} else {
				f[i][0] = add(f[i - 1][0] + f[i - 1][1]);
			}
		}

		printf("%d\n", add(f[n][1] + f[n][0]));

	}
}
namespace solver3 {
	int v[MAXN];
	bool cmp(int a, int b) { return v[a] < v[b]; }
	long long fact[MAXN];
	std::set< std::vector <int> > s;
	void main() {
		static int seq[MAXN];
		fact[0] = 0;
		for (int i = 1; i <= n; i++) fact[i] = fact[i - 1] * i;
		for (int i = 1; i <= n; i++) seq[i] = i;

		for (int i = 0; i < (1 << n); i++) {
			for (int j = 1; j <= n; j++) {
				if (!(i & (1 << (j - 1)))) v[j] = a[j];
				else v[j] = a[j] + n;
			}
			std::sort(seq + 1, seq + n + 1, cmp);
			std::vector <int> t(seq + 1, seq + n + 1);
			s.insert(t);
		}

		printf("%lu\n", s.size());

	}
}
namespace solver2 {
	void main() {
		printf("%d\n", sub(pwr(2, n) - n));
	}
}
int main() {
	scanf("%d%d", &n, &t);
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
		flag &= (a[i] == i);
	}

	if (t == 1) {
		puts("1");
	} else if (t == 2) {
		solver1::main();
	} else if (flag) {
		solver2::main();
	} else {
		solver3::main();
	}
}
