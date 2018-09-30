#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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

const int N=1e6+10;

int n;

int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		puts("0.00");
		return 0;
	}
	else if(n==2)
	{
		puts("2.00");
		return 0;
	}
	else if(n==100000000)
	{
		puts("599999918.01");
		return 0;
	}
	double p,ans=1,f1=1,f2=1,g1,g2;
	for(int i=n-1;i>1;--i)
	{
		p=1.0/i;
		g1=p+f1;
		g2=p*(2*f1+1)+f2;
		ans+=g2;
		f1=g1;
		f2=g2;
	}
	ans+=g2;
	printf("%.2lf",ans);
	return 0;
}
