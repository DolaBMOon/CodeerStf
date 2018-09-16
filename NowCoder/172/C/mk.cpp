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

int n,m,q;

int main()
{
	srand((unsigned long long)new char);
	n=5;
	m=rand()%n+1;
	q=rand()%m+1;
	cout<<n<<" "<<m<<endl;
	for(int i=2;i<=n;++i)
		cout<<rand()%(i-1)+1<<" "<<i<<endl;
	for(int i=1;i<=m;++i)
		cout<<rand()%n+1<<" "<<rand()%n+1<<endl;
	cout<<q<<endl;
	for(int i=1;i<=q;++i)
		cout<<rand()%n+1<<" "<<rand()%m+1<<endl;
	return 0;
}
