%:pragma GCC optimize("Ofast")
%:pragma GCC optimize("inline")
#include<cstdio>
#include<iostream>
#include<cmath>

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

#define LL unsigned long long

int main()
{
	LL n;
	cin>>n;
	LL m=sqrt(n),sm=0;
	for(LL i=1;i<=m;++i)
		sm+=n/i;
	for(LL i=m+1,j,k;i<=n;i=j+1)
	{
		k=n/i;
		j=n/k;
		sm+=(j-i+1u)*k;
	}
	cout<<sm;
	return 0;
}
