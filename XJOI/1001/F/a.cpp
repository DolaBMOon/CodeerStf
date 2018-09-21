#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

#define int long long

const int N=14;
const int MS=(1<<N)+10;

int n,S,G[N];
int dp[MS][N],t[N],jc[N+1];

signed main()
{
	scanf("%lld",&n);
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=jc[i-1]*i;
	S=(1<<n)-1;
	for(int i=0;i<n;++i)
	{
		static char s[20];
		scanf("%s",s);
		for(int j=0;j<n;++j)
			if(s[j]=='Y')
				G[i]^=(1<<j);
	}
	for(int k=0,cnt;k<=S;++k)
	{
		for(int i=0;i<n;++i)if((k>>i)&1)
		{
			int g=0;
			for(int j=0;j<n;++j)if((G[i]>>j)&1)
				g+=dp[k^(1<<i)][j];
			dp[k][i]+=g;
			for(int i=2;i<n;++i)
			{
				g=0;
				for(int t=k^(k&(-k)),j=t;j;j=(j-1)&t)
					g+=f*dp[j][1];
			}
		}
	}
	return 0;
}
