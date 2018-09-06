#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define LL long long

const int N=100000+10;
const int INF=0x3f3f3f3f;

int n,m,master,c[N],l[N];
int fir[N],nxt[N],to[N],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
}

int rt[N],lc[N],rc[N],fix[N],sz[N],sm[N];

void Pullup(int o)
{
	if((sm[o]=sm[lc[o]]+sm[rc[o]])<INF)
		sm[o]=min(INF,sm[o]+c[o]);
	else
		sm[o]=INF;
	sz[o]=1+sz[lc[o]]+sz[rc[o]];
}

void Split(int o,int k,int &x,int &y)
{
	if(!o)
	{
		x=y=0;
		return;
	}
	if(c[o]<=k)
	{
		x=o;
		Split(rc[o],k,rc[o],y);
	}
	else
	{
		y=o;
		Split(lc[o],k,x,lc[o]);
	}
	Pullup(o);
}

int Merge(int x,int y)
{
	if(!x||!y)
		return x^y;
	int a,b;
	if(fix[x]<fix[y])
		swap(x,y);
	Split(y,c[x],a,b);
	lc[x]=Merge(lc[x],a);
	rc[x]=Merge(rc[x],b);
	Pullup(x);
	return x;
}

LL ans;

int Count(int o)
{
	int cnt=0,k=m,t;
	while(k&&o)
	{
		if((t=sm[lc[o]]+c[o])<=k)
		{
			cnt+=sz[lc[o]]+1;
			k-=t;
			o=rc[o];
		}
		else
			o=lc[o];
	}
	return cnt;
}

void Print(int o)
{
	if(o)
	{
		Print(lc[o]);
		Print(rc[o]);
	}
}

void Dfs(int u)
{
	rt[u]=u;
	for(int i=fir[u],v;i;i=nxt[i])
	{
		v=to[i];
		Dfs(v);
		rt[u]=Merge(rt[u],rt[v]);
	}
	ans=max(ans,(LL)l[u]*Count(rt[u]));
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,b;i<=n;++i)
	{
		scanf("%d%d%d",&b,c+i,l+i);
		if(b)
			Adde(b,i);
		else
			master=i;
		fix[i]=rand();
		sz[i]=1;
	}

	Dfs(master);

	printf("%lld",ans);
	return 0;
}
