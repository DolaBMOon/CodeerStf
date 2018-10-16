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

unsigned int a, b, c;
unsigned int _p;
unsigned int Rand() {
	a^=b^c>>1;
	b^=a<<5^c>>3;
	c^=a>>2^b<<4;
	return a>>2|233;
}

int main()
{
	cin>>a>>b>>c>>_p;
	unsigned long long ans=1,ans2=1;
	const unsigned int p=_p;
	for(int i=500000000;i;--i)
	{
		ans=ans*Rand()%p;
		ans2=ans2*Rand()%p;
	}
	cout<<(int)(ans*ans2%p);
	return 0;
}
