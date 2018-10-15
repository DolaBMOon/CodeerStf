#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> bool GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=1e5+10;
const int B=20;

vector<int> d[N],G[N],R[N],fl[N];

int n,a[N];

void Prework()
{
	for(int i=1;i<N;++i)
		for(int j=i;j<N;j+=i)
			d[j].emplace_back(i);
}

int dfn[N],tm,st[N][B],fa[N],dep[N];

void Dfs(int u)
{
	dfn[u]=++tm;
	dep[u]=dep[st[u][0]=fa[u]]+1;
	for(int i=1;i<B;++i)
		st[u][i]=st[st[u][i-1]][i-1];
	for(int v:G[u])if(v!=fa[u])
	{
		fa[v]=u;
		Dfs(v);
	}
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

bool Cmp(int x,int y)
{
	return dfn[x]<dfn[y];
}

int main()
{
	Prework();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		for(int x:d[a[i]])
			R[x].emplace_back(i);
	}
	Dfs(1);
	for(int i=1,f=0;i<N;++i)
	{
		for(int v:R[i])
		{
			if(f)
				f=Lca(f,v);
			else
				f=v;
		}
		for(int v:R[i])
	}
	return 0;
}
