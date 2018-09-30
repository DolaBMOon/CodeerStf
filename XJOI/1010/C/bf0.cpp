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

const int MOD=1e9+7;
const int N=2e6+10;

int n,l[N],r[N],ls[N],ed,dp[N][N][2],f[N][N];

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",l+i);
		r[i]=l[i]+n;
		//ls[++ed]=l[i];
		//ls[++ed]=r[i];
	}
	//sort(ls+1,ls+ed+1);
	//for(int i=1;i<=n;++i)
	//{
	//	l[i]=lower_bound(ls+1,ls+ed+1,l[i])-ls;
	//	r[i]=lower_bound(ls+1,ls+ed+1,r[i])-ls;
	//}
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)
			{
				if(r[k]<r[j])
				{
				}
			}
		}
	}
	return 0;
}
