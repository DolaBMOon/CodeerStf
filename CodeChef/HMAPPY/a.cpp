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

#define int long long

const int N=1e5+10;

int n,m,A[N],B[N];

bool Check(int x)
{
	int rem=m;
	for(int i=1;i<=n&&rem>=0;++i)
		rem-=max(0ll,A[i]-x/B[i]);
	return rem>=0;
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	int sm=0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",A+i);
		sm+=A[i];
	}
	if(sm<=m)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;++i)
		scanf("%lld",B+i);
	int ans=1;
	for(int l=1,mid,r=0x3f3f3f3f3f3f3f3f;l<=r;)
	{
		if(Check(mid=(l+r)>>1))
			r=(ans=mid)-1;
		else
			l=mid+1;
	}
	printf("%lld",ans);
	return 0;
}
