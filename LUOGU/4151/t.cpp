#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
That's how everything starts.
*/

#define LL long long

#define pir pair<int,LL>
#define fir first
#define sec second

const int N=1e5+10;

int n,m,u[N],v[N];
LL d[N];
vector<pir> G[N];
LL pond[63];

LL w[N];

bool vis[N];

void Add(LL x)
{
	for(int i=62;i>=0;--i)
	{
		if((x>>i)&1)
		{
			if(pond[i])
				x^=pond[i];
			else
			{
				pond[i]=x;
				return;
			}
		}
	}
}

LL Query(LL x)
{
	for(int i=62;i>=0;--i)
			x=max(x,x^pond[i]);
	return x;
}

void Dfs(int u)
{
	vis[u]=true;
	for(pir p:G[u])
		if(vis[p.fir])
			Add(w[p.fir]^p.sec^w[u]);
		else
		{
			w[p.fir]=w[u]^p.sec;
			Dfs(p.fir);
		}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i)
	{
		int u,v;
		LL d;
		scanf("%d%d%lld",&u,&v,&d);
		G[u].emplace_back(v,d);
		G[v].emplace_back(u,d);
	}
	Dfs(1);
	printf("%lld",Query(w[1]^w[n]));
	return 0;
}
