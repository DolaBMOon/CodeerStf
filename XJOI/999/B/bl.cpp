#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<cmath>

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

const int N=8;

int main()
{
	int ans=0;
	for(int a=1;a<=N;++a)
		for(int c=1;c<=N;++c)
			for(int b=1;b<=N;++b)
				for(int d=1;d<=N;++d)
				{
					if(a!=c&&pow(a,b)==pow(c,d))
					{
						cout<<a<<"^"<<b<<"="<<c<<"^"<<d<<endl;
						++ans;
					}
				}
	cout<<ans<<endl;
	return 0;
}
