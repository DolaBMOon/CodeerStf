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

int n,m,q;

int main()
{
	srand((unsigned long long)new char);
	n=10000;
	m=n+n;
	q=10000;
	cout<<n<<" "<<m<<" "<<q<<endl;
	for(int i=1,l,r;i<=m;++i)
	{
Fuck:
		l=rand()%n+1;
		r=rand()%n+1;
		if(l>r)
			swap(l,r);
		else if(l==r)
			goto Fuck;
		cout<<l<<" "<<r<<endl;
	}
	for(int i=1;i<=q;++i)
	{
		switch(rand()%3)
		{
			case 0:
				cout<<1<<" "<<rand()%n+1<<endl;
				break;
			case 1:
				cout<<2<<" "<<rand()%n+1<<endl;
				break;
			case 2:
				cout<<3<<" "<<rand()%m+1<<endl;
				break;
		}
	}
	return 0;
}
