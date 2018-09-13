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

const int N=5200;
const int INF=0x3f3f3f3f;

int n,dp[N][N];

int main()
{
	scanf("%d",&n);
	memset(dp,0x3f,sizeof dp);
	dp[0][0]=0;
	for(int i=1,a;i<=n;++i)
	{
		scanf("%d",&a);
		for(int j=0,mn=INF;j<=a&&j<=n;++j)
		{
			if(j<a)
				dp[i][j]=dp[i-1][j]+1;
			else
				dp[i][j]=dp[i-1][j];
			GetMin(dp[i][j],mn+1+(j<a));
			mn=min(mn+1,dp[i-1][j]);
		}
		for(int j=n-1;j>=0;--j)
			GetMin(dp[i][j],dp[i][j+1]);
	}
	//Whats(dp[3][1]);
	printf("%d",dp[n][0]);
	return 0;
}
