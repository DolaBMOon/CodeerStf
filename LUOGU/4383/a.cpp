#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define int long long

#define Pir pair<int,int>
#define fir first
#define sec second
#define makr(x,y) make_pair(x,y)

const int N=3e5+10;

int n,k;
vector<Pir> G[N];
Pir dp[N][3];
int delta;

Pir operator+(const Pir& a,const Pir& b)
{
	return {a.fir+b.fir,a.sec+b.sec};
}

void operator+=(Pir& a,const Pir& b)
{
	a=a+b;
}

Pir GetMax(int u)
{
	return max(dp[u][0],max(dp[u][1],dp[u][2]));
}

int vis[N],tm;

void Dfs(int u)
{
	vis[u]=tm;
	dp[u][0]=Pir(0,0);
	dp[u][1]=dp[u][2]=Pir(delta,1);
	static Pir x;
	for(Pir p:G[u])if(vis[p.sec]!=tm)
	{
		Dfs(p.sec);
		x=GetMax(p.sec);
		dp[u][2]=max(dp[u][2]+x,dp[u][1]+dp[p.sec][1]+Pir(p.fir-delta,-1));
		dp[u][1]=max(dp[u][1]+x,dp[u][0]+dp[p.sec][1]+Pir(p.fir,0));
		dp[u][0]+=x;
	}
}

int ans=-1;

bool Check(int d)
{
	int rt=rand()%n+1;
	delta=d;
	++tm;
	Dfs(rt);
	Pir p=GetMax(rt);
	if(p.sec<=k+1)
	{
		ans=p.fir-(k+1)*d;
		return true;
	}
	return false;
}

signed main()
{
	scanf("%lld%lld",&n,&k);
	int tot=0;
	for(int i=1,u,v,d;i<n;++i)
	{
		scanf("%lld%lld%lld",&u,&v,&d);
		G[u].emplace_back(d,v);
		G[v].emplace_back(d,u);
		tot+=abs(d);
	}
	int left=-tot,mid,right=tot;
	while(left<=right)
		if(Check(mid=((left+right)>>1)))
			left=mid+1;
		else
			right=mid-1;
	printf("%lld",ans);
	return 0;
}
