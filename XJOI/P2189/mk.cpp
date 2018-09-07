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

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n;

int main()
{
	srand((unsigned long long)new char);
	n=100;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		cout<<Randint(-100,100)<<" "<<Randint(-100,100)<<" "<<Randint(0,100)<<endl;
	return 0;
}
