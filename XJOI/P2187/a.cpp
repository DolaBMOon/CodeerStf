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

/*
-<Unlimited Blade Works>-
*/

#define Tp template
#define Ty typename

const int N=100000+10;
const int M=400000+10;

Tp<Ty T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

int n,m;
int fir[N],nxt[M],to[M],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int ans,dfn[N],low[N],dfstime;

void Dfs(int u,int fa=0)
{
	dfn[u]=low[u]=++dfstime;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		if(dfn[v])
			GetMin(low[u],dfn[v]);
		else
		{
			Dfs(v,u);
			GetMin(low[u],low[v]);
		}
	}
	if(fa&&dfn[u]==low[u])
		++ans;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	printf("%d",ans);
	return 0;
}
