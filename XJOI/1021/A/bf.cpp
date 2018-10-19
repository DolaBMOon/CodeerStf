#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

#define LL long long

const int N=400;
const int MOD=19260817;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int n,ki,a[N],mx,ans;
int fir[N],nxt[N<<1],to[N<<1],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int dp[N][N][N],rt;

void Merge(int f[N][N],int g[N][N])
{
	static int t[N][N];
	for(int i=0;i<=mx;++i)
		for(int j=0;j<=mx;++j)
			t[i][j]=0;
	for(int i=0;i<=mx;++i)
		for(int j=0;j<=mx;++j)if(f[i][j])
		{
			for(int a=0;a<=mx;++a)
				for(int b=0;b<=mx;++b)if(g[a][b])
					SU(t[min(i,a)][max(j,b)],Mul(f[i][j],g[a][b]));
		}
	for(int i=0;i<=mx;++i)
		for(int j=0;j<=mx;++j)
			SU(f[i][j],t[i][j]);
}

void Dfs(int u,int fa=0)
{
	dp[u][a[u]][a[u]]=1;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Dfs(v,u);
		Merge(dp[u],dp[v]);
	}
}

int main()
{
	scanf("%d%d",&n,&ki);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		GetMax(mx,a[i]);
	}
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	for(int i=1;i<=n;++i)
		for(int j=0;j+ki<=mx;++j)
			SU(ans,dp[i][j][j+ki]);
	printf("%d",ans);
	return 0;
}
