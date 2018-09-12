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

#define int long long

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

int a,b;

bool Check(int x)
{
	if(x<=0)
		return false;
	int y=a-x;
	if(y<=0)
		return false;
	int d=Gcd(x,y);
	return x/d*y==b;
}

void Work()
{
	int d=Gcd(a,b);
	a/=d;
	b/=d;
	double delta=(double)a*a-4*b;
	if(delta<0)
	{
		puts("No Solution");
		return;
	}
	delta=sqrt(delta);
	int x0=(-a+delta)/(-2)*d,x1=(-a-delta)/(-2)*d;
	a*=d;
	b*=d;
	if(Check(x0))
		printf("%lld %lld\n",x0,a-x0);
	else if(Check(x1))
		printf("%lld %lld\n",x1,a-x1);
	else
		puts("No Solution");
}

signed main()
{
	while(~scanf("%lld%lld",&a,&b))
		Work();
	return 0;
}
