#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
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

const int N=2e5+10;

int n,m,col[N];
vector<int> G[N];

void Dfs(int u,int dep=1)
{
	col[u]=(dep&1);
	for(int v:G[u])if(col[v]==-1)
		Dfs(v,dep+1);
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	for(int i=1;i<=n;++i)
		if(G[i].empty())
		{
			puts("NIE");
			return 0;
		}
	puts("TAK");
	memset(col,-1,sizeof col);
	for(int i=1;i<=n;++i)if(col[i]==-1)
		Dfs(i);
	for(int i=1;i<=n;++i)
		puts(col[i]?"S":"K");
	return 0;
}
