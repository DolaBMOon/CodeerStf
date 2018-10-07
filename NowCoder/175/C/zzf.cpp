#include <bits/stdc++.h>
using namespace std;

const int N = 3030;

struct Node {
	int p, l, r;
}a[N];

vector<int> Val;
int n;

namespace Sub1 {

	int tag[N << 2], ans;

	void Rmain(void) {
		for(int i = 0; i < (1 << n); i++) {
			for(int j = 0; j < Val.size(); j++)
				tag[j] = 0;
			for(int j = 0; j < n; j++)
				if(i >> j & 1) {
					tag[a[j + 1].l]++;
					tag[a[j + 1].p]--;
				} else {
					tag[a[j + 1].p]++;
					tag[a[j + 1].r]--;
				}
			int fin = 0;
			for(int j = 0, now = 0; j < Val.size(); j++) {
				now += tag[j];
				if(now) fin += Val[j + 1] - Val[j];
			}
			ans = max(ans, fin);
		}
		printf("%d\n", ans);
	}

}

namespace Sub2 {

	int tag[N << 2], ans;

	void Rmain(void) {
		for(int i = 1; i <= n; i++)
			tag[a[i].l]++, tag[a[i].p]--;
		for(int i = 0, now = 0; i < Val.size(); i++) {
			now += tag[i];
			if(now) ans += Val[i + 1] - Val[i];
		}
		printf("%d\n", ans);
	}

}

namespace Sub3 {

	vector<int> Lp[N << 2], Rp[N << 2];
	map<int, int> f[N * 3][2];

	int Dfs(int x, int r, int tp) {
		if(x == Val.size()) return 0;
		if(x > r) r = x, tp = 1;
		if(f[x][tp].find(r) != f[x][tp].end()) return f[x][tp][r];
		int ans = 0;
		ans = Dfs(x + 1, r, tp);

		if(tp || x < r) {
			for(int i : Rp[x]) {
				if(i > r)
					ans = max(ans, Dfs(tp ? x + 1 : r + 1, i, 1) + Val[i] - Val[r]);
			}
		}
		for(int i : Lp[x]) {
			if(i > r)
				ans = max(ans, Dfs(tp ? x + 1 : r + 1, i, 0) + Val[i] - Val[r]);
		}
		return f[x][tp][r] = ans;
	}

	void Rmain(void) {
		for(int i = 1; i <= n; i++) {
			Lp[a[i].l].push_back(a[i].p);
			Rp[a[i].p].push_back(a[i].r);
		}
		printf("%d\n", Dfs(0, 0, 0));
	}

}

namespace Sub4 {

	int tag[N << 2], ans;
	double p[N << 2];

	void Rmain(void) {
		srand(12070712);
		int clk = clock();
		for(int i = 1; i <= n; i++) {
			p[i] = (double)(Val[a[i].p] - Val[a[i].l]) / (Val[a[i].r] - Val[a[i].l]);
			p[i] = 0.5 + (p[i] - 0.5) / 6;
		}
		while((double)(clock() - clk) / CLOCKS_PER_SEC < 1.9) {
			random_shuffle(a + 1, a + n + 1);
			for(int i = 0; i < Val.size(); i++)
				tag[i] = 0;
			for(int i = 1; i <= n; i++)
				if((double)rand() / RAND_MAX < p[i]) {
					tag[a[i].l]++;
					tag[a[i].p]--;
				} else {
					tag[a[i].p]++;
					tag[a[i].r]--;
				}
			int fin = 0;
			for(int i = 0, now = 0; i < Val.size(); i++) {
				now += tag[i];
				if(now)
					fin += Val[i + 1] - Val[i];
			}
			ans = max(ans, fin);
		}
		printf("%d\n", ans);
	}

}

int main(void) {
	scanf("%d", &n);
	bool flg = 1;
	vector<int> tmp;
	for(int i = 1; i <= n; i++) {
		scanf("%d%d%d", &a[i].p, &a[i].l, &a[i].r);
		Val.push_back(a[i].p - a[i].l);
		Val.push_back(a[i].p);
		Val.push_back(a[i].p + a[i].r);
		tmp.push_back(a[i].p);
		flg &= !a[i].r;
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	sort(Val.begin(), Val.end());
	Val.erase(unique(Val.begin(), Val.end()), Val.end());
	//  cerr << Val.size() << endl;
	for(int i = 1; i <= n; i++) {
		a[i].r = lower_bound(Val.begin(), Val.end(), a[i].p + a[i].r) - Val.begin();
		a[i].l = lower_bound(Val.begin(), Val.end(), a[i].p - a[i].l) - Val.begin();
		a[i].p = lower_bound(Val.begin(), Val.end(), a[i].p) - Val.begin();
		//cerr << a[i].l << " " << a[i].p << " " << a[i].r << endl;
	}
	//Sub4::Rmain();
	if(n <= 15) Sub1::Rmain();
	else if(flg) Sub2::Rmain();
	else if(tmp.size() == n) Sub3::Rmain();
	else Sub4::Rmain();
	return 0;
}
