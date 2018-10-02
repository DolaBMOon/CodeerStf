#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod=1e9+7;

int n, T;
ll a[1001000], f[1001000]={1};

int main(){
	cin>>n>>T;
	for (int i=1;i<=n;++i) scanf("%lld",&a[i]);
	for (int i=1;i<=n;++i){
		f[i]=(f[i]+f[i-1]*2)%mod;
#define w(x) lower_bound(a+1,a+n+1,x)-a-1
		f[w(a[i]+n)]-=f[w(a[i]-n)];
	}
	cout<<(f[n]%mod+mod)%mod<<endl;
}
