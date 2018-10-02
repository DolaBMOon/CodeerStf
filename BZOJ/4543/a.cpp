#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

const int N=100000+10;

int n;
int fir[N],nxt[N+N],to[N+N],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int dep[N],mxdep[N],dson[N];

void Song(int u,int fa=0)
{
	mxdep[u]=dep[u]=dep[fa]+1;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Song(v,u);
		if(GetMax(mxdep[u],mxdep[v]))
			dson[u]=v;
	}
}

int *_f[N<<2],*_g[N<<2];

void Suan(int u,int fa=0,int *f=_f+N,int *g=_g)
{
	if(dson[u])
		Suan(v,u,f+1);
	int *p=f+2+mxdep[dson[u]],*q=g+2+mxdep[dson[u]];
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa&&v!=dson[u])
	{
		Suan(v,u,p,q);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Song(1);
	Suan(1);
	return 0;
}
