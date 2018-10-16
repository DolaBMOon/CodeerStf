#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<"<<<<<<<<<<"endl
#define Divher() cout<<">>>>>>>>>>"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return (a<=b)?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return (a>=b)?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

#define int long long

const int N=233;
const int K=111;

int n,ki,a[N],v[N],w,dp[N],q;

void Upd(int a,int v)
{
	if(!a)
		return;
	for(int i=n;i>=0;--i)
		for(int j=i-a,k=v;j>=0;--j,k+=v)
			GetMin(dp[i],dp[j]+k+w);
}

int ban[K][N];

signed main()
{
	scanf("%lld%lld%lld",&n,&ki,&w);
	for(int i=1;i<=ki;++i)
		scanf("%lld%lld",a+i,v+i);
	scanf("%lld",&q);
	for(int i=1,x,k;i<=q;++i)
	{
		scanf("%lld%lld",&x,&k);
		++ban[k][x];
	}
	for(int i=1;i<=ki;++i)
		for(int j=1;j<=n;++j)
			ban[i][j]+=ban[i][j-1];
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=ki;++j)
			for(int p=i-a[j],fee=v[j]+w;p>=0&&!(ban[j][i]-(p?ban[j][p-1]:0));p-=a[j],fee+=v[j])
				GetMin(dp[i],dp[p]+fee);
	printf("%lld",dp[n]-w);
	return 0;
}
