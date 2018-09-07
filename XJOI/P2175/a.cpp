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

const int N=233;
const int M=N*N;
const int S=N-1;
const int T=N-2;
const int SS=N-3;
const int TT=N-4;
const int INF=0x3f3f3f3f;

struct Edge
{
	int v,c;
}edges[M];

int n,rd[N],cd[N];
int fir[N],nxt[M],tote=1;

void Adde(int u,int v,int c)
{
	edges[++tote]=(Edge){v,c};
	nxt[tote]=fir[u];
	fir[u]=tote;
	edges[++tote]=(Edge){u,0};
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int s,t,d[N];
queue<int> Q;

bool Bfs()
{
	memset(d,0,sizeof d);
	d[s]=1;
	Q.push(s);

	while(!Q.empty())
	{
		int u=Q.front(),w=d[u]+1;
		Q.pop();
		for(int i=fir[u];i;i=nxt[i])
		{
			Edge &e=edges[i];
			if(e.c&&!d[e.v])
			{
				d[e.v]=w;
				Q.push(e.v);
			}
		}
	}

	return d[t];
}

int cur[N];

int Dfs(int u=s,int a=INF)
{
	if(u==t||!a)
		return a;

	int sm=0,af,w=d[u]+1;
	for(int &i=cur[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(d[e.v]==w&&(af=Dfs(e.v,min(a,e.c))))
		{
			sm+=af;
			e.c-=af;
			edges[i^1].c+=af;
			if(!(a-=af))
				return sm;
		}
	}

	return sm;
}

int MaxFlow(int _s,int _t)
{
	s=_s;
	t=_t;
	int sm=0;
	while(Bfs())
	{
		memcpy(cur,fir,sizeof cur);
		sm+=Dfs();
	}
	return sm;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",cd+i);
		for(int j=1,v;j<=cd[i];++j)
		{
			scanf("%d",&v);
			Adde(i,v,INF);
			++rd[v];
		}
	}

	for(int i=1;i<=n;++i)
	{
		if(!rd[i])
			Adde(S,i,INF);
		if(!cd[i])
			Adde(i,T,INF);
		if(rd[i]>cd[i])
			Adde(SS,i,rd[i]-cd[i]);
		else if(cd[i]>rd[i])
			Adde(i,TT,cd[i]-rd[i]);
	}
	Adde(T,S,INF);

	MaxFlow(SS,TT);
	int ans=edges[tote].c;
	edges[tote].c=edges[tote^1].c=0;
	ans-=MaxFlow(T,S);
	printf("%d",ans);
	return 0;
}
