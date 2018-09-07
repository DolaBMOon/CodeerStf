#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7, N = 1010, M = 55;
const long long MODD = 1LL * MOD * MOD;

namespace {
	long long Add(long long x, long long y) { return (x += y) >= MODD ? x - MODD : x; }
	int Add(int x, int y) { return (x += y) >= MOD ? x - MOD : x; }
}

int D[M][M], E[M][M], A[31][M][M], B[31][M][M];
int n, m, O[N][M], I[N][M], Q, f[N], C[M][M];
long long tmp[M][M];

void Mul(int A[][M], int B[][M]) {
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			tmp[i][j] = 0;
	for(int k = 0; k < m; k++)
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				tmp[i][j] = Add(tmp[i][j], 1LL * A[i][k] * B[k][j]);
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			C[i][j] = tmp[i][j] % MOD;
}

void Calc(int x) {
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			D[i][j] = E[i][j] = 0;
	if(!~x) return;
	for(int i = 0; i < m; i++)
		D[i][i] = E[i][i] = 1;

	for(int i = 0; i < 31; i++)
		if(x >> i & 1) {
			Mul(B[i], E);
			for(int j = 0; j < m; j++)
				for(int k = 0; k < m; k++)
					D[j][k] = Add(D[j][k], C[j][k]);
			Mul(E, A[i]);
			for(int j = 0; j < m; j++)
				for(int k = 0; k < m; k++)
					E[j][k] = C[j][k];
		}
}

int main(void) {
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++)
			scanf("%d", &O[i][j]), O[i][j] %= MOD;
		for(int j = 0; j < m; j++)
			scanf("%d", &I[i][j]), I[i][j] %= MOD;
	}
	for(int k = 0; k < n; k++)
		for(int i = 0; i < m; i++) { 
			for(int j = 0; j < m; j++)
				tmp[i][j] = Add(tmp[i][j], 1LL * I[k][i] * O[k][j]);
		}
	for(int i = 0; i < m; i++)
		for(int j = 0; j < m; j++)
			B[0][i][j] = A[0][i][j] = (tmp[i][j] %= MOD);

	for(int i = 1; i < 31; i++) {
		Mul(A[i - 1], A[i - 1]);
		for(int j = 0; j < m; j++)
			for(int k = 0; k < m; k++)
				A[i][j][k] = C[j][k];
		for(int j = 0; j < m; j++)
			A[i - 1][j][j] = Add(A[i - 1][j][j], 1);
		Mul(A[i - 1], B[i - 1]);
		for(int j = 0; j < m; j++)
			for(int k = 0; k < m; k++)
				B[i][j][k] = C[j][k];
		for(int j = 0; j < m; j++)
			A[i - 1][j][j] = Add(A[i - 1][j][j], MOD - 1);
	}

	scanf("%d", &Q);
	while(Q--) {
		int u, v, d;
		scanf("%d%d%d", &u, &v, &d);
		u--; v--;
		Calc(d - 1);
		for(int i = 0; i < n; i++)
			f[i] = 0;
		for(int i = 0; i < m; i++)
			for(int j = 0; j < m; j++)
				f[i] = Add(f[i], (int)(1LL * O[u][j] * D[j][i] % MOD));
		int Ans = u == v;
		for(int j = 0; j < m; j++)
			Ans = Add(Ans, (int)(1LL * f[j] * I[v][j] % MOD));
		cout << Ans << endl;
	}
	return 0;
}
