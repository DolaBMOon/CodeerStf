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

const int N=18;
const int MS=(1<<N)+10;

int n,m,k,S;
int cnt[MS],rem[MS],dp[MS],bel[MS];
bool he[N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	S=(1<<n)-1;
	for(int i=0,x;i<m;++i)
	{
		scanf("%d",&x);
		rem[S^x]|=x;
	}
	for(int i=S;i>=1;--i)
		for(int j=0;j<n;++j)if((i>>j)&1)
			rem[i^(1<<j)]|=rem[i];
	for(int i=1;i<=S;++i)
		cnt[i]=cnt[i^(i&(-i))]+1;
	for(int i=0;i<n;++i)
		if((k>>(n-i-1))&1)
			he[i]=true;
	memset(dp,-1,sizeof dp);
	dp[0]=0;
	for(int i=1;i<=S;++i)
	{
		if(he[cnt[i]-1])
		{
			for(int j=0;j<n;++j)
				if(((i>>j)&1)&&~dp[i^(1<<j)])
				{
					dp[i]=j;
					break;
				}
		}
		else
		{
			for(int j=0;j<n;++j)
				if(((i>>j)&1)&&~dp[i^(1<<j)]&&!((rem[i^(1<<j)]>>j)&1))
				{
					dp[i]=j;
					break;
				}
		}
	}
	//Whats(cnt[4]);
	//Whats(rem[0]);
	//Whats(dp[4]);
	if(dp[S]==-1)
	{
		puts("-1");
		return 0;
	}
	int nw=S;
	for(;nw;nw^=1<<dp[nw])
	{
		int t=dp[nw],v=he[cnt[nw]-1];
		for(int i=1;i<=S;++i)if((i>>t)&1)
			bel[i]=v;
	}
	for(int i=1;i<=S;++i)
		printf("%d",bel[i]);
	return 0;
}
