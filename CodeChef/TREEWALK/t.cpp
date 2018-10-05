#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

const int mod = 998244353;

long long power(int x, int p) {
	long long res =1;
	long long temp = x;
	while(p) {
		if((p&1) == 1) {
			res *= temp;
			res %= mod;
		}
		temp = temp*temp;

		temp %= mod;
		p /= 2;
	}
	return res;
}

long long inverse(int x) {
	return power(x, mod - 2);
}
vector<vector<int> > child;
int parent[241];
int leaf[241];

void dfs(int node, int par) {
	parent[node] = par;
	bool lf = true;
	for(int i = 0; i < child[node].size(); i++) {
		if(child[node][i] != par) {
			dfs(child[node][i], node);
			lf = false;
		}
	}
	if(lf) {
		leaf[node] = 1;
	}
}

int main() {
	int n;
	scanf("%d", &n);

	child.resize(n+1, vector<int>());
	int egde[n][2];
	for(int i = 0; i < n-1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		egde[i][0] = x, egde[i][1] = y;
		child[x].push_back(y);
		child[y].push_back(x);
	}
	int m;
	scanf("%d", &m);
	int arr[m];
	for(int i = 0; i < m; i++) scanf("%d", arr + i);

	sort(arr, arr + m);
	int q;
	scanf("%d", &q);

	parent[1] = -1;

	dfs(1, -1);
	long long upward[241] = {0};
	long long downward[241] = {0};
	long long ans[241] = {0};
	int inv[241];
	for(int i = 1; i <= 240; i++) {
		inv[i] = inverse(i);
	}

	for(int time = 1, k = 0; time <= q; time++) {
		while(k < m and arr[k] == time) {
			downward[1] += 1;
			k++;
		}
		for(int i = 1; i <= n; i++) {
			ans[i] = (ans[i] + upward[i] + downward[i])%mod;
		}

		for(int i = 2; i <= n; i++) {
			if(leaf[i]) {
				upward[i] = (upward[i] + downward[i])%mod;
				downward[i] = 0;
			}
		}
		downward[1] = (downward[1] + upward[1])%mod;

		long long temp_up[241] = {0}, temp_down[241] = {0};
		for(int ed = 0; ed < n-1; ed++) {
			int par, cld;
			par = egde[ed][1];
			cld = egde[ed][0];
			// cout <<k << " " << ed << "\n";
			if(parent[egde[ed][0]] != egde[ed][1]) {
				par = egde[ed][0];
				cld = egde[ed][1];
			}

			long long down_dis = (downward[par] * inv[child[par].size()-1])%mod;
			if(par == 1) {
				down_dis = (downward[par] * inv[child[par].size()])%mod;
			}
			temp_up[par] = (temp_up[par] + upward[cld])%mod;
			temp_down[cld] = (temp_down[cld] + down_dis)%mod;

		}
		// cout << "--";
		for(int i = 1; i <= n; i++) {
			downward[i] = temp_down[i];
			upward[i] = temp_up[i];
		}
		// for(int i = 0; i < n; i++) {
		// 	if(i) printf(" ");
		// 	printf("%lld", ans[i+1]);
		// }
		// cout << "\n";

	}

	for(int i = 0; i < n; i++) {
		if(i) printf(" ");
		printf("%lld", (ans[i+1] + mod)%mod);
	}

}
