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

#define int long long

const int N=233;
const int S=N-2;
const int T=N-3;
const int M=2333;
const int INF=0x3f3f3f3f3f3f3f3f;

struct Edge
{
	int v,c;
}edges[M];

int cur[N],fir[N],nxt[M],tote=1;

void Adde(int u,int v,int c)
{
	//cout<<u<<","<<v<<":"<<c<<endl;
	edges[++tote]=(Edge){v,c};
	nxt[tote]=fir[u];
	fir[u]=tote;
	edges[++tote]=(Edge){u,0};
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int n,a[N],ans;
int d[N];

bool Bfs()
{
	memset(d,0,sizeof d);
	d[S]=1;
	static queue<int> Q;
	Q.push(S);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=fir[u];i;i=nxt[i])
		{
			Edge &e=edges[i];
			if(e.c&&!d[e.v])
			{
				d[e.v]=d[u]+1;
				Q.push(e.v);
			}
		}
	}
	return d[T];
}

int Dfs(int u,int a=INF)
{
	if(u==T||!a)
		return a;
	int f=0,af;
	for(int &i=cur[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(d[e.v]==d[u]+1&&(af=Dfs(e.v,min(e.c,a))))
		{
			f+=af;
			a-=af;
			e.c-=af;
			edges[i^1].c+=af;
			if(!a)
				break;
		}
	}
	return f;
}

int MaxFlow()
{
	int f=0;
	while(Bfs())
	{
		memcpy(cur,fir,sizeof fir);
		f+=Dfs(S);
	}
	return f;
}

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		if(a[i]>0)
		{
			ans+=a[i];
			Adde(i,T,a[i]);
		}
		else
			Adde(S,i,-a[i]);
	}
	for(int i=1;i<=n;++i)if(a[i]<0)
		for(int j=i;j<=n;j+=i)if(a[j]>0)
			Adde(i,j,INF);
	//Whats(ans);
	ans-=MaxFlow();
	printf("%lld",ans);
	return 0;
}
