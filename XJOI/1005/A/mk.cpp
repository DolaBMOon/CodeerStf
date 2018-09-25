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

int n,k;

int main()
{
	srand((unsigned long long)new char);
	n=100000;
	k=233;
	cout<<n<<" "<<k<<endl;
	for(int i=1;i<=n;++i)
		cout<<(rand()^((long long)rand()<<32))%1000000000000000000ll<<" ";
	return 0;
}
