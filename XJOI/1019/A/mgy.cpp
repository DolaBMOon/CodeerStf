/*program by mangoyang*/
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define inf (0x7f7f7f7f)
#define Max(a, b) ((a) > (b) ? (a) : (b))
#define Min(a, b) ((a) < (b) ? (a) : (b))
typedef long long ll;
using namespace std;
template <class T>
inline void read(T &x){
	int f = 0, ch = 0; x = 0;
	for(; !isdigit(ch); ch = getchar()) if(ch == '-') f = 1;
	for(; isdigit(ch); ch = getchar()) x = x * 10 + ch - 48;
	if(f) x = -x;
}
const int N = 1005;
int f[N][N], b[N][N], a[N], v[N], n, m, w;
inline void update(int &x, int y){ if(y < x) x = y; }
int main(){
	read(n), read(m), read(w);
	for(int i = 1; i <= m; i++) read(a[i]), read(v[i]);
	int q; read(q);
	for(int i = 1, x, y; i <= q; i++){
		read(x), read(y);
		for(int j = x; j <= n; j++) b[j][y]++;
	}
	memset(f, 127, sizeof(f)), f[0][0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = 0; j <= m; j++) if(f[i][j] < inf){
			for(int k = 1; k <= m; k++){
				int nxt = i + a[k];
				if(i + a[k] > n) continue;
				int tmp = i == 0 ? b[nxt][k] : b[nxt][k] - b[i-1][k];
				if(tmp) continue;
				update(f[nxt][k], f[i][j] + v[k] + (j == k ? 0 : w));
			}
		}
	int ans = inf;
	for(int i = 1; i <= m; i++) update(ans, f[n][i]);
	if(ans == inf) puts("-1"); else cout << ans - w;
	return 0;
}
