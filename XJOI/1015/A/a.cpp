#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

const int K=23333;
const int N=55;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,k,a[N],b[N],sm[N],c[N],dp[K],totc;

int Song(int *a,int t)
{
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	for(int i=1;i<=n;++i)
		for(int j=t;j>=0;--j)
			GetMin(dp[min(t,j+a[i])],dp[j]+c[i]);
	return dp[t];
}

signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",b+i);
		sm[i]+=a[i]+b[i];
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",c+i);
		totc+=c[i];
	}
	for(int i=1;i<=n;++i)
	{
		--a[i];
		--b[i];
	}
	int ans=min(min(Song(a,k),Song(b,k)),Song(sm,2*k-1));
	printf("%lld\n",((ans<=totc)?ans:-1));
	return 0;
}
