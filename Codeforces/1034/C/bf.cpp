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

int n,p[N],cnt[N],dp[N];
LL a[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=2;i<=n;++i)
		scanf("%d",p+i);
	for(int i=n;i>=2;--i)
		a[p[i]]+=a[i];
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			++cnt[i];
		}
	}
	return 0;
}
