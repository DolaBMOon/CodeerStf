#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n,k;

int main()
{
	srand((unsigned long long)new char);
	n=5;
	k=Randint(0,n-1);
	cout<<n<<" "<<k<<endl;
	for(int i=2;i<=n;++i)
		cout<<Randint(1,i-1)<<" "<<i<<" "<<Randint(-5,5)<<endl;
	return 0;
}
