%:pragma GCC target("avx")
%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")
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

#define int long long

const int MOD=1e9+9;
const int MOD2=MOD*MOD;
const int N=1300;

int Mul(int x,int y)
{
	return x*y%MOD;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

void SU2(int &x,int y)
{
	((x+=y)>=MOD2)?(x-=MOD2):0;
}

int n,l,c[N],jc[N],njc[N],dp[N][N];

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=Mul(jc[i-1],i);

	njc[n]=Qpow(jc[n]);
	for(int i=n-1;i>=0;--i)
		njc[i]=Mul(njc[i+1],i+1);
}

signed main()
{
	scanf("%lld%lld",&n,&l);
	Prework();
	for(int i=1;i<=n;++i)
		scanf("%lld",c+i);
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int *j=dp[i-1]+(i>1),k=jc[n-i];*j;++j)
			*j=Mul(*j,k);
		for(int j=0,d,f=njc[n-i];j<i;++j)
		{
			d=(c[j]!=c[i]);
			for(int k=(j>0),t;k+d<=l&&(t=dp[j][k]);++k)
				SU2(dp[i][k+d],t*f);
		}
		for(int j=0;j<=l;++j)
			dp[i][j]%=MOD;
	}
	printf("%lld\n",dp[n][l]);
	return 0;
}
