#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> bool GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */

#define int long long

const int N=233;
const int SX=2333+10;
const int MOD=1e9+7;

int n,x[N],y[N],C[SX][SX],jc[SX],njc[SX];
int f[SX],g[SX];

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=x*x%MOD)if(y&1)
		res=res*x%MOD;
	return res;
}

void Prework()
{
	for(int i=0;i<SX;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			if((C[i][j]=C[i-1][j-1]+C[i-1][j])>=MOD)
				C[i][j]-=MOD;
	}
	jc[0]=1;
	for(int i=1;i<SX;++i)
		jc[i]=jc[i-1]*i%MOD;
	njc[SX-1]=Qpow(jc[SX-1]);
	for(int i=SX-2;i>=0;--i)
		njc[i]=njc[i+1]*(i+1)%MOD;
}

signed main()
{
	Prework();
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",x+i);
	for(int i=1;i<=n;++i)
		scanf("%lld",y+i);
	f[0]=1;
	for(int k=1;k<=n;++k)
	{
		memset(g,0,sizeof g);
		for(int i=x[k];i<SX;++i)
			g[i]=f[i-x[k]];
		memset(f,0,sizeof f);
		for(int i=0;i<=y[k];++i)
			for(int j=i;j<SX;++j)if(g[j])
				if((f[j-i]+=g[j]*C[j][i]%MOD)>=MOD)
					f[j-i]-=MOD;
	}
	int sm=0;
	for(int i=1;i<=n;++i)
		sm+=x[i];
	int ans=f[0]*jc[sm]%MOD;
	for(int i=1;i<=n;++i)
		ans=ans*njc[x[i]]%MOD;
	printf("%lld",ans);
	return 0;
}
