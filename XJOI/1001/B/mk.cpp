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

int n;

int main()
{
	srand((unsigned long long)new char);
	n=10;
	int sm=0;
	for(int i=1;i<=n;++i)
	{
		if(sm&&(rand()&1))
		{
			putchar(')');
			--sm;
		}
		else
		{
			putchar('(');
			++sm;
		}
		if(sm==n-i)
		{
			while(sm--)
				putchar(')');
			return 0;
		}
	}
	return 0;
}
