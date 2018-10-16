#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cassert>
#include<queue>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<"<<<<<<<<<<"endl
#define Divher() cout<<">>>>>>>>>>"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return (a<=b)?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return (a>=b)?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=200000+10;

struct Heap
{

	priority_queue<int,vector<int>,greater<int> > P,Q;

	void Push(int x)
	{
		Q.push(x);
	}

	void Del(int x)
	{
		P.push(x);
	}

	void Shrink()
	{
		while(!P.empty()&&P.top()==Q.top())
		{
			P.pop();
			Q.pop();
		}
	}

	int Top()
	{
		Shrink();
		return Q.top();
	}

}H[N];

int n,m,a[N],q;
int fir[N],nxt[N],to[N],tote,dfn[N],low[N],tm,col[N],cnt,fa[N];

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

void Dfs(int u)
{
	dfn[u]=low[u]=++tm;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u])
	{
		if(dfn[v])
			GetMin(low[u],dfn[v]);
		else
		{
			fa[v]=u;
			Dfs(v);
			GetMin(low[u],low[v]);
		}
	}
	if(dfn[u]==low[u])
		col[u]=++cnt;
}

bool vis[N],gr[N];
int tp[N],dep[N];

void Song(int u)
{
	vis[u]=true;
	if(!col[u])
		col[u]=col[fa[u]];
	else
	{
		gr[u]=true;
		tp[col[u]]=col[fa[u]];
		dep[col[u]]=dep[col[fa[u]]]+1;
	}
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u]&&!vis[v])
		Song(v);
}

int Run(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	int res=min(H[x].Top(),H[y].Top());
	while(dep[x]>dep[y])
		GetMin(res,H[x=tp[x]].Top());
	while(x!=y)
	{
		GetMin(res,H[x=tp[x]].Top());
		GetMin(res,H[y=tp[y]].Top());
	}
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	Song(1);
	for(int i=1;i<=n;++i)
		H[col[i]].Push(a[i]);
	scanf("%d",&q);
	char s[3];
	for(int i=1,u,v;i<=q;++i)
	{
		scanf("%s%d%d",s,&u,&v);
		if(*s=='Q')
			printf("%d\n",a[u]-Run(col[u],col[v]));
		else
		{
			H[col[u]].Del(a[u]);
			H[col[u]].Push(a[u]=v);
		}
	}
	return 0;
}
