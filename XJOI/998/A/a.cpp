#pragma GCC optimize(2)
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

#define LL long long

const int N=1e7+10;
const int D=1e7+10;
const int MOD=998244353;

LL l,r;
bool vis[N];
int p[N],totp;

void Prework()
{
	for(int i=2;i<N;++i)
	{
		if(!vis[i])
			p[++totp]=i;
		for(int j=1;j<=totp&&i*p[j]<N;++j)
		{
			vis[i*p[j]]=true;
			if(i%p[j]==0)
				break;
		}
	}
}

int f[D];

int main()
{
	Prework();
	scanf("%lld%lld",&l,&r);
	for(int i=1,t;i<=totp;++i)
	{
		t=p[i];
		for(LL j=(l-1)/t*t+t;j<=r;j+=t)if(!f[j-l]&&j!=t)
			f[j-l]=t;
	}
	LL ans=0,ans2=0;
	for(int i=0;i<=r-l;++i)
		if(f[i])
		{
			++ans;
			ans2+=f[i];
		}
	printf("%lld %lld",ans%MOD,ans2%MOD);
	return 0;
}
