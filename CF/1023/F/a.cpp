#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

#define pir pair<int,bool>
#define fir first
#define sec second

const int N=5e5+10;

int n,k,m,fu[N],fv[N],fw[N];

int in[N],w[N];

int Find(int x)
{
	return in[x]?(in[x]=Find(in[x])):x;
}

void Hb(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x^y)
		in[Find(x)]=Find(y);
}

vector<pir> G[N];

void Adde(int u,int v,bool w)
{
	G[u].emplace_back(v,w);
	G[v].emplace_back(u,w);
}

int fa[N],dep[N],val[N];
bool mine[N];

void Dfs(int u)
{
	for(pir p:G[u])if(p.fir!=fa[u])
	{
		fa[p.fir]=u;
		dep[p.fir]=dep[u]+1;
		mine[p.fir]=p.sec;
		Dfs(p.fir);
	}
}

int main()
{
	scanf("%d%d%d",&n,&k,&m);
	for(int i=1,a,b;i<=k;++i)
	{
		scanf("%d%d",&a,&b);
		Hb(a,b);
		Adde(a,b,true);
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d%d",fu+i,fv+i,fw+i);
		if(Find(fu[i])^Find(fv[i]))
		{
			Hb(fu[i],fv[i]);
			Adde(fu[i],fv[i],false);
			fu[i]=0;
		}
	}

	Dfs(1);
	memset(in+1,0,n*sizeof(int));
	for(int i=1,x,y;i<=m;++i)if(fu[i])
	{
		x=Find(fu[i]);
		y=Find(fv[i]);
		while(x^y)
		{
			if(dep[x]<dep[y])
				swap(x,y);
			val[x]=fw[i];
			x=in[x]=Find(fa[x]);
		}
	}

	long long ans=0;
	for(int i=1;i<=n;++i)if(mine[i])
	{
		if(val[i])
			ans+=val[i];
		else
		{
			puts("-1");
			return 0;
		}
	}
	printf("%lld",ans);
	return 0;
}
