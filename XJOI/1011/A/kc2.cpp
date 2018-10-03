%:pragma GCC target("avx")
%:pragma GCC optimize(3)
%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
%:pragma GCC optimize("-fgcse")
%:pragma GCC optimize("-fgcse-lm")
%:pragma GCC optimize("-fipa-sra")
%:pragma GCC optimize("-ftree-pre")
%:pragma GCC optimize("-ftree-vrp")
%:pragma GCC optimize("-fpeephole2")
%:pragma GCC optimize("-ffast-math")
%:pragma GCC optimize("-fsched-spec")
%:pragma GCC optimize("unroll-loops")
%:pragma GCC optimize("-falign-jumps")
%:pragma GCC optimize("-falign-loops")
%:pragma GCC optimize("-falign-labels")
%:pragma GCC optimize("-fdevirtualize")
%:pragma GCC optimize("-fcaller-saves")
%:pragma GCC optimize("-fcrossjumping")
%:pragma GCC optimize("-fthread-jumps")
%:pragma GCC optimize("-funroll-loops")
%:pragma GCC optimize("-fwhole-program")
%:pragma GCC optimize("-freorder-blocks")
%:pragma GCC optimize("-fschedule-insns")
%:pragma GCC optimize("inline-functions")
%:pragma GCC optimize("-ftree-tail-merge")
%:pragma GCC optimize("-fschedule-insns2")
%:pragma GCC optimize("-fstrict-aliasing")
%:pragma GCC optimize("-fstrict-overflow")
%:pragma GCC optimize("-falign-functions")
%:pragma GCC optimize("-fcse-skip-blocks")
%:pragma GCC optimize("-fcse-follow-jumps")
%:pragma GCC optimize("-fsched-interblock")
%:pragma GCC optimize("-fpartial-inlining")
%:pragma GCC optimize("no-stack-protector")
%:pragma GCC optimize("-freorder-functions")
%:pragma GCC optimize("-findirect-inlining")
%:pragma GCC optimize("-frerun-cse-after-loop")
%:pragma GCC optimize("inline-small-functions")
%:pragma GCC optimize("-finline-small-functions")
%:pragma GCC optimize("-ftree-switch-conversion")
%:pragma GCC optimize("-foptimize-sibling-calls")
%:pragma GCC optimize("-fexpensive-optimizations")
%:pragma GCC optimize("-funsafe-loop-optimizations")
%:pragma GCC optimize("inline-functions-called-once")
%:pragma GCC optimize("-fdelete-null-pointer-checks")
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

#define LL long long

const int N=5005;

int n;
LL val[N],ls[N],ed;
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

int lst[N][N];
LL ans[N];

void Append(int *x,int y)
{
	x[++(*x)]=y;
}

int dep[N];
LL tr[N<<2];
int lz[N<<2],sz[N<<2];

bool Cmp(int x,int y)
{
	return dep[x]<dep[y];
}

void Add(int ql,int qr,int o,int l,int r)
{
	if(ql<=l&&r<=qr)
	{
		tr[o]+=sz[o];
		++lz[o];
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	if(ql<=mid)
		Add(ql,qr,lc,l,mid);
	if(qr>mid)
		Add(ql,qr,rc,mid+1,r);
	tr[o]=tr[lc]+tr[rc]+(LL)lz[o]*sz[o];
}


void Update(int q,int o=1,int l=1,int r=ed)
{
	if(l==r)
	{
		tr[o]=lz[o]*(++sz[o]);
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	if(q<=mid)
		Update(q,lc,l,mid);
	else
		Update(q,rc,mid+1,r);
	tr[o]=tr[lc]+tr[rc]+(LL)lz[o]*(++sz[o]);
}

void Song(int q,int o=1,int l=1,int r=ed)
{
	if(q<=l)
	{
		tr[o]+=sz[o];
		++lz[o];
		return;
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	if(q<=mid)
		Song(ql,qr,lc,l,mid);
	if(qr>mid)
		Add(ql,qr,rc,mid+1,r);
	tr[o]=tr[lc]+tr[rc]+(LL)lz[o]*sz[o];
}

int cc;

int Query(int ql,int qr,int o,int l,int r,int &won)
{
	if(ql<=l&&r<=qr)
	{
		won+=sz[o];
		return tr[o];
	}
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1,res=0,cnt=0;
	if(ql<=mid)
		res+=Query(ql,qr,lc,l,mid,cnt);
	if(qr>mid)
		res+=Query(ql,qr,rc,mid+1,r,cnt);
	won+=cnt;
	return res+cnt*lz[o];
}
int Query(int ql,int qr)
{
	cc=0;
	if(ql<=qr)
	{
		int res=Query(ql,qr,1,1,ed,cc);
		return res-cc;
	}
	return 0;
}

void Cleaher()
{
	memset(tr,0,sizeof tr);
	memset(lz,0,sizeof lz);
	memset(sz,0,sizeof sz);
}

void Dfs(int u,int fa=0)
{
	dep[u]=dep[fa]+1;
	int *x=lst[u],*y;
	Append(x,u);
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Dfs(v,u);
		y=lst[v];
		for(int j=*y;j>=1;--j)
			Append(x,y[j]);
	}
	sort(x+1,x+*x+1,Cmp);
	LL &a=ans[u];
	Cleaher();
	for(int i=*x,rec=*x;i>=1;--i)
	{
		if(dep[x[i]]!=dep[x[i+1]])
		{
			for(int j=i+1;j<=rec;++j)
				Insert(val[x[j]]);
			rec=i;
		}
		a+=Query(1,val[x[i]]-1);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",val+i);
		ls[++ed]=val[i];
	}
	sort(ls+1,ls+ed+1);
	ed=unique(ls+1,ls+ed+1)-ls-1;
	for(int i=1;i<=n;++i)
		val[i]=lower_bound(ls+1,ls+ed+1,val[i])-ls;
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}
