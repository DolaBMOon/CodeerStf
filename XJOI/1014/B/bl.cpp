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

const int N=1000;
const int INF=0x3f3f3f3f3f3f3f3f;

int s,t,a,b;
int dp[N];

signed main()
{
	memset(dp,0x3f,sizeof dp);
	cin>>s>>t>>a>>b;
	dp[s]=0;
	for(int i=0;i<N;++i)
	{
		for(int j=0;j<N;++j)
		{
			if(j+a<N)
				GetMin(dp[j+a],dp[j]+1);
			if(j*b<N)
				GetMin(dp[j*b],dp[j]+1);
		}
	}
	printf("%lld\n",((dp[t]==INF)?(-1):dp[t]));
	return 0;
}
