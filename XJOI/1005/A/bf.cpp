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

#define int long long

const int N=1e5+10;

int n,k;
int a[N];

int Get(int x)
{
	if(!x)
		return 0;
	int res=1;
	for(;x;x/=10)
	{
		int t=x%10;
		res*=t;
	}
	return res;
}

bool Check(int x,int y)
{
	x=Get(x);
	y=Get(y);
	for(int i=0;i<10000;++i)if(abs(pow(i,k)-x*y)<1e-5)
		return false;
	return true;
}

signed main()
{
	scanf("%lld%lld",&n,&k);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		for(int j=1;j<i;++j)
			ans+=Check(a[i],a[j]);
	}
	printf("%lld",ans);
	return 0;
}
