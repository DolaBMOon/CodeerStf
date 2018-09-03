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

/*
-<Unlimited Blade Works>-
*/

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n,m;

int main()
{
	srand((unsigned long long)new char);
	n=1e5;
	for(int i=1;i<=n;++i)
		putchar(Randint('a','z'));
	putchar('\n');
	m=1e5;
	cout<<m<<endl;
	for(int i=1,l,r;i<=m;++i)
	{
		l=Randint(1,n);
		r=Randint(1,n);
		if(l>r)
			swap(l,r);
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}
