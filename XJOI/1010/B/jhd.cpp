#include <cstdio>
#include <cstring>
#include <algorithm>
const int MAXN = 50 + 10;
const int MOD = 1e9 + 7;

int n;
char s[MAXN][MAXN];
int len[MAXN];
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
const int P[] =  {2, 3, 5, 7, 11,
	13, 17, 19, 23, 29,
	31, 37, 41, 43, 47};
struct Num {
	int a[15];
	Num(int x = 1) {
		for (int i = 0; i < 15; i++) {
			a[i] = 0;
			while(x % P[i] == 0) {
				a[i]++;
				x /= P[i];
			}
		}

	}
	friend Num lcm(const Num &a, const Num &b) {
		Num ans;
		for (int i = 0; i < 15; i++) {
			ans.a[i] = std::max(a.a[i], b.a[i]);
		}
		return ans;
	}
	Num operator * (const Num &rhs) const {
		Num ans;
		for (int i = 0; i < 15; i++) {
			ans.a[i] = a[i] + rhs.a[i];
		}
		return ans;
	}
	Num operator / (const Num &rhs) const {
		Num ans;
		for (int i = 0; i < 15; i++) {
			ans.a[i] = a[i] - rhs.a[i];
		}
		return ans;
	}
	int val() {
		int ans = 1;
		for (int i = 0; i < 15; i++) {
			ans = mul(ans, pwr(P[i], a[i]));
		}
		return ans;
	}
};
namespace solver1 {
	int f[MAXN][MAXN];
	void main() {

		Num p = 1, t = 1;

		for (int i = 1; i <= 50; i++) p = p * i;

		f[0][0] = 1;
		for (int i = 1; i <= n; i++) {
			int cnt = 0;
			for (int j = 1; j <= len[i]; j++) {
				cnt += s[i][j] == 'O';
			}
			f[i][0] = mul(f[i - 1][0], len[i] - cnt);
			for (int j = 1; j <= i; j++) {
				f[i][j] = add(mul(f[i - 1][j - 1], cnt) +
						mul(f[i - 1][j], len[i] - cnt));
			}
			t = t * len[i];
		}

		int val = (p / t).val();
		for (int i = 1; i <= n; i++) {
			//fprintf(stderr, "%d ", f[n][i]);
			printf("%d\n", mul(f[n][i], val));
		}
	}
}
namespace solver2 {
	int tot[MAXN];
	void main() {
		Num p = 1;
		for (int i = 1; i <= 50; i++) p = p * i;

		int lcm = len[1];
		for (int i = 2; i <= n; i++) {
			lcm = lcm / std::__gcd(lcm, len[i]) * len[i];
		}


		for (int i = 0; i < lcm; i++) {
			int cnt = 0;
			for (int j = 1; j <= n; j++) {
				if (s[j][i % len[j] + 1] == 'O') cnt++;
			}
			tot[cnt]++;
		}

		int val = (p / lcm).val();
		for (int i = 1; i <= n; i++) {
			printf("%d\n", mul(tot[i], val));
		}
	}
}
int main() {
	scanf("%d", &n);
	bool flag = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d%s", len + i, s[i] + 1);
		for (int j = 1; j < i; j++) {
			flag &= (std::__gcd(len[j], len[i]) == 1);
		}
	}

	if (flag) {
		solver1::main();
	} else {
		solver2::main();
	}

}
