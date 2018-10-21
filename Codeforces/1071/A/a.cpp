#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

int a,b,n;
vector<int> A,B;

signed main()
{
	scanf("%lld%lld",&a,&b);
	for(;(2+n)*(n+1)/2<=a+b;++n);
	for(int i=n;i>=1;--i)
	{
		if(a>=i)
		{
			a-=i;
			A.push_back(i);
		}
		else
			B.push_back(i);
	}
	printf("%lld\n",(int)A.size());
	for(int i:A)
		printf("%lld ",i);
	printf("\n%lld\n",(int)B.size());
	for(int i:B)
		printf("%lld ",i);
	return 0;
}
