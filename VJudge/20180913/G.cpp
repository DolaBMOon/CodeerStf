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

#define Pir pair<int,int>
#define fir first
#define sec second

const int MOD=1e9+7;
const int N=5000000+10;

int n,k;
Pir p[N];
int ls[N],ed;

int A[N];

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

int jc[N],njc[N];

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=Mul(jc[i-1],i);
	njc[n]=Qpow(jc[n]);
	for(int i=n-1;i>=0;--i)
		njc[i]=Mul(njc[i+1],i+1);
}

int C(int n,int m)
{
	if(m>n)
		return 0;
	return jc[n]*njc[m]%MOD*njc[n-m]%MOD;
}

signed main()
{
	scanf("%lld%lld",&n,&k);
	Prework();
	for(int i=1;i<=n;++i)
	{
		scanf("%lld%lld",&p[i].fir,&p[i].sec);
		++p[i].sec;
		ls[++ed]=p[i].fir;
		ls[++ed]=p[i].sec;
	}
	sort(ls+1,ls+ed+1);
	ed=unique(ls+1,ls+ed+1)-ls-1;
	for(int i=1;i<=n;++i)
	{
		//Whats(lower_bound(ls+1,ls+ed+1,p[i].fir)-ls);
		++A[lower_bound(ls+1,ls+ed+1,p[i].fir)-ls];
		//Whats(lower_bound(ls+1,ls+ed+1,p[i].sec)-ls);
		--A[lower_bound(ls+1,ls+ed+1,p[i].sec)-ls];
	}
	int ans=0;
	for(int i=1;i<ed;++i)
	{
		A[i]+=A[i-1];
		ans=ans+C(A[i],k)*(ls[i+1]-ls[i])%MOD;
		//cout<<ls[i]<<","<<ls[i+1]<<":"<<A[i]<<endl;
		if(ans>=MOD)
			ans-=MOD;
	}
	printf("%lld",ans);
	return 0;
}
