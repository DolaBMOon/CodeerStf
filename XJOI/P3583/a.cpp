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

#define int long long

const int K=20;
const int MOD=1e9+7;
const int MOD2=MOD*MOD;

int Mul(int x,int y)
{
	return x*y%MOD;
}

int U(int x,int y)
{
	return ((x+=y)>=MOD)?(x-MOD):x;
}

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int U2(int x,int y)
{
	return ((x+=y)>=MOD2)?(x-MOD2):x;
}

void SU2(int &x,int y)
{
	((x+=y)>=MOD2)?(x-=MOD2):0;
}

int n,k;

struct Vector
{
	int a[K];
};

int Dot(const Vector &a,const Vector &b)
{
	int res=0;
	for(int i=0;i<k;++i)
		SU2(res,a[i]*b[i]);
}

signed main()
{
	scanf("%lld%lld",&n,&k);
	for(int i=1;i<=n;++i)
	{
	}
	return 0;
}
