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

int S,n,m;

int main()
{
	srand((unsigned long long)new char);
	S=500000;
	n=10000;
	m=S/n;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=m;++j)
			cout<<rand()%2<<" ";
		cout<<endl;
	}
	return 0;
}
