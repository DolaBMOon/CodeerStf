#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

double h,s,s2,v,l,k;
int n,ans;

int main()
{
	scanf("%lf%lf%lf%lf%lf%d",&h,&s,&v,&l,&k,&n);
	s2=s+l;
	for(int i=0;i<n;++i)
	{
		double x=(s-i)/v,x2=(s2-i)/v;
		x=h-5*x*x;
		x2=h-5*x2*x2;
		GetMin(x,k);
		GetMax(x2,0.0);
		if(-0.0001<x-x2)
			++ans;
	}
	printf("%d",ans);
	return 0;
}
