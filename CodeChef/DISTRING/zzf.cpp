#include <bits/stdc++.h>
using namespace std;

const int N = 501000;

vector<int> A[N];
long long Ans;
int n, m;

char Getc(void) {
	static char pool[100000], *p1 = pool, *p2 = pool;
	return p1 == p2 && (p2 = (p1 = pool) + fread(pool, 1, 100000, stdin), p1 == p2)
		? EOF : *p1++;
}

void Read(int &x) {
	x = 0; char ch = Getc();
	while(ch < '0' || ch > '9') ch = Getc();
	while(ch >= '0' && ch <= '9')
		x = x * 10 + ch - 48, ch = Getc();
}

namespace Solver1 {

	vector<int> now[N];
	int stat[N], vis[N], lst[N];

	void Rmain(void) {
		for(int l = 1; l <= m; l++) {
			int tot = 1;
			for(int i = 1; i <= n; i++)
				stat[i] = 1;

			for(int r = l; r <= m; r++) {
				for(int i = 1; i <= n; i++) {
					now[stat[i]].push_back(i);
				}
				int ntot = 0;
				for(int i = 1; i <= tot; i++) {
					for(int j : now[i]) {
						if(!vis[A[j][r]]) vis[A[j][r]] = ++ntot;
						Ans += 1LL * (j - lst[A[j][r]]) * (n - j + 1);

						stat[j] = vis[A[j][r]];
						lst[A[j][r]] = j;
					}
					for(int j : now[i])
						vis[A[j][r]] = 0, lst[A[j][r]] = 0;
				}
				tot = ntot;
				for(int i = 1; i <= tot; i++)
					now[i].clear();
			}

		}
	}

}

namespace Solver2 {

	int lcp[1000][1000];

	void Rmain(void) {
		for(int l = m; l >= 1; l--) {

			for(int i = 1; i <= n; i++) {
				int mx = 0;
				for(int j = i - 1; j >= 1; j--) {
					if(A[i][l] == A[j][l])
						lcp[i][j]++;
					else lcp[i][j] = 0;
					if(lcp[i][j] > mx) {
						Ans += 1LL * (i - j) * (lcp[i][j] - mx) * (n - i + 1);
						mx = lcp[i][j];
					}
				}
				Ans += (m - l + 1 - mx) * i * (n - i + 1);
			}

		}
	}

}

int main(void) {
	Read(n), Read(m);
	vector<int> tmp;
	for(int i = 1; i <= n; i++) {
		A[i].resize(m + 1);
		for(int j = 1; j <= m; j++) {
			Read(A[i][j]);
			tmp.push_back(A[i][j]);
		}
	}
	sort(tmp.begin(), tmp.end());
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			A[i][j] = lower_bound(tmp.begin(), tmp.end(), A[i][j]) - tmp.begin();
	if(n > m) Solver1::Rmain();
	else Solver2::Rmain();
	cout << Ans << endl;
}
