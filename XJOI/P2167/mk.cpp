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

int n;

int main()
{
	srand((unsigned long long)new char);
	n=1000;
	cout<<n<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%1500000000<<endl;
	return 0;
}
