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

const int MOD=1e9+7;

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

int n;

int main()
{
	scanf("%d",&n);
	int ans=1;
	for(int i=n+n-1;i>=n;--i)
		ans=Mul(ans,i);
	for(int i=2;i<=n;++i)
		ans=Mul(ans,Qpow(i));
	ans=Mul(ans,2);
	ans-=n;
	if(ans<0)
		ans+=MOD;
	printf("%d",ans);
	return 0;
}
