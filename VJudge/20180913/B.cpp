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

#define Pir pair<double,double>

const int N=5000;

int n,cnt;

int main()
{
	scanf("%d",&n);
	double sm=0;
	for(int i=1;i<=n+n;++i)
	{
		double a;
		scanf("%lf",&a);
		a=a-floor(a);
		cnt+=(a==0);
		sm-=a;
	}
	int l=max(0,n-cnt),r=min(n,2*n-cnt);
	double ans=1e100;
	for(int i=l;i<=r;++i)
		GetMin(ans,abs(sm+i));
	printf("%.3lf",ans);
	return 0;
}
