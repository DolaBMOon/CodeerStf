#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<"<<<<<<<<<<"endl
#define Divher() cout<<">>>>>>>>>>"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return (a<=b)?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return (a>=b)?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

int Rdw()
{
	return rand();
}

int n,q;

int main()
{
	srand((unsigned long long)new char);
	n=100000;
	q=100000;
	cout<<n<<" "<<q<<endl;
	for(int i=1;i<=n;++i)
		cout<<Rdw()<<" ";
	puts("");
	for(int i=2;i<=n;++i)
		cout<<rand()%(i-1)+1<<" "<<i<<endl;
	for(int i=1,k;i<=q;++i)
	{
		if(rand()&3)
		{
			cout<<"Q ";
			k=rand()%30+1;
			for(int j=1;j<=k;++j)
				cout<<rand()%n+1<<" ";
			cout<<"0"<<endl;
		}
		else
		{
			cout<<"C "<<rand()%n+1<<" "<<Rdw()<<endl;
		}
	}
	return 0;
}
