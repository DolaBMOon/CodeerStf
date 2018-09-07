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

/*
-<Unlimited Blade Works>-
*/

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2333;
const int INF=0x3f3f3f3f3f3f3f3f;

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

int n,m,w[N],sm[N],cost[N][N],ans=INF;
Pir dp[N];

bool Check(int d)
{
	for(int i=1;i<=n;++i)
	{
		dp[i]=Pir(cost[1][i],0);
		for(int j=2;j<=i;++j)
		{
			Pir t=dp[j-1];
			t.fir+=cost[j][i]+d;
			t.sec+=1;
			GetMin(dp[i],t);
		}
	}
	if(dp[n].sec<=m)
	{
		GetMin(ans,dp[n].fir-dp[n].sec*d);
		return true;
	}
	return false;
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",w+i);
		sm[i]=w[i]+sm[i-1];
	}
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			cost[i][j]=cost[i][j-1]+w[j]*(sm[j-1]-sm[i-1]);
	int left=0,mid,right=INF;
	while(left<=right)
	{
		mid=(left+right)>>1;
		if(Check(mid))
			right=mid-1;
		else
			left=mid+1;
	}
	printf("%lld",ans);
	return 0;
}
