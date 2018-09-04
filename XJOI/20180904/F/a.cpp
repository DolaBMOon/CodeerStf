#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>
#include<map>
#include<ext/pb_ds/priority_queue.hpp>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define fir first
#define sec second

#define PQ __gnu_pbds::priority_queue<int, less<int>, __gnu_pbds::pairing_heap_tag>
#define PT PQ::point_iterator

const int N=200000+10;

int n,m,exn;
bool on[N];

int fir[N],nxt[N<<2],to[N<<2],w[N<<2],tote;

void Adde(int u,int v)
{
	int x=(v<=n);
	to[++tote]=v;w[tote]=x;nxt[tote]=fir[u];fir[u]=tote;
	to[++tote]=u;w[tote]=x;nxt[tote]=fir[v];fir[v]=tote;
}

void Song(int u,int fa=0)
{
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
		Song(v,u);

	static queue<int> Q;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa)
		Q.push(v);

	fir[u]=0;
	while(Q.size()>2)
	{
		int v=Q.front(),v2;
		Q.pop();
		v2=Q.front();
		Q.pop();
		Adde(++exn,v);
		Adde(exn,v2);
		Q.push(exn);
	}
	while(!Q.empty())
	{
		int v=Q.front();
		Q.pop();
		Adde(u,v);
	}
}

void GetMax(int &x,int y)
{
	x=((x>y)?x:y);
}

void GetMin(int &x,int y)
{
	x=((x<y)?x:y);
}

int ban[N],totc,tp[N],tpf[N],fa[N],sz[N],lst[N],ed,low[N],ch[N][2],rt[N][2],mxl[N],ad[N];

namespace STr
{

	int w[N],as[N],tot;
	map<int,pair<int,PT> > mp[N];
	PQ D[N];

	void Insert(int &o,int p,int k)
	{
		if(!o)
			o=++tot;
		PT it=D[o].push(k);
		mp[o][p]=pair<int,PT>(k,it);
		w[o]=D[o].top();
	}

	void Xor(int o,int p)
	{
		if(on[p])
			mp[o][p].sec=D[o].push(mp[o][p].fir);
		else
			D[o].erase(mp[o][p].sec);
		if(!D[o].empty())
			w[o]=D[o].top();
		else
			w[o]=0;
	}

}

void Dfs(int u)
{
	lst[++ed]=u;
	sz[u]=1;
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u]&&!ban[v])
	{
		fa[v]=u;
		Dfs(v);
		sz[u]+=sz[v];
	}
}

void Dfs2(int u,int &o,int fa=0,int dep=0)
{
	if(u<=n)
		STr::Insert(o,u,dep);
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa&&!ban[v])
		Dfs2(v,o,u,dep+w[i]);
}

void Pullup(int o)
{
	mxl[o]=max(mxl[ch[o][0]],mxl[ch[o][1]]);
	GetMax(mxl[o],STr::w[rt[o][0]]+STr::w[rt[o][1]]+ad[o]);
}

void Build(int u,int comefrom=0,int fl=0)
{
	int id=++totc;
	tp[id]=comefrom;
	tpf[id]=fl;
	fa[u]=ed=0;
	Dfs(u);
	if(ed==1)
	{
		low[u]=id;
		return;
	}
	ch[comefrom][fl]=id;
	int t=sz[u],x=u,y;
	for(int i=2,v;i<=ed;++i)
	{
		v=lst[i];
		if((sz[v]=max(sz[v],t-sz[v]))<sz[x])
			x=v;
	}
	y=fa[x];
	for(int i=fir[x];i;i=nxt[i])if(to[i]==y)
		ad[id]=w[i];

	ban[x]=false;
	ban[y]=true;
	Dfs2(x,rt[id][0]);
	ban[x]=true;
	ban[y]=false;
	Dfs2(y,rt[id][1]);

	ban[x]=false;
	ban[y]=true;
	Build(x,id,0);
	ban[x]=true;
	ban[y]=false;
	Build(y,id,1);

	Pullup(id);
}

int gcnt;

void Change(int u)
{
	for(int nw=low[u],o;(o=tp[nw]);nw=tp[nw])
	{
		STr::Xor(rt[o][tpf[nw]],u);
		Pullup(o);
	}
	gcnt+=(on[u]?1:-1);
	on[u]^=1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		to[++tote]=v;nxt[tote]=fir[u];fir[u]=tote;
		to[++tote]=u;nxt[tote]=fir[v];fir[v]=tote;
	}

	exn=n;
	Song(1);

	gcnt=n;
	Build(1);

	scanf("%d",&m);
	char s[10];
	for(int i=1,x;i<=m;++i)
	{
		scanf("%s",s);
		if(*s=='G')
		{
			if(gcnt==0)
				puts("-1");
			else if(gcnt==1)
				puts("0");
			else
				printf("%d\n",mxl[1]);
		}
		else
		{
			scanf("%d",&x);
			Change(x);
		}
	}
	return 0;
}
