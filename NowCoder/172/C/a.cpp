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

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=1e6;
const int B=20;

int n,m,q;
int fir[N],nxt[N],to[N],tote;

void Adde(int u,int v)
{
	to[++tote]=v;nxt[tote]=fir[u];fir[u]=tote;
	to[++tote]=u;nxt[tote]=fir[v];fir[v]=tote;
}

int dep[N],st[N][B];

void Song(int u,int fa=0)
{
	dep[u]=dep[fa]+1;
	st[u][0]=fa;
	for(int i=1;i<B;++i)
		st[u][i]=st[st[u][i-1]][i-1];
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
		Song(v,u);
}

int Lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=B-1;~i;--i)if(dep[st[x][i]]>=dep[y])
		x=st[x][i];
	if(x==y)
		return x;
	for(int i=B-1;~i;--i)if(st[x][i]!=st[y][i])
	{
		x=st[x][i];
		y=st[y][i];
	}
	return st[x][0];
}

vector<int> A[N],Q[N];
int cnt[N],d[N],lz[N<<2],mx[N<<2],ki[N],ans[N];

void Add(int q,int w,int o=1,int l=1,int r=n)
{
	mx[o]+=w;
	if(q<=l)
	{
		lz[o]+=w;
		return;
	}
	int mid=(l+r)>>1;
	if(q<=mid)
		Add(q,w,o<<1,l,mid);
	else
		Add(q,w,(o<<1)^1,mid+1,r);
}

int Query(int k,int o=1,int l=1,int r=n)
{
	if(l==r)
		return l;
	int mid=(l+r)>>1,lc=o<<1,rc=lc^1;
	k-=lz[o];
	if(mx[lc]>=k)
		return Query(k,lc,l,mid);
	else
		return Query(k,rc,mid+1,r);
}

void Dfs(int u,int fa=0)
{
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
		Dfs(v,u);
	for(int i=0;i<(int)A[u].size();++i)
		Add(A[u][i],1);
	if(cnt[u])
		Add(dep[u],cnt[u]);
	for(int i=0,id;i<(int)Q[u].size();++i)
	{
		id=Q[u][i];
		if(mx[1]<ki[id])
			ans[id]=0;
		else
			ans[id]=dep[u]-Query(ki[id]);
	}
	if(cnt[u])
		Add(dep[u],-cnt[u]);
	if(d[u])
		Add(dep[u]-1,-d[u]);
}

void Doit(int u,int f)
{
	A[u].push_back(dep[f]);
	for(int i=B-1;~i;--i)if(dep[st[u][i]>dep[f]])
		u=st[u][i];
	++d[u];
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Song(1);
	for(int i=1,x,y,f;i<=m;++i)
	{
		scanf("%d%d",&x,&y);
		f=Lca(x,y);
		if(f!=x&&f!=y)
		{
			Doit(x,f);
			Doit(y,f);
		}
		else if(f!=x||f!=y)
		{
			if(f==x)
				Doit(y,f);
			else
				Doit(x,f);
		}
		++cnt[f];
	}
	scanf("%d",&q);
	for(int i=1,v;i<=q;++i)
	{
		scanf("%d%d",&v,ki+i);
		Q[v].push_back(i);
	}
	Dfs(1);
	for(int i=1;i<=q;++i)
		printf("%d\n",ans[i]);
	return 0;
}
