#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
	 -<Unlimited Blade Works>-
 */

const int N=100000+10;
const int M=1000000+10;

int n,m,MOD;
int fir[N],nxt[M],to[M],tote;

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

void Adde(int u,int v)
{
	to[++tote]=v;nxt[tote]=fir[u];fir[u]=tote;
}

int dfn[N],low[N],dfstime,stk[N],tp,col[N],cc,sz[N];
bool ins[N];

void GetMin(int &a,int b)
{
	a=((a<b)?a:b);
}

void GetMax(int &a,int b)
{
	a=((a>b)?a:b);
}

void Dfs(int u)
{
	dfn[u]=low[u]=++dfstime;
	ins[stk[++tp]=u]=true;
	for(int i=fir[u],v;i;i=nxt[i])
	{
		v=to[i];
		if(dfn[v])
		{
			if(ins[v])
				GetMin(low[u],dfn[v]);
		}
		else
		{
			Dfs(v);
			GetMin(low[u],low[v]);
		}
	}

	if(dfn[u]==low[u])
	{
		++cc;
		for(int v=-1;v!=u;++sz[cc])
		{
			ins[v=stk[tp--]]=false;
			col[v]=cc;
		}
	}
}

vector<int> rv[N],cv[N];
int mx[N],cnt[N];

void Song(vector<int> &v)
{
	sort(v.begin(),v.end());
	v.resize(unique(v.begin(),v.end())-v.begin());
}

int main()
{
	scanf("%d%d%d",&n,&m,&MOD);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}

	for(int i=1;i<=n;++i)if(!dfn[i])
		Dfs(i);

	for(int u=1;u<=n;++u)
		for(int i=fir[u],v,x,y;i;i=nxt[i])if(col[v=to[i]]!=col[u])
		{
			x=col[u];
			y=col[v];
			cv[x].push_back(y);
			rv[y].push_back(x);
		}

	for(int i=1;i<=cc;++i)
	{
		Song(rv[i]);
		Song(cv[i]);
		if(!rv[i].size())
			cnt[i]=1;
	}

	int gmx=0;
	for(int u=cc;u>=1;--u)
	{
		int &x=mx[u],&y=cnt[u];
		for(int v:rv[u])
		{
			if(x==mx[v])
				SU(y,cnt[v]);
		}
		GetMax(gmx,x+=sz[u]);
		for(int v:cv[u])
			GetMax(mx[v],mx[u]);
	}

	printf("%d\n",gmx);
	int gcnt=0;
	for(int i=1;i<=cc;++i)if(gmx==mx[i])
		SU(gcnt,cnt[i]);
	printf("%d",gcnt);
	return 0;
}

