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

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=10000;
const int K=22;

int n,ki,ans;

vector<Pir> G[N];

int dp[N][K],sz[N],sm[N];

void Merge(int *f,int *g)
{
	static int t[K];
	memset(t,0,sizeof t);
	for(int i=0;i<=ki;++i)
		for(int j=0;i+j<=ki;++j)
			GetMax(t[i+j],f[i]+g[j]);
	memcpy(f,t,sizeof t);
}

void Dfs(int u,int l=0,int fa=0)
{
	sz[u]=1;
	sm[u]=l;
	for(Pir p:G[u])if(p.fir!=fa)
	{
		Dfs(p.fir,p.sec,u);
		sz[u]+=sz[p.fir];
		sm[u]+=sm[p.fir];
		Merge(dp[u],dp[p.fir]);
	}
	if(sz[u]<=ki)
	{
		GetMax(dp[u][sz[u]],sm[u]);
		//cout<<u<<"!!"<<dp[u][sz[u]]<<endl;
	}
}

//void Song(int u,int fa=0)
//{
//	for(int i=0;i<=ki;++i)
//		GetMax(ans,dp[u][i]);
//	for(Pir p:G[u])if(p.fir!=fa)
//	{
//		int szu=sz[u],szv=sz[p.fir],smu=sm[u],smv=sm[p.fir];
//		sz[p.fir]+=(sz[u]-=sz[p.fir]);
//		sm[p.fir]+=(sm[u]-=sm[p.fir]+p.sec)+p.sec;
//		static int f[K],g[K];
//		memcpy(f,dp[u],sizeof f);
//		memcpy(g,dp[p.fir],sizeof g);
//	}
//}

void Work()
{
	scanf("%lld%lld",&n,&ki);
	for(int i=1;i<=n;++i)
		G[i].clear();
	int sm=0;
	for(int i=1,u,v,w;i<n;++i)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		++u;
		++v;
		sm+=w;
		G[u].emplace_back((Pir){v,w});
		G[v].emplace_back((Pir){u,w});
	}
	ans=0;
	for(int cc=min(2*n,80ll);cc--;)
	{
		int rt=rand()%n+1;
		memset(dp,0,sizeof dp);
		Dfs(rt);
		for(int i=0;i<=ki;++i)
			GetMax(ans,dp[rt][i]);
	}
	printf("%lld\n",(sm-ans)<<1);
}

signed main()
{
	int T;
	for(scanf("%lld",&T);T--;)
		Work();
	return 0;
}
