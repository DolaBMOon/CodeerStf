#pragma GCC optimize(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>

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

const int N=110;

int n;
string s,dp[N][N];

void Update(string &s,const string &t)
{
	if(s.empty())
		s=t;
	else
		GetMin(s,t);
}

int main()
{
	cin>>s;
	n=s.size();
	dp[1][1]="(";
	for(int i=1;i<n;++i)
		if(s[i]=='(')
		{
			for(int j=i;j>=1;--j)
				for(int k=n-1;k>=0;--k)if(!dp[j][k].empty())
					Update(dp[j+1][k+1],dp[j][k]+"(");
		}
		else
		{
			for(int j=i;j>=1;--j)
				for(int k=1;k<=n;++k)if(!dp[j][k].empty())
					Update(dp[j+1][k-1],dp[j][k]+")");
		}
	string ans="A";
	for(int i=1;i<=n;++i)if(!dp[i][0].empty())
		GetMin(ans,dp[i][0]);
	cout<<ans<<endl;
	return 0;
}
