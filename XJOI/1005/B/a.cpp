#pragma GCC optimize(2)
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

const int N=1e6+10;
const int INF=0x3f3f3f3f;

int n,k,dp[N][3];//0: not used, 1: used before fa, 2: used after fa
vector<int> G[N];

void Dfs(int u,int fa=0)
{
	int nd=k-(fa>0),sm=0;
	vector<int> delta;
	for(int v:G[u])if(v!=fa)
	{
		Dfs(v,u);
		int t=max(dp[v][0],dp[v][2]);
		if(~dp[v][1])
		{
			sm+=dp[v][1];
			delta.emplace_back(t-dp[v][1]);
		}
		else
		{
			--nd;
			sm+=t;
		}
		dp[u][0]+=max(dp[v][0],dp[v][1]);
	}
	sort(delta.rbegin(),delta.rend());
	if(nd>=0&&(int)delta.size()>=nd)
	{
		dp[u][1]=sm+1;
		for(int i=0;i<nd;++i)
			dp[u][1]+=delta[i];
	}
	else
		dp[u][1]=-1;
	if(fa&&(++nd)>=0&&(int)delta.size()>=nd)
		dp[u][2]=(nd?(dp[u][1]+delta[nd-1]):(sm+1));
	else
		dp[u][2]=-1;
	//if(u==4)
	//	cout<<dp[u][0]<<","<<dp[u][1]<<","<<dp[u][2]<<endl;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	Dfs(1);
	printf("%d\n",max(dp[1][0],dp[1][1]));
	return 0;
}
