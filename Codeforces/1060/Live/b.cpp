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

LL n,x;

int Calc(LL x)
{
	int res=0;
	for(;x;res+=x%10,x/=10);
	return res;
}

int main()
{
	scanf("%lld",&n);
	x=n/2;
	int ans=0;
	for(int i=0;i<=500000&&i<=x;++i)
		GetMax(ans,Calc(x-i)+Calc(n-x+i));
	for(LL i=9;i<=n;i=i*10+9)
		GetMax(ans,Calc(i)+Calc(n-i));
	printf("%d",ans);
	return 0;
}
