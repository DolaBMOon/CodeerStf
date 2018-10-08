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
	for(int k=2;k<4;++k)
	{
		for(int i=1;i<=n;++i)
			ans[i]*=p[used+i%k+1];
		used+=k;
	}
	for(int i=1;i<=n;++i)
	{
		*t=0;
		for(int j=1;j<i-1;++j)
			if(Gcd(ans[i],ans[j])==1)
				Append(j);
		if(!*t)
			continue;
		bool fl=true;
		for(int j=1;j<*t&&fl;++j)
			fl&=(t[j]+1!=t[j+1]);
		if(fl)
		{
			int a=p[++used];
			for(int i=1;i<=*t;++i)
				ans[t[i]]*=a;
			ans[i]*=a;
		}
		else
		{
			int a=p[++used],b=p[++used];
			ans[i]*=a*b;
			for(int j=1;j<=*t;++j)
			{
				ans[t[j]]*=a;
				if(j<*t&&t[j]+1==t[j+1])
				{
					ans[t[j+1]]*=b;
					++j;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}
