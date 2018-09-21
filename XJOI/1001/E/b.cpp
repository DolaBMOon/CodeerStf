#pragma GCC optimize(2)
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

int n,m,tm,p[N];
int fir[N],nxt[N],to[N],tote;
bool ban[N];

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

namespace Flower
{

	int fir[N],nxt[N],to[N],tote;

	void Adde(int u,int v)
	{
		to[++tote]=v;
		nxt[tote]=fir[u];
		fir[u]=tote;
	}

	int linker[N],used[N],cc;

	bool Dfs(int u)
	{
		for(int i=fir[u],v;i;i=nxt[i])if(used[v=to[i]]!=cc)
		{
			used[v]=cc;
			if(!linker[v]||Dfs(linker[v]))
			{
				linker[v]=u;
				return true;
			}
		}
		return false;
	}

	int PiPei()
	{
		int res=0;
		for(int i=1;i<=m;++i)
		{
			++cc;
			res+=Dfs(p[i]);
		}
		return res;
	}
	
}

void Dfs(int o,int u,int fa=0,int dep=-1)
{
	++dep;
	//if(o==3)
	//	cout<<dep<<","<<u<<endl;
	if(dep>tm)
		return;
	if(!ban[u])
		Flower::Adde(o,u);
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
		Dfs(o,v,u,dep);
}

void Build()
{
	for(int i=1;i<=m;++i)
		Dfs(p[i],p[i]);
}

int main()
{
	scanf("%d%d",&n,&tm);
	for(int i=2,p;i<=n;++i)
	{
		scanf("%d",&p);
		Adde(i,p+1);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		scanf("%d",p+i);
		ban[++p[i]]=true;
	}
	Build();
	printf("%d",Flower::PiPei());
	return 0;
}
