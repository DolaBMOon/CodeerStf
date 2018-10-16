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

#define Pir pair<int,int>
#define fir first
#define sec second

int n,m,a[N],q;
int fir[N],nxt[N],to[N],tote,dfn[N],low[N],tm;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

Pir stk[N];
int tp;
vector<int> G[N];

void Dfs(int u,int fa=0)
{
	dfn[u]=low[u]=++tm;
	stk[++tp]=Pir(fa,u);
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		if(dfn[v])
			GetMin(low[u],dfn[v]);
		else
		{
			Dfs(v,u);
			if(low[v]>dfn[u])
			{
				Pir wt(u,v);
				while(stk[tp]!=wt)
				{
				}
			}
			GetMin(low[u],low[v]);
		}
	}
}

bool vis[N],gr[N];
int tp[N],dep[N];

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
	return 0;
}
