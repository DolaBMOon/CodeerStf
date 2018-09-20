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

#define Pir pair<int,int>
#define fir first
#define sec second

#define int long long

const int N=55;

int n,a[N],s[N],sx,sy,ex,ey;

signed main()
{
	scanf("%lld%lld%lld%lld%lld",&n,&sx,&sy,&ex,&ey);
	if(sx>ex)
		swap(sx,ex);
	if(sy>ey)
		swap(sy,ey);
	++sx;
	++ex;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		s[i]=s[i-1]+a[i];
	}
	int ans=0x3f3f3f3f3f3f3f3f;
	for(int i=1;i<sx;++i)
		GetMin(ans,s[sx]-s[i-1]+a[i]*(ey-sy-1)+s[ex]-s[i-1]);
	for(int i=sx;i<ex;++i)
		GetMin(ans,s[ex]-s[sx-1]+a[i]*(ey-sy));
	for(int i=ex;i<=n;++i)
		GetMin(ans,s[i]-s[sx-1]+a[i]*(ey-sy-1)+s[i]-s[ex-1]);
	printf("%lld",ans);
	return 0;
}
