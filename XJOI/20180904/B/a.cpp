#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<bitset>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=100+10;
const int A=3000+10;

int n,a[N];
bitset<N*A> B;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	for(int i=1;i<=n;++i)
	{
		B=1;
		for(int j=1;j<=n;++j)if(i!=j)
			B|=B<<a[j];
		printf("%d\n",(int)B.count()-1);
	}
}
