#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=100000+10;

char s[N],t[N];
int lens,lent;

bool match[N];
int fail[N];

namespace BruteSolver
{

	int dp[2333][2333][2];

	void Solve()
	{
		for(int i=1;i+lent-1<=lens;++i)
		{
			dp[i][i+lent-1][0]=match[i];
			dp[i][i+lent-1][1]=match[i];
		}
		for(int l=lent+1;l<=lens;++l)
		{
			for(int i=1,j=l;i+l-1<=lens;++i,++j)
			{
				dp[i][j][0]=dp[i+1][j][1]&&dp[i][j-1][1];
				dp[i][j][1]=dp[i+1][j][0]||dp[i][j-1][0];
			}
		}
		puts(dp[1][lens][0]?"pty":"cqf");
	}

}

namespace Songer
{

	void Song()
	{
		bool ans=false;
		for(int i=1;i+lent-1<=lens&&!ans;++i)
			ans|=(match[i]&&i-1==lens-(i+lent-1));
		for(int i=1;i+lent<=lens&&!ans;++i)
			ans|=(match[i]&&match[i+1]&&i-1==lens-(i+lent));
		for(int i=1;i+lent+1<=lens&&!ans;++i)
			ans|=(match[i]&&match[i+2]&&i-1==lens-(i+lent+1));
		puts(ans?"pty":"cqf");
	}

}

void Work()
{
	scanf("%s%s",s+1,t+1);
	lens=strlen(s+1);
	lent=strlen(t+1);
	for(int i=2,j;i<=lent;++i)
	{
		j=fail[i-1];
		for(;j&&t[j+1]!=t[i];j=fail[j]);
		fail[i]=((t[j+1]==t[i])?(j+1):0);
	}
	memset(match,0,sizeof match);
	for(int i=1,j=0;i<=lens;++i)
	{
		for(;j&&t[j+1]!=s[i];j=fail[j]);
		j+=(t[j+1]==s[i]);
		if(j==lent)
			match[i-lent+1]=true;
	}
	if(lens<=2000)
		BruteSolver::Solve();
	else
		Songer::Song();
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
