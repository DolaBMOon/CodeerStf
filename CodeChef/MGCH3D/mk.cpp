#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n,q;

int main()
{
	srand((unsigned long long)new char);
	n=77777;
	q=77;
	cout<<n<<" "<<q<<endl;
	for(int i=1;i<=n;++i)
		cout<<Randint(1,77)<<" "<<Randint(1,77)<<" "<<Randint(1,77)<<endl;
	for(int i=1;i<=q;++i)
	{
		cout<<Randint(1,77)<<" "<<Randint(1,77)<<" "<<Randint(1,77)<<" "<<Randint(1,7777)<<endl;
	}
	return 0;
}
