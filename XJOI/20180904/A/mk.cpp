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

int n;

int main()
{
	n=1e6;
	cout<<n<<endl;
	for(int i=1,l,r;i<=n;++i)
	{
		l=Randint(1,1e5);
		r=Randint(1,1e5);
		if(l>r)
			swap(l,r);
		cout<<l<<" "<<r<<endl;
	}
	return 0;
}
