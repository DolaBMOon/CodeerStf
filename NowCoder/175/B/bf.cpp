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

const int N=2333;

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

int n,a[N],ans;

signed main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		scanf("%lld",a+i);
	for(int i=1;i<=n;++i)
		for(int j=i;j<=n;++j)
		{
			int d=0;
			for(int k=i;k<=j;++k)
				d=Gcd(d,a[k]);
			for(int k=i;k<=j;++k)if(a[k]==d)
				GetMax(ans,j-i+1);
		}
	printf("%lld",ans);
	return 0;
}
