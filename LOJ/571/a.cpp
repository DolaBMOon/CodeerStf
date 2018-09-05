#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=500+10;

int n,m,L,R,tot;

namespace A
{

	vector<int> G[N];
	bool Cn[N][N];

	void Adde(int u,int v)
	{
		G[u].emplace_back(v);
	}

	int dfn[N],low[N],dfstime,stk[N],tp,col[N],cc;
	bool in[N];

	void Dfs(int u)
	{
		dfn[u]=low[u]=++dfstime;
		stk[++tp]=u;
		in[u]=true;
		for(int v:G[u])
		{
			if(dfn[v])
			{
				if(in[v])
					low[u]=min(low[u],dfn[v]);
			}
			else
			{
				Dfs(v);
				low[u]=min(low[u],low[v]);
			}
		}

		if(dfn[u]==low[u])
		{
			++cc;
			for(int x=0;x!=u;col[x=stk[tp--]]=cc,in[x]=false);
		}
	}

	void Work()
	{
		for(int i=1;i<=tot;++i)if(!dfn[i])
			Dfs(i);
		for(int i=1;i<=tot;++i)
			for(int v:G[i])
				Cn[i][v]=true;
		for(int k=1;k<=tot;++k)
			for(int i=1;i<=tot;++i)
				for(int j=1;j<=tot;++j)
					Cn[i][j]|=(Cn[i][k]&&Cn[k][j]);
	}

}

vector<int> G[N];
int have[N];

void Adde(int u,int v)
{
	G[u].emplace_back(v);
	G[v].emplace_back(u);
}

void Adde(int u,int v,int fl)
{
	if(fl)
		A::Adde(v,u);
	else
		A::Adde(u,v);
}

int rt[N][4],ch[N][2],dep[N],mxd[N],hson[N],ud[N][2],vd[N][4];

void Itt(int& x,int fl)
{
	if(x)
	{
		++tot;
		memcpy(ch[tot],ch[x],2*sizeof(int));
		Adde(tot,x,fl);
		x=tot;
	}
	else
		x=++tot;
}

void Attach(int& x,int y,int fl)
{
	if(!y)
		return;
	if(!x)
	{
		x=y;
		return;
	}
	++tot;
	Adde(tot,x,fl);
	Adde(tot,y,fl);
}

void Insert(int& o,int fl,int x,int y,int l=1,int r=n)
{
	Itt(o,fl);
	if(l==r)
	{
		Adde(o,x,fl);
		return;
	}

	int mid=(l+r)>>1;
	if(y<=mid)
	{
		Insert(ch[o][0],fl,x,y,l,mid);
		Adde(o,ch[o][0],fl);
	}
	else
	{
		Insert(ch[o][1],fl,x,y,mid+1,r);
		Adde(o,ch[o][1],fl);
	}
}

void Merge(int& x,int y,int fl,int l=1,int r=n)
{
	if(!x)
		x=y;
	if(!y)
		return;
	Attach(x,y,fl);
	Merge(ch[x][0],ch[y][0],fl);
	Merge(ch[x][1],ch[y][1],fl);
}

void Link(int o,int fl,int x,int ql,int qr,int l=1,int r=n)
{
	if(!o)
		return;
	if(ql<=l&&r<=qr)
	{
		Adde(x,o,fl);
		return;
	}
	int mid=(l+r)>>1;
	if(ql<=mid)
		Link(ch[o][0],fl,x,ql,qr,l,mid);
	if(qr>mid)          
		Link(ch[o][1],fl,x,ql,qr,mid+1,r);
}

void Dri(int u,int fa=0)
{
	mxd[u]=dep[u]=dep[fa]+1;
	for(int v:G[u])if(v!=fa)
	{
		Dri(v,u);
		if(mxd[u]<mxd[v])
		{
			mxd[u]=mxd[v];
			hson[u]=v;
		}
	}
}

void Dfs(int u,int fa=0,int x=0)
{
	if(hson[u])
	{
		Dfs(hson[u],u,x+1);
		memcpy(rt[u],rt[hson[u]],4*sizeof(int));
	}

	Link(rt[u][2],1,u,dep[u]+L,dep[u]+R);
	Link(rt[u][3],1,n+u,dep[u]+L,dep[u]+R);
	for(int i=0;i<4;++i)if((have[u]>>i)&1)
		Link(rt[u][i&1],0,((i&2)?n:0)+u,dep[u]+L,dep[u]+R);
	Attach(ud[x][0],u,0);
	Attach(ud[x][1],n+u,1);
	for(int i=0;i<4;++i)if((have[u]>>i)&1)
	{
		Attach(vd[x][i],((i&2)?n:0)+u,i&1);
		Attach(vd[x][4^i],((i&2)?0:n)+u,i&1);
	}

	Insert(rt[u][0],0,u,dep[u]);
	Insert(rt[u][1],0,n+u,dep[u]);
	for(int i=0;i<4;++i)if((have[u]>>i)&1)
	{
		Insert(rt[u][2^(i&1)],1,((i&2)?n:0)+u,dep[u]);
		Insert(rt[u][!(i&1)],0,((i&2)?0:n)+u,dep[u]);
	}
	for(int v:G[u])if(v!=hson[u]&&v!=fa)
	{
		int b=x+mxd[u]-dep[u]+1;
		Dfs(v,u,b);

		for(int i=0;i<=mxd[v]-dep[v];++i)
		{
			Link(rt[u][2],1,ud[b+i][0],dep[u]+L-i-1,dep[u]+R-i-1);
			Link(rt[u][3],1,ud[b+i][1],dep[u]+L-i-1,dep[u]+R-i-1);
			Attach(vd[x+i][0],ud[b+i][0],0);
			Attach(vd[x+i][1],ud[b+i][1],1);
		}
		for(int i=0;i<=mxd[v]-dep[v];++i)
			for(int j=0;j<4;++j)if(vd[b+i][j])
			{
				Link(rt[u][j&1],0,vd[b+i][j],dep[u]+L-i-1,dep[u]+R-i-1);
				Attach(vd[x+i][j],vd[b+i][j],j&1);
			}

		for(int i=0;i<4;++i)
			Merge(rt[u][i],rt[v][i],i&1);
	}
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&L,&R);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}

	for(int i=1,a,ty;i<=m;++i)
	{
		scanf("%d%d",&a,&ty);
		have[a]|=(1<<ty);
	}

	tot=n+n;
	Dri(1);
	Dfs(1);

	A::Work();

	for(int i=1;i<=n+n;++i)
	{
		for(int j=1;j<=n+n;++j)
			cout<<A::Cn[i][j]<<" ";
		cout<<endl;
	}

	for(int i=1;i<=n;++i)
		if(A::col[i]==A::col[n+i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
