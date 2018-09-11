#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

int n;

int Calc(int n)
{
	int ans=0;
	for(int x=1;x<=n;++x)
		for(int y=1;y<=n;++y)
			for(int i=1;i<=n/x;++i)
				for(int j=1;j<=n/y;++j)
					ans+=x*j;
	return ans;
}

int Calc2(int n)
{
	int ans=0;
	for(int x=1;x<=n;++x)
	{
		for(int y=1;y<=n;++y)
		{
			ans+=x*(n/x)*y*(n/y);
		}
	}
	return ans;
}

int main()
{
	cin>>n;
	Whats(Calc(n));
	Whats(Calc2(n));
	return 0;
}
