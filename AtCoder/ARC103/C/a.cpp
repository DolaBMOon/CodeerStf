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

const int N=1e5+10;
const int INF=0x3f3f3f3f;

int n,cnt[2][N],ans;

int main()
{
	scanf("%d",&n);
	for(int i=1,a;i<=n;++i)
	{
		scanf("%d",&a);
		++cnt[i&1][a];
	}
	for(int i=N-1,mx=0;i>=1;--i)
	{
		GetMax(ans,cnt[1][i]+mx);
		GetMax(mx,cnt[0][i]);
	}
	for(int i=N-1,mx=0;i>=1;--i)
	{
		GetMax(ans,cnt[0][i]+mx);
		GetMax(mx,cnt[1][i]);
	}
	printf("%d",n-ans);
	return 0;
}
