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

int n,q;

int main()
{
	srand((unsigned long long)new char);
	n=3;
	cout<<n<<" 0"<<endl;
	for(int i=1;i<=n;++i)
		puts((rand()&1)?"A":"G");
	for(int i=1;i<=n;++i)
		cout<<rand()%3<<" ";
	puts("");
	for(int i=2;i<=n;++i)
		cout<<rand()%(i-1)+1<<" "<<i<<endl;
	q=3;
	cout<<q<<endl;
	for(int i=1,x,y;i<=q;++i)
	{
		x=rand()%n+1;
		y=rand()%n+1;
		cout<<1<<" "<<x<<" "<<y<<" ";
		putchar((rand()&1)?'A':'G');
		putchar((rand()&1)?'A':'G');
		//putchar((rand()&1)?'A':'G');
		puts("");
	}
	return 0;
}
