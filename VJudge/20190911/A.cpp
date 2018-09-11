#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<queue>
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

#define int long long
#define double long double

const int N=50000+10;

int n,m;

int Calc(int x,int y)
{
	return x*x+100000*x+y*y-100000*y+x*y;
}

bool Check(int w)
{
	int cnt=0;
	for(int i=1;i<=n&&cnt<m;++i)
	{
		int b=(i-100000),c=i*i+100000*i-w;
		double t=sqrt(b*b-4*c);
		int x0=max((int)ceil((-b-t)/2),1ll),x1=min((int)floor((-b+t)/2),n);
		cnt+=max(0ll,x1-x0+1);
	}
	return cnt>=m;
}

void Work()
{
	scanf("%lld%lld",&n,&m);
	int left=-1e10,mid,right=1e10,res;
	while(left<=right)
	{
		if(Check(mid=(left+right)>>1))
			right=(res=mid)-1;
		else
			left=mid+1;
	}
	printf("%lld\n",res);
}

signed main()
{
	int T;
	for(scanf("%lld",&T);T--;)
		Work();
	return 0;
}
