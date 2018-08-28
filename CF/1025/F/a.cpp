//%:pragma GCC optimize("Ofast")
//%:pragma GCC target("sse3","sse2","sse")
//%:pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//%:pragma GCC target("f16c")
//%:pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//%:pragma GCC diagnostic error "-fwhole-program"
//%:pragma GCC diagnostic error "-fcse-skip-blocks"
//%:pragma GCC diagnostic error "-funsafe-loop-optimizations"
//%:pragma GCC diagnostic error "-std=c++14"

#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
That's how everything starts.
*/

#define LL long long

const int N=2002;
const double PI=3.141592653589793;

int n;
double x[N],y[N];

LL Calc(int n)
{
	return (n*(n-1LL))>>1;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%lf%lf",x+i,y+i);
	LL ans=0;
	for(int i=1;i<=n;++i)
	{
		static double p[N+N];
		int totp=0;
		for(int j=1;j<=n;++j)if(i!=j)
			p[++totp]=atan2(x[j]-x[i],y[j]-y[i]);
		sort(p+1,p+totp+1);
		for(int j=1;j<=totp;++j)
			p[j+totp]=p[j]+2*PI;
		for(int j=1,k=1;j<=totp;++j)
		{
			for(;p[k]-p[j]<PI;++k);
			ans+=(LL)Calc(k-j-1)*Calc(totp-k+j);
		}
	}
	printf("%I64d",ans>>1);
	return 0;
}
