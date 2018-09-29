%:pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int Xu = 1e5 + 5;

typedef pair <int, int> pii;
typedef set < pii > :: iterator iter;

set < pii > Set;

const int mod = 998244353;
const int MAX = 1e6;

namespace {
	int add(int x) {return (x >= mod) ? x - mod : x;}
	int sub(int x) {return (x < 0) ? x + mod : x;}
	void Add(int &x, int y) {x = add(x + y);}
	void Sub(int &x, int y) {x = sub(x - y);}
	int Pow(int x, int y) {
		int res = 1;
		for(; y; y >>= 1, x = 1LL * x * x % mod) {
			if(y & 1)
				res = 1LL * res * x % mod;
		}
		return res;
	}
}

bool isp[N];
int n, pr[N], cnt, mu[N], A[N], C[N], ty;

vector <int> G[N];
int f[N];

void prework(int n = 1e6) {
	for(int i = 2; i <= n; ++ i)
		isp[i] = 1;
	mu[1] = 1;
	for(int i = 1; i <= n; ++ i) {
		if(isp[i]) pr[++ cnt] = i, mu[i] = sub(-1);
		for(int j = 1; j <= cnt && pr[j] * i <= n; ++ j) {
			isp[i * pr[j]] = 0;
			if(i % pr[j] == 0) {
				mu[i * pr[j]] = 0;
				break;
			}
			else mu[i * pr[j]] = 1LL * mu[i] * mu[pr[j]] % mod;
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = i; j <= n; j += i) {
			G[j].push_back(i);
			Add(f[j], 1LL * i * mu[i] % mod);
		}
	}
	for(int i = 1; i <= n; ++ i)
		f[i] = 1LL * f[i] * i % mod;
	//cout << mu[30] <<" " << mu[210] << endl;
}

int S[N], ans;

void Insert(int v, int Len) {
	Len = add(sub(Len));
	for(int i = 0; i < (int) G[v].size(); ++ i) {
		int now = G[v][i];
		//Len * (v / now)
		Sub(ans, 1LL * f[now] * S[now] % mod * S[now] % mod);
		Add(S[now], 1LL * Len * (v / now) % mod);
		Add(ans, 1LL * f[now] * S[now] % mod * S[now] % mod);
	}
}

void modify(int l, int r, int v) {
	iter L = -- Set.upper_bound(make_pair(l, 2e9)), R = -- Set.upper_bound(make_pair(r + 1, 2e9));
	pii Nxt = *R;
	Set.insert(make_pair(l, (*L).second));
	Set.insert(make_pair(r + 1, (*R).second));
	L = Set.lower_bound(make_pair(l, -2e9)), R = Set.lower_bound(make_pair(r + 1, -2e9));
	vector <pii> Del;
	int Len;
	for(iter it = L; it != R; ++ it) {
		iter now = it;
		Del.push_back(*it);
		++ now; Len = (*now).first - (*it).first;
		Insert((*it).second, -Len);
	}
	Insert(v, r - l + 1);
	for(int i = 0; i < (int) Del.size(); ++ i) Set.erase(Del[i]);
	Set.insert(make_pair(l, v));
	Set.insert(make_pair(r + 1, Nxt.second));
}

int main() {
	// freopen("herb5.in", "r", stdin);
	//freopen("myout", "w", stdout);
	prework();
	cin >> ty;
	cin >> n;
	Set.insert(make_pair(0, -123123123));
	Set.insert(make_pair(n + 1, -123123123));
	for(int i = 1; i <= n; ++ i)
		scanf("%d", &A[i]), ++ C[A[i]], Set.insert(make_pair(i, A[i]));
	for(int i = 1; i <= MAX; ++ i) {
		for(int j = i; j <= MAX; j += i) {
			Add(S[i], 1LL * C[j] * (j / i) % mod);
		}
		Add(ans, 1LL * f[i] * S[i] % mod * S[i] % mod);
	}
	cout << ans << endl;
	int q, l, r, v;
	for(cin >> q; q --;) {
		scanf("%d%d%d", &l, &r, &v);
		//if(q <= 95500) cerr << l <<" " << r <<" " << v << endl;
		modify(l, r, v);
		printf("%d\n", ans);
	}
}
