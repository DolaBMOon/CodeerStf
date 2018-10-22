#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

#define LL long long

const int N=5200;
const int MOD=1e9+9;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(LL)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int Sqr(int x)
{
	return (LL)x*x%MOD;
}

int Qpow(int x,int y)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

int Sig(int n)
{
	return (LL)(1+n)*n/2%MOD;
}

int n,p[N],sm;
int ans,jc[N],C[N][N],G[N];

int Calc(int x,int y)
{
	int res=0;
	if(x>y)
	{
		//a!=y&&b!=x
		SU(res,Mul(G[n-4],D(sm,D(U(U(Sig(x-1),Sig(y-1)),U(Sig(n-x),Sig(n-y))),x-y))));
		//a==y&&b==x
		//res+=0;
		//a==y&&b!=x
		SU(res,Mul(G[n-3],Sig(y-1)));
		//a!=y&&b==x
		SU(res,Mul(G[n-3],Sig(n-x)));
	}
	else
	{
		//a!=y&&b!=x
		SU(res,Mul(G[n-4],D(sm,D(U(U(Sig(x-1),Sig(y-1)),U(Sig(n-x),Sig(n-y))),y-x))));
		//a==y&&b==x
		SU(res,Mul(G[n-2],y-x));
		//a==y&&b!=x
		SU(res,Mul(G[n-3],D(Sig(y-1),y-x)));
		//a!=y&&b==x
		SU(res,Mul(G[n-3],D(Sig(n-x),y-x)));
	}
	return res;
}

int Fl(int x)
{
	return (x&1)?(MOD-1):1;
}

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=Mul(jc[i-1],i);
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=U(C[i-1][j],C[i-1][j-1]);
	}
	for(int i=0;i<=n-2;++i)
	{
		for(int j=0;j<=i;++j)
		{
			if(j&1)
				SD(G[i],Mul(C[i][j],jc[n-2-j]));
			else
				SU(G[i],Mul(C[i][j],jc[n-2-j]));
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			SU(sm,j-i);
}

namespace Brute
{

	int a[N];

	void Force()
	{
		for(int i=1;i<=n;++i)
			a[i]=i;
		int ans=0;
		do
		{
			bool fl=true;
			for(int i=1;i<=n;++i)
				fl&=(a[i]!=p[i]);
			if(!fl)
				continue;
			for(int i=1;i<=n;++i)
				for(int j=i+1;j<=n;++j)if(a[i]>a[j])
					SU(ans,Mul(j-i,D(a[i],a[j])));
		}
		while(next_permutation(a+1,a+n+1));
		printf("%d",ans);
	}

}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",p+i);
	if(n<=4)
	{
		Brute::Force();
		return 0;
	}
	Prework();
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			SU(ans,Mul(j-i,Calc(p[i],p[j])));
	printf("%d",ans);
	return 0;
}
