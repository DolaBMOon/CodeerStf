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

int n,d;

int main()
{
	srand((unsigned long long)new char);
	n=100;
	d=0;
	cout<<n<<" "<<d<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<4;++j)
			putchar('a'+rand()%26);
		cout<<endl;
	}
	return 0;
}
