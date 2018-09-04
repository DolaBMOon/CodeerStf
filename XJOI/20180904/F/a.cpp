#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define Pir pair<int,int>
#define fir first
#define sec seond

const int N=200000+10;
const int LG=20;

int n,m,exn;
bool on[N];

int _fir[N],_nxt[N<<1],_to[N<<1],_tote;
int fir[N],nxt[N<<1],to[N<<1],w[N<<1],tote;

void Adde(int u,int v,int x)
{
	//cout<<u<<"---"<<v<<endl;
	to[++tote]=v;w[tote]=x;nxt[tote]=fir[u];fir[u]=tote;
	to[++tote]=u;w[tote]=x;nxt[tote]=fir[v];fir[v]=tote;
}

void Song(int u,int fa=0)
{
	int o=u;
	bool fl=false;
	for(int i=_fir[u],v;i;i=_nxt[i])if((v=_to[i])!=fa)
	{
		if(fl)
		{
			Adde(o,++exn,0);
			Adde(o=exn,v,1);
		}
		else
		{
			Adde(u,v,1);
			fl=true;
		}
		Song(v,u);
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

	int lc[LG*N],rc[LG*N],tot,w[LG*N],as[LG*N];

	void Insert(int &o,int p,int k,int l=1,int r=n)
	{
		if(!o)
			o=++tot;
		GetMax(w[o],k);
		if(l==r)
		{
			as[o]=k;
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)
			Insert(lc[o],p,k,l,mid);
		else
			Insert(rc[o],p,k,mid+1,r);
	}

	void Xor(int o,int p,int l=1,int r=n)
	{
		if(l==r)
		{
			w[o]=(on[p]?as[o]:0);
			return;
		}
		int mid=(l+r)>>1;
		if(p<=mid)
			Xor(lc[o],p,l,mid);
		else
			Xor(rc[o],p,mid+1,r);
		w[o]=max(w[lc[o]],w[rc[o]]);
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
	tpf[id]=comefrom;
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
		_to[++_tote]=v;_nxt[_tote]=_fir[u];_fir[u]=_tote;
		_to[++_tote]=u;_nxt[_tote]=_fir[v];_fir[v]=_tote;
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
