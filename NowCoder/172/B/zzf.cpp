#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<map>

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

#define int long long

int K;map<int,int> dp[20];vector<int> vec;

inline int Dfs(int x,int lim,int val,int zero)
{
	if(x==(int)vec.size())
		return val <= K;
	if(!lim&&!zero&&dp[x].find(val)!=dp[x].end())
		return dp[x][val];
	int ans = 0;
	int up = lim ? vec[x] : 9;
	ans+=Dfs(x + 1,0==up,val*(zero?1:0),zero);
	for(int i = 1;i <= up;i++)
		ans += Dfs(x + 1,lim && i == up,val*i,0);
	if(!lim && !zero)
		dp[x][val] = ans;
	return ans;
}

inline int Solve(int len,int k)
{
	if(len<0||k<0)
		return 0;
	K=k;
	vec.clear();
	while(len)
	{
		vec.emplace_back(len%10);
		len/=10;
	}
	reverse(vec.begin(),vec.end());
	for(int i=0;i<(int)vec.size();i++)
		dp[i].clear();
	return Dfs(0,1,1,1);
}

signed main()
{
	int L,R,L1,R1;
	scanf("%lld%lld%lld%lld",&L,&R,&L1,&R1);
	printf("%lld\n",Solve(R,R1)-Solve(R,L1-1)-Solve(L-1,R1)+Solve(L-1,L1-1));
	return 0;
}
