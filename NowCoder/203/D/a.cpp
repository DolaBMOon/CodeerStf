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

const int N=2333;

int n,m,a[N];

void Work()
{
	scanf("%lld%lld",&n,&m);
	int cnt=0;
	double ans=0;
	for(int i=1,b;i<=n;++i)
	{
		scanf("%lld%lld",a+i,&b);
		cnt+=b;
		ans+=a[i];
	}
	GetMin(cnt,m);
	sort(a+1,a+n+1,greater<int>());
	for(int i=1;i<=cnt;++i)
		ans-=a[i]*0.5;
	printf("%.1lf\n",ans);
}

signed main()
{
	int T;
	for(scanf("%lld",&T);T--;)
		Work();
	return 0;
}
