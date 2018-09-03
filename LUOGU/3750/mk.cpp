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

int n;

int main()
{
	srand((unsigned long long)new char);
	n=Randint(1,20);
	cout<<n<<" "<<n<<endl;
	for(int i=1;i<=n;++i)
		cout<<(i%3>0)<<" ";
	return 0;
}
