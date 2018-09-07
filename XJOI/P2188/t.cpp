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

int n,m,w[N],sm[N],cost[N][N],dp[N][N];

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
	memset(dp,0x3f,sizeof dp);
	for(int i=1;i<=n;++i)
	{
		dp[i][0]=cost[1][i];
		for(int j=2;j<=i;++j)
		{
			for(int k=1;k<=m;++k)
			{
				GetMin(dp[i][k],cost[j][i]+dp[j-1][k-1]);
				//if(i==4&&k==1&&cost[j][i]+dp[j-1][k-1]==20)
				//{
				//	cout<<j<<"!!"<<endl;
				//}
			}
		}
	}
	int ans=INF;
	for(int i=0;i<=m;++i)
		GetMin(ans,dp[n][i]);
	printf("%lld",ans);
	return 0;
}
