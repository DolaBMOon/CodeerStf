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

long long n;

int main()
{
	int cnt=0;
	long long a=0;
	cin>>n;
	long long m=n;
	while(m>0)
	{
		a=a*10+9;
		m/=10;
		++cnt;
	}
	--cnt;
	a/=10;
	long long b=n-a;
	long long res=cnt*9;
	while(b>0)
	{
		int r=b%10;
		res+=r;
		b/=10;
	}
	cout<<res;
	return 0;
}
