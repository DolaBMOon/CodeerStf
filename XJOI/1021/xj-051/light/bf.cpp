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
int fir[N],nxt[N],to[N],tote;

int ch[N][5],sz=1;

vector<int> S[N];

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
	S[nw].push_back(u);
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

int fa[N],st[N][B],dep[N];

void Dfs(int u)
{
	dep[u]=dep[st[u][0]=fa[u]]+1;
	for(int i=1;i<B;++i)
		st[u][i]=st[st[u][i-1]][i-1];
	for(int i=fir[u],v;i;i=nxt[i])if((v=to[i])!=fa[u])
	{
		fa[v]=u;
		Dfs(v);
	}
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

bool Onit(int x,int y)
{
	if(dep[y]<dep[x])
		return false;
	for(int i=B-1,k;i>=0;--i)if(dep[k=st[y][i]]>=dep[x])
		y=k;
	return x==y;
}

bool OnThePath(int x,int u,int v)
{
	return (Onit(x,u)||Onit(x,v))&&(dep[x]>=dep[Lca(u,v)]);
}

LL Song(char *s,int u,int v)
{
	LL ans=0;
	int nw=1;
	static int cnt[5];
	memset(cnt,0,sizeof cnt);
	for(int k,o;*s;++s)
	{
		k=idx[*s];
		++cnt[k];
		nw=ch[nw][k];
		o=nw;
		for(;o;o=fail[o])
		{
			for(int i=0,p;i<(int)S[o].size();++i)
			{
				p=S[o][i];
				//Whats(p);
				if(OnThePath(p,u,v))
				{
					ans+=meng[p];
				}
			}
		}
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
	for(int i=1;i<=n;++i)
		scanf("%d",meng+i);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		Adde(u,v);
	}
	Dfs(1);
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
			printf("%lld\n",Song(s,x,y));
		}
		else
			meng[x]=y;
	}
	return 0;
}
