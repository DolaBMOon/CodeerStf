#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

#define int long long

const int MX=5200;

int p[MX],totp,used;
bool vis[MX];

void Prework()
{
	for(int i=2;i<MX;++i)
	{
		if(!vis[i])
			p[++totp]=i;
		for(int j=1;j<=totp&&p[j]*i<MX;++j)
		{
			vis[p[j]*i]=true;
			if(i%p[j]==0)
				break;
		}
	}
}

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

const int N=520;

int n,ans[N],t[N];

void Append(int x)
{
	t[++*t]=x;
}

signed main()
{
	Prework();
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		ans[i]=1;
	for(int k=2;k<11;++k)
	{
		for(int i=1;i<=n;++i)
			ans[i]*=p[used+i%k+1];
		used+=k;
	}
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}
