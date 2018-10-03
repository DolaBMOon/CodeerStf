#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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

const int N=2e5+10;

int n,m,q,du[N],u[N],v[N],ls[N],ed;
int fir[N],nxt[N],to[N],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
}

void Song1(int id)
{
	static int d[N];
	memset(d,0,sizeof d);
	int ans=0;
	for(int i=1,u;i<=n;++i)if((u=ls[i])!=id)
	{
		GetMax(ans,d[u]);
		for(int j=fir[u];j;j=nxt[j])
			GetMax(d[to[j]],d[u]+1);
	}
	printf("%d\n",ans);
}

void Song2(int id)
{
	static int d[N][2];
	for(int i=1;i<=n;++i)
	{
		d[i][0]=0;
		d[i][1]=-(0x3f3f3f3f);
	}
	d[id][1]=0;
	int ans=0;
	for(int i=1,u;i<=n;++i)
	{
		GetMax(ans,d[u=ls[i]][1]);
		for(int j=fir[u],v;j;j=nxt[j])
		{
			v=to[j];
			GetMax(d[v][v==id],d[u][0]+1);
			if(d[u][1])
				GetMax(d[v][1],d[u][1]+1);
		}
	}
	printf("%d\n",ans);
}

void Song3(int id)
{
	static int d[N][2];
	memset(d,0,sizeof d);
	int ans=0,x=u[id],y=v[id];
	for(int i=1,u;i<=n;++i)
	{
		GetMax(ans,d[u=ls[i]][1]);
		for(int j=fir[u],v;j;j=nxt[j])
		{
			v=to[j];
			GetMax(d[v][u==x&&v==y],d[u][0]+1);
			GetMax(d[v][1],d[u][1]+1);
		}
	}
	printf("%d\n",ans);
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);
		Adde(u[i],v[i]);
		++du[v[i]];
	}
	queue<int> Q;
	for(int i=1;i<=n;++i)if(!du[i])
		Q.push(i);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		ls[++ed]=u;
		for(int i=fir[u],v;i;i=nxt[i])if(!(--du[v=to[i]]))
			Q.push(v);
	}
	for(int i=1,ty,x;i<=q;++i)
	{
		scanf("%d%d",&ty,&x);
		if(ty==1)
			Song1(x);
		else if(ty==2)
			Song2(x);
		else
			Song3(x);
	}
	return 0;
}
