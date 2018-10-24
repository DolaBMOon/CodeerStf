#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

#define LL long long

const int N=3333;

int n,p,q,rt,ms[N],mxd[N];
vector<int> G[N];

void Song(int u,int fa=0)
{
	ms[u]=mxd[u]=0;
	for(int v:G[u])if(v!=fa)
	{
		Song(v,u);
		if(GetMax(mxd[u],mxd[v]+1))
			ms[u]=v;
	}
}

int dp[N<<1];

LL res[N],sm,ans;

void Dfs(int u,int fa=0,int *f=dp)
{
	f[0]=1;
	res[u]=0;
	if(!ms[u])
		return;
	Dfs(ms[u],u,f+1);
	if(q<=mxd[u])
		res[u]=f[q];
	for(int v:G[u])if(v!=fa&&v!=ms[u])
	{
		int *g=f+mxd[u]+1;
		Dfs(v,u,g);
		for(int i=0,j;i<=mxd[v];++i)
		{
			if(0<=(j=q-i-1)&&j<=mxd[u])
				res[u]+=f[j]*g[i];
		}
		for(int i=0;i<=mxd[v];++i)
			f[i+1]+=g[i];
	}
}

void Dfs2(int u,int fa=0,int dep=0)
{
	sm-=res[u];
	if(dep==p)
		ans+=sm;
	else
	{
		for(int v:G[u])if(v!=fa)
			Dfs2(v,u,dep+1);
	}
	sm+=res[u];
}

int main()
{
	scanf("%d%d%d",&n,&p,&q);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for(rt=1;rt<=n;++rt)
	{
		Song(rt);
		Dfs(rt);
		sm=0;
		for(int i=1;i<=n;++i)
			sm+=res[i];
		Dfs2(rt);
	}
	ans<<=1;
	printf("%lld",ans);
	return 0;
}
