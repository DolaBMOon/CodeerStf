#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<queue>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=2e5+10;

int n,m,cnt[N][2];
char s[N];
vector<int> G[N];
bool ban[N];

int main()
{
	scanf("%d%d%s",&n,&m,s+1);
	for(int i=1;i<=n;++i)
		s[i]-='A';
	for(int i=1,u,v;i<=m;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
		++cnt[u][s[v]];
		++cnt[v][s[u]];
	}
	queue<int> Q;
	for(int i=1;i<=n;++i)
		if(!cnt[i][0]||!cnt[i][1])
		{
			Q.push(i);
			ban[i]=true;
		}
	while(!Q.empty())
	{
		int u=Q.front();
		Q.pop();
		for(int v:G[u])if(!ban[v]&&!(--cnt[v][s[u]]))
		{
			Q.push(v);
			ban[v]=true;
		}
	}
	for(int i=1;i<=n;++i)if(!ban[i])
		return puts("Yes"),0;
	puts("No");
	return 0;
}
