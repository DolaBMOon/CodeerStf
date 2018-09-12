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

const int N=100;

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n;
char s[N];

int main()
{
	srand((unsigned long long)new char);
	n=5;
	for(int i=1;i<=n;++i)
		s[i]=Randint('a','z');
	cout<<(s+1)<<endl;
	int l=Randint(1,n),r=Randint(1,n);
	if(l>r)
		swap(l,r);
	reverse(s+l,s+r+1);
	cout<<(s+1)<<endl;
	return 0;
}
