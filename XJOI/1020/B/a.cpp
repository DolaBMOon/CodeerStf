#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=200000+10;
const int B=20;
const int MOD=998244353;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(LL)x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

int D(int x,int y)
{
	return ((x-=y)<0)?(x+MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

void SD(int &x,int y)
{
	((x-=y)<0)?(x+=MOD):0;
}

struct Edge
{
	int v,p;
}edges[N<<1];

int n,a[N],d[N];
int fir[N],nxt[N<<1],tote;

void Adde(int u,int v,int p)
{
	edges[++tote]=(Edge){v,p};
	nxt[tote]=fir[u];
	fir[u]=tote;
	edges[++tote]=(Edge){u,p};
	nxt[tote]=fir[v];
	fir[v]=tote;
}

int st[N][B],fa[N],dep[N],f[N];
Pir data[N];

Pir Merge(Pir x,Pir y)
{
	return (Pir){U(U(x.fir,y.fir),Mul(2,Mul(x.sec,y.sec))),U(x.sec,y.sec)};
}

Pir Pick(Pir x,Pir y)
{
	int t=D(x.sec,y.sec);
	return (Pir){D(x.fir,U(y.fir,Mul(2,Mul(t,y.sec)))),t};
}

vector<int> del[N];
int ans[N];

void Dfs(int u)
{
	dep[u]=dep[st[u][0]=fa[u]]+1;
	for(int i=1;i<B;++i)
		st[u][i]=st[st[u][i-1]][i-1];
	int x=u;
	for(int i=B-1,k,wt=dep[u]-d[u]-1;x&&i>=0;--i)if(dep[k=st[x][i]]>=wt)
		x=k;
	if(x)
		del[x].push_back(a[u]);
	for(int i=fir[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(e.v==fa[u])
			continue;
		fa[e.v]=u;
		Dfs(e.v);
		SU(f[u],f[e.v]);
		Pir t=data[e.v];
		SMul(t.fir,e.p);
		SMul(t.sec,e.p);
		data[u]=Merge(data[u],t);
	}
	SU(f[u],a[u]);
	for(int i=del[u].size()-1;i>=0;--i)
		SD(f[u],del[u][i]);
	data[u]=Merge(data[u],(Pir){Mul(f[u],f[u]),f[u]});
}

void Song(int u)
{
	ans[u]=data[u].fir;
	for(int i=fir[u];i;i=nxt[i])
	{
		Edge &e=edges[i];
		if(e.v==fa[u])
			continue;
		Pir _a=data[u],_b=data[e.v],t=data[e.v];
		SMul(t.fir,e.p);
		SMul(t.sec,e.p);
		data[u]=Pick(data[u],t);
		t=data[u];
		SMul(t.fir,e.p);
		SMul(t.sec,e.p);
		data[e.v]=Merge(data[e.v],t);
		Song(e.v);
		data[u]=_a;
		data[e.v]=_b;
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",a+i,d+i);
	for(int i=1,u,v,p;i<n;++i)
	{
		scanf("%d%d%d",&u,&v,&p);
		Adde(u,v,p);
	}
	Dfs(1);
	Song(1);
	int q;
	scanf("%d",&q);
	for(int i=1,u;i<=q;++i)
	{
		scanf("%d",&u);
		printf("%d\n",ans[u]);
	}
	return 0;
}
