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

int n,m;

int main()
{
	srand((unsigned long long)new char);
	n=5;
	m=rand()%n;
	cout<<n<<" "<<m<<endl;
	for(int i=1;i<=n;++i)
		cout<<rand()%10<<" ";
	return 0;
}
