#include <bits/stdc++.h>
using namespace std;

const int p[4] = {2, 3, 5, 7};

int coe[10][4];

void Init(void) {
	for(int i = 2; i <= 9; i++) {
		int x = i;
		for(int j = 0; j < 4; j++) {
			while(x % p[j] == 0)
				coe[i][j]++, x /= p[j];
		}
	}
}

long long K;
map<long long, long long> f[20];
vector<int> tmp;

long long Dfs(int x, int c2, int c3, int c5, int c7, int lim, long long val, int zero) {
	if(x == tmp.size()) return val <= K;
	if(!lim && !zero && f[x].find(val) != f[x].end()) return f[x][val];
	long long ans = 0;
	int up = lim ? tmp[x] : 9;
	ans += Dfs(x + 1, c2, c3, c5, c7, 0 == up, val * (zero ? 1 : 0), zero);

	for(int i = 1; i <= up; i++)
		ans += Dfs(x + 1, c2 + coe[i][0], c3 + coe[i][1], c5 + coe[i][2],
				c7 + coe[i][3], lim && i == up, val * i, 0);

	if(!lim && !zero) f[x][val] = ans;
	return ans;
}

long long Solve(long long L, long long k) {
	if(L < 0 || k < 0) return 0;
	K = k;
	tmp.clear();
	while(L) {
		tmp.push_back(L % 10);
		L /= 10;
	}
	reverse(tmp.begin(), tmp.end());
	for(int i = 0; i < tmp.size(); i++)
		f[i].clear();
	return Dfs(0, 0, 0, 0, 0, 1, 1, 1);
}

int main(void) {
	Init();
	long long L, R, L1, R1;
	scanf("%lld%lld%lld%lld", &L, &R, &L1, &R1);
	printf("%lld\n", Solve(R, R1) - Solve(R, L1 - 1)
			- Solve(L - 1, R1) + Solve(L - 1, L1 - 1));
	return 0;
}
