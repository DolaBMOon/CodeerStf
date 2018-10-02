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

long long Mul(long long x,long long y,long long mo)
{
	long long tmp=((unsigned long long)x*y-(unsigned long long)((long double)x/mo*y+1.0e-8)*mo);
	return (tmp<0)?(tmp+mo):tmp;
}

int main()
{
	long long a,b,c;
	cin>>a>>b>>c;
	cout<<Mul(a%c,b%c,c);
	return 0;
}
