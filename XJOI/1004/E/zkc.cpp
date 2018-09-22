#include <bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define mkpr make_pair

typedef long long LL;
const int MAXN=1313;
const LL Md=1e9+9;
LL f[MAXN][MAXN], sum[MAXN], inv[MAXN];
int c[MAXN];
int n, l, m;
LL times, ans;

inline void Add(LL &x, LL y) {
	x+=y;
	if(x>=Md) x-=Md;
}

int main() {
	inv[0]=inv[1]=1;
	for(int i=2;i<=1300;++i) {
		inv[i]=inv[Md%i]*(Md-Md/i)%Md;
	}
	scanf("%d%d", &n, &l);
	for(int i=n;i;--i) {
		scanf("%d", &c[i]);
	}
	times=1;
	f[c[1]][1]=sum[1]=1;
	for(int i=2;i<=n;++i) {
		for(int j=l;j;--j) {
			LL mre=(sum[j-1]-f[c[i]][j-1]+f[c[i]][j])%Md;
			if(mre<0) mre+=Md;
			mre=mre*inv[i-1]%Md;
			Add(f[c[i]][j], mre);
			Add(sum[j], mre);
		}
		times=times*(i-1)%Md;
	}
	printf("%lld\n", sum[l]*times%Md);
	return 0;
}
