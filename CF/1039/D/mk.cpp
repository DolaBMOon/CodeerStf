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

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n;

int main()
{
	srand((unsigned long long)new char);
	n=100000;
	cout<<n<<endl;
	for(int i=2;i<=n;++i)
		cout<<Randint(1,i-1)<<" "<<i<<endl;
	return 0;
}
