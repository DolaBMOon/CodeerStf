#include<bits/stdc++.h>
#define LL long long
#define INF 0x3f3f3f3f3f3f3f3fll
#define N 200010
using namespace std;

typedef pair<LL,int> P;
struct Edge{int y;LL w;};
int a[N],f[N],m,n,s;
vector<Edge> g[N];
LL d[N],ans[N];

inline void dijkstra()
{
	priority_queue<P,vector<P>,greater<P> > q;
	for(int i=1;i<=n;i++) d[i]=INF;
	for(int i=1;i<=s;i++)
	{
		q.push(P{0,a[i]});
		d[a[i]]=0; f[a[i]]=a[i];
	}
	while (!q.empty())
	{
		LL w=q.top().first;
		int j=q.top().second;
		q.pop(); if (w>d[j]) continue;
		for(int k=0;k<g[j].size();k++)
		{
			int y=g[j][k].y;
			LL dist=w+g[j][k].w;
			if (d[y]>dist)
			{
				d[y]=dist; f[y]=f[j];
				q.push(P(d[y],y));
			}
		}
	}
}

int main()
{
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=s;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		g[u].push_back(Edge{v,w});
		g[v].push_back(Edge{u,w});
	}

	dijkstra();
	for(int i=1;i<=n;i++) ans[i]=INF;
	for(int i=1;i<=n;i++)
	{
		cout<<i<<":"<<f[i]<<endl;
		for(int j=0;j<g[i].size();j++)
		{
			int y=g[i][j].y,w=g[i][j].w;
			if (f[i]!=f[y]) ans[f[i]]=min(ans[f[i]],d[y]+d[i]+w);
		}
	}
	for(int i=1;i<=s;i++)
		printf("%lld%c",ans[a[i]]," \n"[i==s]);
	return 0;
}
