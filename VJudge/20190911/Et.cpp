#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

const int N=233;

int n;
int f[N];

signed main()
{
	scanf("%lld",&n);
	f[1]=4;
	f[2]=12;
	f[3]=33;
	for(int i=4;i<=n;++i)
		f[i]=f[i-1]*4-f[i-2]*4+f[i-3];
	cout<<f[n]<<endl;
	return 0;
}
