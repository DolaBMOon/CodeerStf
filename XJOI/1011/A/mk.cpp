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

int n;

int main()
{
	srand((unsigned long long)new char);
	n=5000;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		//cout<<rand()-RAND_MAX/2<<" ";
		cout<<rand()-RAND_MAX/2<<" ";
	cout<<endl;
	for(int i=2;i<=n/2;++i)
		//cout<<rand()%(i-1)+1<<" "<<i<<endl;
		cout<<i-1<<" "<<i<<endl;
	for(int i=n/2+1;i<=n;++i)
		cout<<rand()%(i-1)+1<<" "<<i<<endl;
	return 0;
}
