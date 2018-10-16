#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<"<<<<<<<<<<"endl
#define Divher() cout<<">>>>>>>>>>"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return (a<=b)?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return (a>=b)?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

#define int long long

const int N=200000+10;
const int B=20;

int n,q,a[N];

int fir[N],nxt[N],to[N],tote;

void Adde(int u,int v)
{
	to[++tote]=v;
	nxt[tote]=fir[u];
	fir[u]=tote;
	to[++tote]=u;
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int in[N],ou[N],tm,st[N][B],fa[N],dep[N];

void Dfs(int u)
{
	dep[u]=dep[st[u][0]=fa[u]]+1;
	for(int i=1;i<B;++i)
		st[u][i]=st[st[u][i-1]][i-1];
	in[u]=++tm;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u])
	{
		fa[v]=u;
		Dfs(v);
	}
	ou[u]=++tm;
}

int Lca(int x,int y)
{
	if(dep[x]<dep[y])
		swap(x,y);
	for(int i=B-1;i>=0;--i)if(dep[st[x][i]]>=dep[y])
		x=st[x][i];
	if(x==y)
		return x;
	for(int i=B-1;i>=0;--i)if(st[x][i]!=st[y][i])
	{
		x=st[x][i];
		y=st[y][i];
	}
	return fa[x];
}

int C[N];

int Ask(int l,int r)
{
	if(l>r)
		return 0;
	int res=0;
	for(;r;r&=r-1)
		res+=C[r];
	for(--l;l;l&=l-1)
		res-=C[l];
	return res;
}

bool Cmp(int x,int y)
{
	return in[x]<in[y];
}

void Que()
{
	static int lst[N],ed,stk[N],tp;
	ed=0;
	for(;scanf("%lld",lst+ed+1),lst[ed+1];++ed);
	if(!ed)
	{
		puts("0");
		return;
	}
	//sort(lst+1,lst+ed+1);
	//ed=unique(lst+1,lst+ed+1)-lst-1;
	sort(lst+1,lst+ed+1,Cmp);
	tp=0;
	int ans=0;
	for(int i=1,v;i<=ed;++i)
	{
		v=lst[i];
		if(tp)
		{
			int f=Lca(stk[tp],v);
			for(;tp&&dep[stk[tp]]>=dep[f];--tp)
				if(dep[stk[tp-1]]>=dep[f])
					ans+=Ask(in[stk[tp-1]]+1,in[stk[tp]]);
				else
					ans+=Ask(in[f]+1,in[stk[tp]]);
			stk[++tp]=f;
		}
		stk[++tp]=v;
	}
	for(;tp>1;--tp)
		ans+=Ask(in[stk[tp-1]]+1,in[stk[tp]]);
	ans+=a[stk[tp]];
	printf("%lld\n",ans);
}

void Add(int x,int v)
{
	for(;x<=tm;x+=x&(-x))
		C[x]+=v;
}

void Chg()
{
	int x,v;
	scanf("%lld%lld",&x,&v);
	Add(in[x],-a[x]);
	Add(ou[x],a[x]);
	Add(in[x],a[x]=v);
	Add(ou[x],-v);
}

signed main()
{
	scanf("%lld%lld",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%lld%lld",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
	for(int i=1;i<=n;++i)
	{
		Add(in[i],a[i]);
		Add(ou[i],-a[i]);
	}
	char s[3];
	for(int i=1;i<=q;++i)
	{
		scanf("%s",s);
		if(*s=='Q')
			Que();
		else
			Chg();
	}
	return 0;
}
