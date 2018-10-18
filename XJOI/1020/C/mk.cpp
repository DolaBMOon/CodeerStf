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

int main()
{
	srand((unsigned long long)new char);
	cout<<1<<endl;
	int n=rand()%10+1,m=rand()%3+1;
	for(int i=1;i<=n;++i)
		putchar('a'+rand()%3);
	puts("");
	for(int i=1;i<=m;++i)
		putchar('a'+rand()%3);
	return 0;
}
