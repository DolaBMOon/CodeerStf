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

int n,p;

int main()
{
	srand((unsigned long long)new char);
	n=10;
	p=8;
	cout<<n<<" "<<p<<endl;
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			cout<<Randint(-10,10)<<" ";
		}
		cout<<endl;
	}
	return 0;
}
