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
double f1[N],f2[N];

int main()
{
	scanf("%d",&n);
	f1[n]=1;
	f2[n]=1;
	for(int i=n-1;i>1;--i)
	{
		double p=1.0/i;
		f1[i]=p*(f1[i+1]+1)+(1-p)*f1[i+1];
		f2[i]=p*(f2[i+1]+2*f1[i+1]+1)+(1-p)*f2[i+1];
	}
	f2[1]=f2[2];
	double ans=0;
	for(int i=1;i<=n;++i)
		ans+=f2[i];
	printf("%.2lf",ans);
	return 0;
}
