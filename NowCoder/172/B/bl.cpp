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

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

#define int long long

int Calc(int x)
{
	int res=1;
	while(x)
	{
		res*=x%10;
		x/=10;
	}
	return res;
}

signed main()
{
	int cnt=0;
	for(int i=0;i<=10000;++i)
		if(Calc(i)<=57)
		{
			++cnt;
			Whats(i);
		}
	cout<<cnt<<endl;
	return 0;
}
