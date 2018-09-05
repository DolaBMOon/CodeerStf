%:pragma GCC optimize("Ofast")
%:pragma GCC target("sse3","sse2","sse")
%:pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
%:pragma GCC target("f16c")
%:pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
%:pragma GCC diagnostic error "-fwhole-program"
%:pragma GCC diagnostic error "-fcse-skip-blocks"
%:pragma GCC diagnostic error "-funsafe-loop-optimizations"
%:pragma GCC diagnostic error "-std=c++14"

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=5200;
const int MOD=1e9+7;

int Mul(int a,int b)
{
	unsigned long long x=(long long)a*b;
	unsigned xh=(unsigned)(x>>32),xl=(unsigned)x,d,m;
	asm
		(
		 "divl %4;\n\t"
		 :"=a"(d),"=d"(m)
		 :"d"(xh),"a"(xl),"r"(MOD)
		);
	return m;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int& x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int& x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int n;
vector<int> G[N];

int sz[N],dp[N][N],cm[N];

void Dfs(int u,int fa=0)
{
	sz[u]=dp[u][1]=1;
	for(int v:G[u])if(v!=fa)
	{
		Dfs(v,u);
		int sm=0;
		for(int i=2;i<=sz[v];i+=2)
			SD(sm,Mul(dp[v][i],cm[i>>1]));
		static int x[N];
		int s=sz[u]+sz[v];
		for(int i=sz[u];i;--i)
			x[i]=Mul(dp[u][i],sm);
		for(int i=sz[u]+1;i<=s;++i)
			x[i]=0;
		for(int i=sz[u];i;--i)
			for(int j=sz[v];j;--j)
				SU(x[i+j],Mul(dp[u][i],dp[v][j]));
		for(int i=s;i;--i)
			dp[u][i]=x[i];
		sz[u]=s;
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

	cm[1]=1;
	for(int i=2;i<=n;++i)
		cm[i]=Mul(cm[i-1],(i<<1)-1);

	Dfs(1);

	int ans=0;
	for(int i=2;i<=n;i+=2)
		SU(ans,Mul(dp[1][i],cm[i>>1]));
	printf("%d",ans);
	return 0;
}
