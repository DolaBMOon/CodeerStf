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

int n,len;

int main()
{
	srand((unsigned long long)new char);
	n=5;
	len=rand()%n+1;
	cout<<n<<" "<<len<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%10+1<<" ";
	return 0;
}
