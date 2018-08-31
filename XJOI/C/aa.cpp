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

const int P=100000+10;

int p,a[P];

int main()
{
	scanf("%d",&p);
	if(p==2)
		return 0*puts("Impossible");
	for(int i=1;i<p;++i)
		a[i]=1;
	for(int i=1;i<p;++i)
		a[(1ll*i*i)%p]=0;
	for(int i=1;i<p;++i)
		printf("%d",a[i]);
	return 0;
}
