#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
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

const int MOD=998244353;

int n;

int main()
{
	n=200000;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%MOD<<" "<<rand()%n<<endl;
	for(int i=2;i<=n;++i)
		cout<<rand()%(i-1)+1<<" "<<i<<" "<<rand()%MOD<<endl;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		printf("%d\n",i);
	return 0;
}
