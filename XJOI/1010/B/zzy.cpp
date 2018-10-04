#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#include<bits/stdc++.h>
using namespace std;

#define ll long long
const int mod=1e9+7;

ll K(ll x,ll y=mod-2){
	ll t=1;
	for (;y;y>>=1,x=x*x%mod)
		if (y&1) t=t*x%mod;
	return t;
}

int lcm(int x,int y){
	return x*y/__gcd(x,y);
}

int T, n, s[55][55], np[55], zeta=21600*7;
char ss[55];
int a[55][1600000], l[55], f[444][33], g[444][33], ans[33];

void Ua(int &x,int y){
	x=(x+y)%mod;
}

int main(){
	cin>>T;
	for (int cas=1;cas<=T;++cas){
		cin>>n>>ss;
		for (int i=0;i<n;++i)
			s[n][i]+= ss[i]=='O';
	}
	for (int i=2;i<=50;++i)
		if (!np[i]){
			if (i<=5) np[i]=1;
			for (int j=i+i;j<=50;j+=i)
				np[j]=1;
		}
	l[1]=zeta;
	for (int i=7;i<=50;++i)
		if (!np[i]){
			l[i]= i==7? i*i: i;
			for (int j=1;j<=7;++j)
				l[i]=lcm(l[i],j);
		}
	for (int i=1;i<=50;++i){
		int b=0;
		if (zeta%i==0) b=1;
		else {
			for (int j=7;j<=50;++j)
				if (!np[j]&&i%j==0) b=j;
		}
		for (int j=0;j<l[b];++j){
			a[b][j]+=s[i][j%i];
		}
	}
	/*
		 for (int i=1;i<=50;++i)
		 if (!np[i]){
		 printf(" %d : %d\n",i,l[i]);
		 for (int j=0;j<10;++j) printf("%d",a[i][j]); puts("");
		 }
	 */
	for (int i=0;i<420;++i) f[i][0]=1;
	for (int w=1;w<=50;++w)
		if (!np[w]){
			memset(g,0,sizeof g);
			for (int i=0;i<l[w];++i)
				for (int j=0;j<=T;++j)
					Ua(g[i%420][j+a[w][i]],f[i%420][j]);
			swap(f,g);
		}

	for (int i=0;i<420;++i)
		for (int j=0;j<=T;++j)
			Ua(ans[j],f[i][j]);
	// cout<<' '<<ans[1]<<endl;

	ll fix=1;
	for (int i=1;i<=50;++i) fix=fix*i%mod;
	//cout<<fix<<endl;
	for (int i=1;i<=50;++i)
		if (!np[i]){
			fix=fix*K(l[i]/420)%mod;
		}
	fix=fix*K(420)%mod;
	//cout<<fix<<endl;
	/*
		 ll t=1;
		 for (int i=1;i<=50;++i)
		 if (!np[i]) t=t*l[i]/420%mod;
		 cout<<t*420%mod<<' '<<ans[0]<<endl;
	 */
	for (int i=1;i<=T;++i)
		printf("%lld\n",ans[i]*fix%mod);
}
