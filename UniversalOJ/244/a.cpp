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
const int INF=0x3f3f3f3f3f3f3f3f;

int n,a[N],p[N];

signed main()
{
	scanf("%lld",&n);
	++n;
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1;i<=n;++i)
		p[i]=p[i-1]+a[i];
	int id=n,sm=0,ans=INF;
	for(int i=n;i>=1;--i)
	{
		if(a[i]<a[id])
		{
			sm+=(id-i)*a[id]+p[id]-p[i];
			id=i;
		}
		GetMin(ans,(sm+(id-i)*a[id]+p[id]-p[i])*2+(4*i-3)*a[i]);
	}
	printf("%lld",ans);
	return 0;
}
