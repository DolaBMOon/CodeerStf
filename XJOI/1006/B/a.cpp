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

const int N=35;
const int MOD=1e9+7;

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Mul(int x,int y)
{
	return (long long)x*y%MOD;
}

int d[N],n;
int C[N][N],dp[N][N][2];

int Song(int k,int cnt,int lim)
{
	int &res=dp[k][cnt][lim];
	if(~res)
		return res;
	if(!k)
		return res=1;
	res=0;
	for(int i=0,nl;i<=(lim?d[k]:1);++i)
	{
		nl=lim&&(i==d[k]);
		if(i)
		{
			for(int j=1;j<=cnt;j+=2)
				SU(res,Mul(C[cnt][j],Song(k-1,cnt,nl)));
			SU(res,Song(k-1,cnt+1,nl));
		}
		else
		{
			for(int j=0;j<=cnt;j+=2)
				SU(res,Mul(C[cnt][j],Song(k-1,cnt,nl)));
		}
	}
	return res;
}

int main()
{
	int x;
	scanf("%d",&x);
	for(;x;x>>=1)
		d[++n]=x&1;
	for(int i=0;i<=n;++i)
	{
		C[i][0]=1;
		for(int j=1;j<=i;++j)
			C[i][j]=U(C[i-1][j-1],C[i-1][j]);
	}
	memset(dp,-1,sizeof dp);
	printf("%d\n",Song(n,0,1));
	return 0;
}
