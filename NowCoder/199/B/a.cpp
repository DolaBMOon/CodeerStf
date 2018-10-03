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

#define LL long long

const int MOD=1e9+7;
const int N=1e5+10;

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

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

int n,l,r;
int fir[N],nxt[N],to[N],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int dep[N],sz[N],ans;

void Song1(int u,int fa=0)
{
	sz[u]=1;
	dep[u]=dep[fa]+1;
	int tmp=0;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Dfs(v,u);
		sz[u]+=sz[v];
	}
}

void Song2(int u,int fa=0)
{
}

int main()
{
	scanf("%d%d%d",&n,&l,&r);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	printf("%d",ans);
	return 0;
}
