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

int n,K;

int main()
{
	n=50;
	K=10000;
	cout<<n<<" "<<K<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%K+1<<" ";
	for(int i=1;i<=n;++i)
		cout<<rand()%K+1<<" ";
	for(int i=1;i<=n;++i)
		cout<<rand()%K+1<<" ";
	return 0;
}
