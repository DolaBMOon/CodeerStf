#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

const int N=30;
const int L=50;
const int AL=55;
const int MOD=1e9+7;
const int C=21600;

int Mul(int x,int y)
{
	return (long long)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(long long)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

long long Gcd(long long x,long long y)
{
	return y?Gcd(y,x%y):x;
}

int n,len[N],ans[N];
bool mp[N][AL],vis[AL];
int ch[C][AL][AL];

void Solve(int ch[AL][AL])
{
	static int f[N],g[N];
	memset(f,0,sizeof f);
	f[0]=1;
	for(int i=1;i<=L;++i)if(vis[i])
	{
		memset(g,0,sizeof g);
		for(int j=0;j<=n;++j)if(f[j])
			for(int k=0;k<i;++k)
				SU(g[j+ch[i][k]],f[j]);
		memcpy(f,g,sizeof f);
	}
	for(int i=1;i<=n;++i)
		SU(ans[i],f[i]);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		static char s[L+1];
		scanf("%d%s",len+i,s);
		for(int j=0;j<len[i];++j)
			mp[i][j]=(s[j]=='O');
	}
	for(int i=0;i<n;++i)
	{
		int k=len[i]/Gcd(len[i],C);
		if(k==7)
			k=k*k;
		vis[k]=true;
		for(int j=0;j<k*C;++j)
			ch[j%C][k][j/C]+=mp[i][j%len[i]];
	}
	for(int i=0;i<C;++i)
		Solve(ch[i]);
	long long lcm=1;
	for(int i=1;i<=L;++i)if(vis[i])
		lcm=lcm/Gcd(lcm,(long long)i)*i;
	int mu=Qpow(Mul(C,lcm%MOD));
	for(int i=2;i<=50;++i)
		SMul(mu,i);
	for(int i=1;i<=n;++i)
		printf("%d\n",Mul(ans[i],mu));
	return 0;
}
