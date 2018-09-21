#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<queue>

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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=5000;
const int INF=0x3f3f3f3f;
const int S=N-1;
const int T=N-2;

int n,tm,p[N];
int fir[N],nxt[N],to[N],tote;
bool ban[N];

void Adde(int u,int v)
{
	to[++tote]=fir[u];
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=fir[v];
	nxt[tote]=fir[v];
	fir[v]=tote;
}

namespace Flower
{

	int TT=N-3;

	struct Edge
	{
		int v,cap,cost;
	}edges[N];

	int fir[N],nxt[N],tote=1;

	void Adde(int u,int v,int cap,int cost)
	{
		edges[++tote]=(Edge){v,cap,cost};
		nxt[tote]=fir[u];
		fir[u]=tote;
		edges[++tote]=(Edge){u,cap,cost};
		nxt[tote]=fir[v];
		fir[v]=tote;
	}
	
	bool vis[N];
	int cur[N],d[N];

	int Spfa()
	{
		queue<int> Q;
		Q.push(S);
		memset(d,0x3f,sizeof d);
		d[S]=0;
		while(!Q.empty())
		{
			int u=Q.front();
			Q.pop();
			inq[u]=false;
			for(int i=fir[u];i;i=nxt[i])
			{
				Edge &e=edges[i];
				if(e.cap&&GetMin(d[e.v],d[u]+e.cost)&&!inq[e.v])
				{
					Q.push(e.v);
					inq[e.v]=true;
				}
			}
		}
		return d[T]<INF;
	}

	int Dfs(int u,int a=INF)
	{
		if(u==T||!a)
			return a;
		inq[u]=true;
		int f=0,af;
		for(int &i=cur[u];i;i=nxt[i])
		{
			Edge &e=edges[i];
			if(!inq[e.v]&&d[e.v]==d[u]+e.cost&&(af=Dfs(e.v,min(a,e.cap))))
			{
				f+=af;
				a-=af;
				e.cap-=af;
				edges[i^1].cap+=af;
				if(!a)
					break;
			}
		}
		inq[u]=false;
		return f;
	}

	Pir Ext()
	{
		Adde(T,TT,1,0);
		static int flow=0,af,cost=0;
		while(Spfa())
		{
			memcpy(cur,fir,sizeof cur);
			flow+=(af=Dfs(S));
			cost+=af*d[T];
		}
		return Pir(flow,cost);
	}

}

void Dfs(int o,int u,int fa=0,int dep=-1)
{
	++dep;
	if(!ban[u])
		Flower::Adde(o,u,1,dep);
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
		Dfs(o,v,u,dep);
}

void Build()
{
	for(int i=1;i<=tm;++i)
		Dfs(p[i],p[i]);
}

void Run()
{
	int ans=0;
	Pir p;
	while(true)
	{
		p=Ext();
		if(p.fir==ans+1&&p.sec<=tm)
			++ans;
		else
			break;
	}
}

int main()
{
	scanf("%d%d",&n,&tm);
	for(int i=2,p;i<=n;++i)
	{
		scanf("%d",&p);
		Adde(i,p);
	}
	for(int i=1;i<=tm;++i)
	{
		scanf("%d",p+i);
		ban[p[i]]=true;
	}
	Build();
	Run();
	return 0;
}
