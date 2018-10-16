#include<bits/stdc++.h>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<"<<<<<<<<<<"<<endl
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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=400000+10;
const int INF=0x3f3f3f3f;

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

	int Top()
	{
		while(!P.empty()&&P.top()==Q.top())
		{
			P.pop();
			Q.pop();
		}
		return Q.top();
	}

}H[N];

int n,m,a[N],q,cnt;

struct Graph
{

	int fir[N],nxt[N],to[N],tote,dfn[N],low[N],dfstime;

	void Adde(int u,int v)
	{
		//cout<<u<<","<<v<<endl;
		to[++tote]=v;
		nxt[tote]=fir[u];
		fir[u]=tote;
		to[++tote]=u;
		nxt[tote]=fir[v];
		fir[v]=tote;
	}

}A,B;

int stk[N],tp,dfn[N],low[N],dfstime;

void Tarjan(int u,int fa=0)
{
	dfn[u]=low[u]=++dfstime;
	stk[++tp]=u;
	for(int i=A.fir[u],v;i;i=A.nxt[i])if((v=A.to[i])!=fa)
	{
		if(dfn[v])
			GetMin(low[u],dfn[v]);
		else
		{
			Tarjan(v,u);
			if(low[v]>=dfn[u])
			{
				++cnt;
				for(int nw=-1;nw!=v;)
				{
					nw=stk[tp--];
					B.Adde(nw,cnt);
				}
				B.Adde(u,cnt);
			}
			GetMin(low[u],low[v]);
		}
	}
}

int dep[N],fa[N];

void Dfs(int u)
{
	dep[u]=dep[fa[u]]+1;
	for(int i=B.fir[u],v;i;i=B.nxt[i])if((v=B.to[i])!=fa[u])
	{
		fa[v]=u;
		Dfs(v);
	}
}

int Get(int u)
{
	if(u>n)
		return H[u].Top();
	else
		return a[u];
}

void Que()
{
	int x,y;
	scanf("%d%d",&x,&y);
	int rec=a[x],res=min(Get(x),Get(y));
	if(dep[x]<dep[y])
		swap(x,y);
	for(;dep[x]>dep[y];GetMin(res,Get(x=fa[x])));
	for(;x!=y;GetMin(res,min(Get(x=fa[x]),Get(y=fa[y]))));
	if(x>n)
		GetMin(res,a[fa[x]]);
	printf("%d\n",rec-res);
}

void Chg()
{
	int u,x;
	scanf("%d%d",&u,&x);
	if(fa[u]>n)
	{
		H[fa[u]].Del(a[u]);
		H[fa[u]].Push(x);
	}
	a[u]=x;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		A.Adde(u,v);
	}
	cnt=n;
	Tarjan(1);
	Dfs(1);
	for(int i=1;i<=n;++i)
		H[fa[i]].Push(a[i]);
	scanf("%d",&q);
	char s[3];
	for(int i=1;i<=q;++i)
	{
		scanf("%s",s);
		if(*s=='Q')
			Que();
		else
			Chg();
	}
	return 0;
}
