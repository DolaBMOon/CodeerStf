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

int n,m,q;

int main()
{
	n=300000;
	m=300000;
	cout<<n<<" "<<m<<endl;
	for(int i=2;i<=n;++i)
		cout<<i<<" "<<rand()%(i-1)+1<<endl;
	cout<<rand()%n+1<<" "<<rand()%n+1<<endl;
	q=n;
	cout<<q<<endl;
	for(int i=1,x,y;i<=q;++i)
	{
		x=rand()%n+1;
		y=rand()%n+1;
		if(x>y)
			swap(x,y);
		cout<<x<<" "<<y<<endl;
	}
	return 0;
}
