#pragma GCC opimitze(2)
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

const int N=3000;
const int MOD=1e9+7;

void SU(int &a,int b)
{
	((a+=b)>=MOD)?(a-=MOD):0;
}

char ch0[N],ch1[N];
int s0[N],len0,s1[N],len1,dp[N][N];

int main()
{
	scanf("%s%s",ch0+1,ch1+1);
	len0=strlen(ch0+1);
	len1=strlen(ch1+1);
	for(int i=1;i<=len0;++i)
		s0[i]=s0[i-1]+((ch0[i]=='(')?1:-1);
	for(int i=1;i<=len1;++i)
		s1[i]=s1[i-1]+((ch1[i]=='(')?1:-1);
	if(s0[len0]+s1[len1])
		return puts("0"),0;
	dp[0][0]=1;
	for(int i=0;i<=len0;++i)
		for(int j=0;j<=len1;++j)if(s0[i]+s1[j]>=0)
		{
			if(i)
				SU(dp[i][j],dp[i-1][j]);
			if(j)
				SU(dp[i][j],dp[i][j-1]);
		}
	printf("%d",dp[len0][len1]);
	return 0;
}
