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

int n,m,x;
int a[N],b[N],h[N];

signed main()
{
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1;i<=m;++i)
		scanf("%lld",b+i);
	memset(h,0x3f,sizeof h);
	h[0]=0;
	for(int i=1;i<=m;++i)
	{
		int sm=0;
		for(int j=i;j<=m;++j)
		{
			sm+=b[j];
			GetMin(h[j-i+1],sm);
		}
	}
	scanf("%lld",&x);
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		int sm=0;
		for(int j=i;j<=n;++j)
		{
			sm+=a[j];
			GetMax(ans,(j-i+1)*(upper_bound(h,h+m+1,x/sm)-h-1));
			//if(ans==6)
			//	Oops();
			//cout<<i<<","<<j<<":"<<sm<<":"<<upper_bound(h,h+m+1,x/sm)-h-1<<endl;
		}
	}
	printf("%lld",ans);
	return 0;
}
