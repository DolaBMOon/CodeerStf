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

int n,q,tp,idx[520],meng[N],id[N],px[N],py[N];

int ch[N][5],sz=1;

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

struct Tree
{

	int fir[N],nxt[N],to[N],tote;
	int fa[N],st[N][B],dep[N],in[N],ou[N],dtm;

	void Adde(int u,int v)
	{
		to[++tote]=v;
		nxt[tote]=fir[u];
		fir[u]=tote;
		to[++tote]=u;
		nxt[tote]=fir[v];
		fir[v]=tote;
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

}Tx,Ty;

int C[N];

void Add(int x,int y,int w)
{
}

int Que(char *s,int u,int v)
{
	int ans=0,nw=1;
	for(int k;*s;++s)
	{
		k=idx[*s];
		nw=ch[nw][k];
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
	for(int i=2;i<=sz;++i)
		Tx.Adde(fail[i],i);
	Tx.Dfs(1);
	for(int i=1;i<=n;++i)
		scanf("%d",meng+i);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Ty.Adde(u,v);
	}
	Ty.Dfs(1);
	for(int i=1;i<=n;++i)
	{
		px[i]=Tx.dfn[id[i]];
		py[i]=Ty.dfn[i];
		Add(px[i],py[i],meng[i]);
	}

	scanf("%d",&q);
	int last_ans=0;
	for(int i=1,op,x,y;i<=q;++i)
	{
		scanf("%d%d%d",&op,&x,&y);
		x^=(tp*last_ans);
		y^=(tp*last_ans);
		if(op&1)
		{
			scanf("%s",s);
			printf("%d\n",last_ans=Que(s,x,y));
		}
		else
		{
			Add(px[x],py[x],y-meng[x]);
			meng[x]=y;
		}
	}
	return 0;
}
