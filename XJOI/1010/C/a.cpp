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

const int MOD=1e9+7;

int Mul(int x,int y)
{
	return x*y%MOD;
}

void SMul(int &x,int y)
{
	x=x*y%MOD;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

#define Pir pair<int,int>
#define fir first
#define sec second

bool Cmp(const Pir &a,const Pir &b)
{
	return a.sec<b.sec;
}

const int N=1e6+10;
const int LG=21;

int n,rt[N],lc[LG*N],rc[LG*N],sm[LG*N];
Pir p[N];

void GetHer(int a,int b)
{
}

signed main()
{
	scanf("%lld%*d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",&p[i].fir);
		p[i].sec=p[i].fir+n;
	}
	sort(p+1,p+n+1,Cmp);
	for(int i=1;i<=n;++i)
	{
		int x=0;
		for(int l=1,md,r=i-1;l<=r;)
		{
			if(p[md=(l+r)>>1].sec<p[i].fir)
				l=(x=md)+1;
			else
				r=md-1;
		}
		GetHer(x,i);
	}
	return 0;
}
