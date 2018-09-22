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

#define LL long long

const int MOD=1e9+9;
const int N=233;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,x=Mul(x,x))if(y&1)
		res=Mul(res,x);
	return res;
}

void SU(int &x,int y)
{
	x=(((x+y)>=MOD)?(x+y-MOD):(x+y));
}

int n,l,c[N],dp[N][N],jc[N],njc[N];

void Prework()
{
	jc[0]=1;
	for(int i=1;i<=n;++i)
		jc[i]=Mul(jc[i-1],i);

	njc[n]=Qpow(jc[n]);
	for(int i=n-1;i>=0;--i)
		njc[i]=Mul(njc[i+1],i+1);
}

int main()
{
	scanf("%d%d",&n,&l);
	Prework();
	for(int i=1;i<=n;++i)
		scanf("%d",c+i);
	dp[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0,d,f=njc[n-i];j<i;++j)
		{
			d=(c[j]!=c[i]);
			for(int k=(j>0),t;(t=dp[j][k]);++k)
				SU(dp[i][k+d],Mul(t,Mul(jc[n-j-1],f)));
		}
	}
	printf("%d\n",dp[n][l]);
	return 0;
}
