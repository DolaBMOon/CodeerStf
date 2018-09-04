#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

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
#define sec second

const int MOD=64123;
const int N=2000;

int n,k,w;

Pir p[N];
int ans,dp[N][N];
vector<int> G[N];

void Update(int o)
{
}

int main()
{
	scanf("%d%d%*d",&n,&k);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].fir);
		p[i].sec=i;
	}
	for(int i=1,x,y;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		G[x].emplace_back(y);
		G[y].emplace_back(x);
	}
	Dfs(1);
	sort(p+1,p+n+1,greater<Pir>());
	for(int i=1;i<=n;++i)
		dp[i][0]=1;
	int ans=0;
	for(int i=1;i<=n;++i)
		Update(p[i].sec);
	return 0;
}
