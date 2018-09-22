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

const int MOD=1e9+7;

void SU(int &a,int b)
{
	((a+=b)>=MOD)?(a-=MOD):a;
}

const int N=55;
const int K=10;
const int MS=(1<<K)+10;

int n,ki,S,cnt0[MS],cnt1[MS];
int dp[N+N][MS][N+N],*f[MS],*g[MS];

int main()
{
	scanf("%d%d",&n,&ki);
	--ki;
	S=(1<<ki)-1;
	for(int i=1;i<=S;++i)
		cnt1[i]=cnt1[i^(i&(-i))]+1;
	for(int i=0;i<=S;++i)
		cnt0[i]=ki-cnt1[i];
	dp[0][0][N]=1;
	for(int i=1;i<=n+n;++i)
	{
		for(int j=0;j<=S;++j)
		{
			f[j]=dp[i-1][j]+N;
			g[j]=dp[i][j]+N;
		}
		//Put A
		for(int j=0;j<=S;++j)
			for(int k=-i,t;k<=i;++k)if((k>=0||cnt0[j]<-k)&&(t=f[j][k]))
				SU(g[((j<<1)^1)&S][k+1],f[j][k]);
		//Put B
		for(int j=0;j<=S;++j)
			for(int k=-i,t;k<=i;++k)if((k<=0||cnt1[j]<k)&&(t=f[j][k]))
				SU(g[(j<<1)&S][k-1],f[j][k]);
	}
	int ans=0;
	for(int i=0;i<=S;++i)
		SU(ans,g[i][0]);
	printf("%d",ans);
	return 0;
}
