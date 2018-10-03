#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>
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

int n,m,q,du[N],tup[N],ed,u[N],v[N],dp[N],adp[N],inv[N],que[N],hd,tl,mx[N<<2],premx[N],sufmx[N],px[N];
vector<int> G[N],aG[N],A[N],B[N];

void Song1(int x)
{
	printf("%d\n",px[inv[x]]);
}

void Song2(int x)
{
	printf("%d\n",dp[x]+adp[x]);
}

void Song3(int x)
{
	printf("%d\n",dp[u[x]]+1+adp[v[x]]);
}

void Gao(int o=1,int l=1,int r=n,int x=0)
{
	GetMax(x,mx[o]);
	if(l==r)
	{
		px[l]=max(max(premx[l-1],sufmx[r+1]),x);
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	Gao(lc,l,mid,x);
	Gao(rc,mid+1,r,x);
}

void Update(int ql,int qr,int w,int o=1,int l=1,int r=n)
{
	if(ql<=l&&r<=qr)
	{
		GetMax(mx[o],w);
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	if(ql<=mid)
		Update(ql,qr,w,lc,l,mid);
	if(qr>mid)
		Update(ql,qr,w,rc,mid+1,r);
}

void Prework()
{
	queue<int> Q;
	for(int i=1;i<=n;++i)if(!du[i])
		Q.push(i);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		tup[++ed]=u;
		inv[u]=ed;
		for(int v:G[u])if(!(--du[v]))
			Q.push(v);
	}

	for(int i=1,u;i<=n;++i)
	{
		u=tup[i];
		premx[i]=max(premx[i-1],dp[u]);
		for(int v:G[u])
			GetMax(dp[v],dp[u]+1);
	}
	for(int i=n,u;i>=1;--i)
	{
		u=tup[i];
		sufmx[i]=max(sufmx[i+1],adp[u]);
		for(int v:aG[u])
			GetMax(adp[v],adp[u]+1);
	}
	for(int i=1,l,r,w;i<=m;++i)
		if((l=inv[u[i]]+1)<=(r=inv[v[i]]-1))
		{
			w=dp[u[i]]+1+adp[v[i]];
			Update(l,r,w);
		}

	Gao();
}

int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",u+i,v+i);
		G[u[i]].emplace_back(v[i]);
		aG[v[i]].emplace_back(u[i]);
		++du[v[i]];
	}
	Prework();
	for(int i=1,ty,x;i<=q;++i)
	{
		scanf("%d%d",&ty,&x);
		switch(ty)
		{
			case 1:
				Song1(x);
				break;
			case 2:
				Song2(x);
				break;
			case 3:
				Song3(x);
				break;
		}
	}
	return 0;
}
