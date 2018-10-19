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

const int N=4000;
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

int n,ki,a[N],ans;
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

int dp[N][2],rt;

void Merge(int *f,int *g)
{
	int t[2]={0};
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j)
			SU(t[i|j],Mul(f[i],g[j]));
	SU(f[0],t[0]);
	SU(f[1],t[1]);
}

void Dfs(int u,int fa=0)
{
	dp[u][0]=0;
	dp[u][1]=0;
	if(a[u]>a[rt]+ki||a[u]<a[rt]||(a[u]==a[rt]&&u>rt))
		return;
	if(a[u]==a[rt]+ki)
		dp[u][1]=1;
	else
		dp[u][0]=1;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Dfs(v,u);
		Merge(dp[u],dp[v]);
	}
}

int main()
{
	freopen("lfk.in","r",stdin);
	freopen("lfk.out","w",stdout);
	scanf("%d%d",&n,&ki);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	for(int i=1;i<=n;++i)
	{
		Dfs(rt=i);
		SU(ans,dp[i][1]);
	}
	printf("%d",ans);
	return 0;
}
