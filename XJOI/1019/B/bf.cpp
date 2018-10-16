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

bool vis[N];

void Dfs(int u,int fa=0)
{
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
	{
		Dfs(v,u);
		vis[u]|=vis[v];
	}
}

void Que()
{
	memset(vis,0,sizeof vis);
	static int lst[N],ed;
	ed=0;
	for(;scanf("%lld",lst+ed+1),lst[ed+1];++ed);
	for(int i=1;i<=ed;++i)
		vis[lst[i]]=true;
	for(int i=1;i<=ed;++i)
		Dfs(lst[i]);
	int res=0;
	for(int i=1;i<=n;++i)if(vis[i])
		res+=a[i];
	printf("%lld\n",res);
}

void Chg()
{
	int x,k;
	scanf("%lld%lld",&x,&k);
	a[x]=k;
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
