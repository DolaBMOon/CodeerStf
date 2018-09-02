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

#define LL long long

const int N=1e5+10;
const int MOD=100003;

int n,fl[N];

int main()
{
	scanf("%d%*d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",fl+i);
	int ans=0;
	for(int i=n;i;--i)
	{
		for(int j=i+i;j<=n;j+=i)
			fl[i]^=fl[j];
		ans+=fl[i];
	}
	for(int i=1;i<=n;++i)
		ans=(LL)ans*i%MOD;
	printf("%d",ans);
	return 0;
}
