#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

const int N=1e6+10;
const int MOD=1e9+7;

void SU(int &a,int b)
{
	((a+=b)>=MOD)?(a-=MOD):0;
}

LL Gcd(LL a,LL b)
{
	return b?Gcd(b,a%b):a;
}

int n,p[N],cnt[N],dp[N];
LL a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=2;i<=n;++i)
		scanf("%d",p+i);
	for(int i=n;i>1;--i)
		a[p[i]]+=a[i];
	for(int i=1;i<=n;++i)
	{
		LL k=a[1]/Gcd(a[1],a[i]);
		if(k<=n)
			++cnt[k];
	}
	for(int i=n;i>=1;--i)
		for(int j=i+i;j<=n;j+=i)
			cnt[j]+=cnt[i];
	//for(int i=1;i<=n;++i)
	//	cout<<i<<":"<<cnt[i]<<endl;
	int ans=1;
	for(int i=n;i>=2;--i)if(cnt[i]==i)
	{
		++dp[i];
		for(int j=i+i;j<=n;j+=i)
			SU(dp[i],dp[j]);
		SU(ans,dp[i]);
	}
	printf("%d",ans);
	return 0;
}
