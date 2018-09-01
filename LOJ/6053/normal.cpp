#include<algorithm>
#include<cstring>
#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

#define int long long

const int MX=200000+10;
const int MOD=1e9+7;

int n,m,B,p[MX],s[MX],totp,w[MX],g[MX],h[MX],id[MX],id2[MX];
bool vis[MX];

void Prework()
{
	for(int i=2;i<=B;++i)
	{
		if(!vis[i])
		{
			p[++totp]=i;
			s[totp]=s[totp-1]+i;
		}
		for(int j=1;j<=totp&&p[j]*i<=B;++j)
		{
			vis[p[j]*i]=true;
			if(!(i%p[j]))
				break;
		}
	}
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):((x<0)?(x+MOD):x);
}

void SU(int& x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):((x<0)?(x+=MOD):0);
}

int F(int x,int y)
{
	if(x<=1||p[y]>x)
		return 0;
	int k=(x<B)?id[x]:id2[n/x],ans=U(0,(g[k]-s[y-1]-(h[k]-(y-1))+(y==1)*2)%MOD);
	for(int i=y;i<=totp&&p[i]*p[i]<=x;++i)
	{
		int t=p[i],t2=p[i]*p[i];
		for(int e=1;t2<=x;++e,t=t2,t2=t2*p[i])
			SU(ans,U(F(x/t,i+1)*(p[i]^e)%MOD,(p[i]^(e+1))%MOD));
	}
	return ans;
}

signed main()
{
	scanf("%lld",&n);
	B=sqrt(n);
	Prework();
	for(int i=1,last;i<=n;i=last+1)
	{
		last=n/(n/i);
		w[++m]=n/i;
		h[m]=U(w[m]%MOD,-1);
		g[m]=U((w[m]&1)?(((w[m]+1)>>1)%MOD*(w[m]%MOD)%MOD):((w[m]>>1)%MOD*((w[m]+1)%MOD)%MOD),MOD-1);
		if(n/i<B)
			id[n/i]=m;
		else
			id2[last]=m;
	}
	Whats(g[1]);
	for(int j=1;j<=totp;++j)
		for(int i=1,t,ii=p[j]*p[j];i<=m&&w[i]>=ii;++i)
		{
			int k=((t=w[i]/p[j])<B)?id[t]:id2[n/t];
			SU(h[i],-(h[k]-j+1)%MOD);
			SU(g[i],-p[j]*(g[k]-s[j-1])%MOD);
		}
	Whats(h[1]);
	Whats(g[1]);
	printf("%lld\n",U(F(n,1),1));
	return 0;
}
