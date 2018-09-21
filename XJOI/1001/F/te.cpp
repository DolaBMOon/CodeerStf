#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<set>
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

const int N=10;

int n;

vector<int> p,G[N];
set<vector<int> > S;
bool vis[N];

void Dfs(int u)
{
	p.emplace_back(u);
	vis[u]=true;
	random_shuffle(G[u].begin(),G[u].end());
	for(int v:G[u])if(!vis[v])
		Dfs(v);
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	{
		static char s[20];
		scanf("%s",s);
		for(int j=0;j<n;++j)if(s[j]=='Y')
			G[i].emplace_back(j);
	}
	p.reserve(n);
	for(int cc=300000;cc--;)
	{
		memset(vis,0,sizeof vis);
		p.clear();
		Dfs(rand()%n);
		S.insert(p);
	}
	printf("%u",S.size());
	return 0;
}
