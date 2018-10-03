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

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(LL)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

int n;
vector<int> G[N];
int dp[N],ans[N];

void Song(int u,int fa=0)
{
	dp[u]=1;
	for(int v:G[u])if(v!=fa)
	{
		Song(v,u);
		SMul(dp[u],U(1,dp[v]));
	}
}

void Dfs(int u,int fa=0)
{
	ans[u]=dp[u];
	for(int v:G[u])if(v!=fa)
	{
		int k=U(1,dp[v]);
		SMul(dp[u],Qpow(k));
		int t=U(1,dp[u]);
		SMul(dp[v],t);
		Dfs(v,u);
		SMul(dp[v],Qpow(t));
		SMul(dp[u],k);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	Song(1);
	Dfs(1);
	for(int i=1;i<=n;++i)
		printf("%d\n",ans[i]);
	return 0;
}
