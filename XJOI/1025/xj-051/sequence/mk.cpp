#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

int n,m;

int main()
{
	n=5e5;
	m=5e5;
	cout<<n<<" "<<m<<endl;
	for(int i=1,l,r,k;i<=m;++i)
	{
		l=rand()%n+1;
		r=rand()%n+1;
		if(l>r)
			swap(l,r);
		k=rand()%21;
		cout<<l<<" "<<r<<" "<<k<<endl;
	}
	return 0;
}
