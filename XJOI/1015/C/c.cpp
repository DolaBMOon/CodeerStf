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

int n,ans[N],t[N],t2[N];

void Append(int *t,int x)
{
	t[++*t]=x;
}

signed main()
{
	Prework();
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)
		ans[i]=1;
	for(int cc=1,x;cc<=500;++cc)
	{
		x=rand()%n+1;
		*t=0;
		for(int i=1;i<=n;++i)if(i<x-1||i>x+1)
			if(Gcd(ans[x],ans[i])==1)
				Append(t,i);
		if(!*t)
			continue;
		*t2=0;
		bool fl=true;
		for(int i=1;i<*t;++i)
		{
			if(t[i]+1==t[i+1])
			{
				fl=false;
				//Append(t2,
				break;
			}
		}
		if(fl)
		{
			int a=p[++used];
			for(int i=1;i<=*t;++i)
				ans[t[i]]*=a;
			ans[x]*=a;
		}
		else
		{
			int a=p[++used],b=p[++used];
			ans[x]*=a*b;
			for(int i=1;i<=*t;++i)
			{
				ans[t[i]]*=a;
				if(i<*t&&t[i]+1==t[i+1])
				{
					ans[t[i+1]]*=b;
					++i;
				}
			}
		}
	}
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
	return 0;
}
