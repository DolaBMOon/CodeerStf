#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define int long long

const int INF=0x3f3f3f3f3f3f3f3f;

const int K=1111111;
const int N=2012;

const int S=N-2;
const int T=N-3;

struct Edge
{
	int v,cap,cost;
}edges[K];

int n,m,k;
int fir[N],nxt[K],tote=1;

void Adde(int u,int v,int cap,int cost)
{
	edges[++tote]=(Edge){v,cap,cost};
	nxt[tote]=fir[u];fir[u]=tote;
	edges[++tote]=(Edge){u,0,-cost};
	nxt[tote]=fir[v];fir[v]=tote;
}

int d[N];
bool inq[N];
queue<int> Q;

bool SPFA()
{
	memset(d,0x3f,sizeof d);
	d[S]=0;
	Q.push(S);

	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		inq[u]=false;
		for(int i=fir[u],s;i;i=nxt[i])
		{
			Edge &e=edges[i];
			if(e.cap&&(s=d[u]+e.cost)<d[e.v])
			{
				d[e.v]=s;
				if(!inq[e.v])
				{
					Q.push(e.v);
					inq[e.v]=true;
				}
			}
		}
	}

	return d[T]<0;
}

int cur[N];

int Dfs(int u,int a=INF)
{
	if(u==T||!a)
		return a;
	
	inq[u]=true;
	int sum=0,f;
	for(int &i=cur[u];i&&a;i=nxt[i])
	{
		Edge &e=edges[i];
		if(!inq[e.v]&&d[e.v]==d[u]+e.cost&&(f=Dfs(e.v,min(a,e.cap))))
		{
			sum+=f;
			a-=f;
			e.cap-=f;
			edges[i^1].cap+=f;
		}
	}

	inq[u]=false;
	return sum;
}

int MaxFlowMinCost()
{
	int cost=0,flow;
	while(SPFA())
	{
		memcpy(cur,fir,sizeof cur);
		flow=Dfs(S);
		cost+=d[T]*flow;
	}
	return cost;
}

signed main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1,u,v,cost;i<=k;++i)
	{
		scanf("%lld%lld%lld",&u,&v,&cost);
		Adde(u,n+v,1,-cost);
	}
	for(int i=1;i<=n;++i)
		Adde(S,i,1,0);
	for(int i=1;i<=m;++i)
		Adde(n+i,T,1,0);

	printf("%lld",-MaxFlowMinCost());
	return 0;
}
