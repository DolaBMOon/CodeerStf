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

int Rdw()
{
	return rand();
}

int main()
{
	n=100000;
	m=rand()%n;
	cout<<n<<" "<<m<<endl;
	for(int i=2;i<=n;++i)
		cout<<rand()%(i-1)+1<<" "<<i<<endl;
		//cout<<i-1<<" "<<i<<endl;
	for(int i=1;i<=m;++i)
		cout<<rand()%n+1<<" "<<rand()%n+1<<" "<<Rdw()<<endl;
	return 0;
}
