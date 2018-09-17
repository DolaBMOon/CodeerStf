#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

const int INF=0x3f3f3f3f;

int n;
int dp[8];

int main()
{
	scanf("%d",&n);
	memset(dp,0x3f,sizeof dp);
	dp[0]=0;
	char s[10];
	for(int i=1,c,t;i<=n;++i)
	{
		scanf("%d%s",&c,s);
		t=0;
		for(char *j=s;*j;++j)
			t^=1<<(*j-'A');
		for(int j=0;j<8;++j)
			GetMin(dp[j|t],dp[j]+c);
	}
	if(dp[7]<INF)
		printf("%d",dp[7]);
	else
		puts("-1");
	return 0;
}
