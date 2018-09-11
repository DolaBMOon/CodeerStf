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

const int N=20;

int n;

//int C[N][N];

signed main()
{
	//for(int i=0;i<N;++i)
	//{
	//	C[i][0]=1;
	//	for(int j=1;j<=i;++j)
	//		C[i][j]=C[i-1][j-1]+C[i-1][j];
	//}
	//scanf("%lld",&n);
	//++n;
	//int ans=0;
	//for(int i=0;i<n;++i)
	//{
	//	ans+=C[n+i][n-i];
	//}
	//printf("%lld",ans);
	return 0;
}
