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
	scanf("%d%d",&n,&m);
	for(int i=1,a,p;i<=n;++i)
	{
		scanf("%d",&a,&p);
		assert(p<=1000000);
	}
	return 0;
}
