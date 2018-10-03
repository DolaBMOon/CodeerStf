#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

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

int n,m,k,du[N];
vector<int> G[N];

int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		++du[v];
	}
	queue<int> Q;
	for(int i=1;i<=n;++i)if(!du[i])
		Q.push(i);
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int v:G[u])if(!(v=
	}
	return 0;
}
