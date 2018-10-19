#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<queue>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

#define LL long long

const int N=400000+10;
const int B=20;

int n,q,tp,idx[520],meng[N];
int fir[N],nxt[N],to[N],tote,id[N];

int ch[N][5],sz=1;
bool vis[N];

void Insert(char *s,int u)
{
	int nw=1;
	for(int k;*s;++s)
	{
		k=idx[*s];
		if(!ch[nw][k])
			ch[nw][k]=++sz;
		nw=ch[nw][k];
	}
	id[u]=nw;
	vis[nw]=true;
}

int fail[N];

void Build()
{
	queue<int> Q;
	for(int i=0;i<5;++i)
		if(ch[1][i])
		{
			Q.push(ch[1][i]);
			fail[ch[1][i]]=1;
		}
		else
			ch[1][i]=1;
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int i=0,v;i<5;++i)
		{
			if((v=ch[u][i]))
			{
				Q.push(v);
				fail[v]=ch[fail[u]][i];
			}
			else
				ch[u][i]=ch[fail[u]][i];
		}
	}
}

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int fa[N],st[N][B],dep[N],in[N],ou[N],dtm;

void Dfs(int u)
{
	in[u]=++dtm;
	dep[u]=dep[st[u][0]=fa[u]]+1;
	for(int i=1;i<B;++i)
		st[u][i]=st[st[u][i-1]][i-1];
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u])
	{
		fa[v]=u;
		Dfs(v);
	}
	ou[u]=++dtm;
}

int Lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=B-1,k;i>=0;--i)if(dep[k=st[x][i]]>=dep[y])
		x=k;
	if(x==y)
		return x;
	for(int i=B-1,k,k2;i>=0;--i)if((k=st[x][i])!=(k2=st[y][i]))
	{
		x=k;
		y=k2;
	}
	return fa[x];
}

int rt[N],sm[N*30],lc[N*30],rc[N*30],tot;

void Add(int &o,int p,int w,int l=1,int r=dtm)
{
	if(!o)
		o=++tot;
	if(l==r)
	{
		sm[o]+=w;
		return;
	}
	sm[o]+=w;
	int mid=(l+r)>>1;
	if(p<=mid)
		Add(lc[o],p,w,l,mid);
	else
		Add(rc[o],p,w,mid+1,r);
}

int Query(int o,int ql,int qr,int l=1,int r=dtm)
{
	if(!o)
		return 0;
	if(ql<=l&&r<=qr)
		return sm[o];
	int mid=(l+r)>>1,res=0;
	if(ql<=mid)
		res+=Query(lc[o],ql,qr,l,mid);
	if(qr>mid)
		res+=Query(rc[o],ql,qr,mid+1,r);
	return res;
}

int Askher(int o,int u,int v,int f)
{
	if(u==f)
		return Query(rt[o],in[f],in[v]);
	else if(v==f)
		return Query(rt[o],in[f],in[u]);
	return Query(rt[o],in[f],in[v])+Query(rt[o],in[f],in[u])-Query(rt[o],in[f],in[f]);
	//return Query(rt[o],1,in[v])+Query(rt[o],1,in[u])-Query(rt[o],1,in[f])-(fa[f]?Query(rt[o],1,in[fa[f]]):0);
}

LL Song(char *s,int u,int v)
{
	LL ans=0;
	int nw=1,f=Lca(u,v);
	for(int k,o;*s;++s)
	{
		k=idx[*s];
		nw=ch[nw][k];
		o=nw;
		for(;o;o=fail[o])
			ans+=Askher(o,u,v,f);
	}
	return ans;
}

int main()
{
	idx['A']=0;
	idx['C']=1;
	idx['G']=2;
	idx['T']=3;
	idx['U']=4;
	scanf("%d%d",&n,&tp);
	static char s[N];
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		Insert(s,i);
	}
	Build();
	for(int i=2;i<=sz;++i)if(!vis[fail[i]])
		fail[i]=fail[fail[i]];
	for(int i=1;i<=n;++i)
		scanf("%d",meng+i);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	for(int i=1;i<=n;++i)
	{
		Add(rt[id[i]],in[i],meng[i]);
		Add(rt[id[i]],ou[i],-meng[i]);
	}
	scanf("%d",&q);
	LL last_ans=0;
	for(int i=1,op;i<=q;++i)
	{
		LL x,y;
		scanf("%d%lld%lld",&op,&x,&y);
		x^=(tp*last_ans);
		y^=(tp*last_ans);
		if(op&1)
		{
			scanf("%s",s);
			printf("%lld\n",last_ans=Song(s,x,y));
		}
		else
		{
			Add(rt[id[x]],in[x],y-meng[x]);
			Add(rt[id[x]],ou[x],meng[x]-y);
			meng[x]=y;
		}
	}
	return 0;
}
