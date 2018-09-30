#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return ((a<=b)?false:(a=b,true));
}

template<typename T> bool GetMax(T &a,T b)
{
	return ((a>=b)?false:(a=b,true));
}

/*
	 -<Unlimited Blade Works>-
 */

#define LL long long

const int MOD=1e9+7;

int Mul(int x,int y)
{
	return (LL)x*y%MOD;
}

void SMul(int &x,int y)
{
	x=(LL)x*y%MOD;
}

int Qpow(int x,int y=MOD-2)
{
	int res=1;
	for(;y;y>>=1,SMul(x,x))if(y&1)
		SMul(res,x);
	return res;
}

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

const int N=60;

int n,tot=1;
char s[N][N];
int mo[N],ans[N];

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%s",mo+i,s[i]);
		tot=tot/Gcd(tot,mo[i])*mo[i];
	}
	for(int i=0;i<tot;++i)
	{
		int cnt=0;
		for(int j=1;j<=n;++j)
			if(s[j][i%mo[j]]=='O')
				++cnt;
		++ans[cnt];
	}
	int k=1;
	for(int i=2;i<=50;++i)
		SMul(k,i);
	SMul(k,Qpow(tot));
	for(int i=1;i<=n;++i)
		printf("%d\n",Mul(k,ans[i]));
	return 0;
}
