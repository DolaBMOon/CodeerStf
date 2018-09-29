#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<unordered_map>

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

const int N=1e5+10;

int n,d[N],id[N],sz[N],fa[N],dp[N];
unordered_map<int,int> re;

bool Cmp(int x,int y)
{
	return d[x]>d[y];
}

signed main()
{
	scanf("%lld",&n);
	if(n==2)
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",d+i);
		re[d[i]]=i;
	}
	for(int i=1;i<=n;++i)
	{
		id[i]=i;
		sz[i]=1;
	}
	sort(id+1,id+n+1,Cmp);
	for(int i=1,u,v,x;i<n;++i)
	{
		re[d[u=id[i]]]=0;
		if((x=sz[u]+sz[u]-n)>=0||!(v=re[d[u]+x]))
		{
			puts("-1");
			return 0;
		}
		sz[fa[u]=v]+=sz[u];
		dp[fa[u]]+=dp[u]+sz[u];
	}
	if(dp[id[n]]!=d[id[n]])
	{
		puts("-1");
		return 0;
	}
	for(int i=1;i<=n;++i)
		if(fa[i])
			printf("%lld %lld\n",fa[i],i);
	return 0;
}
