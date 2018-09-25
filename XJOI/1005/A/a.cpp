#pragma GCC optimize(2)
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

#define int long long

const int N=1e5+10;

int n,k,a[N],ans,cnt0;
int cnt[60][38][26][22];

void Song(int a,int b,int c,int d)
{
	a=(k-a)%k;
	b=(k-b)%k;
	c=(k-c)%k;
	d=(k-d)%k;
	if(a<60&&b<38&&c<26&&d<22)
		ans+=cnt[a][b][c][d];
	ans+=cnt0;
}

void Update(int x,int id)
{
	if(!x)
	{
		ans+=id-1;
		++cnt0;
		return;
	}
	int a=0,b=0,c=0,d=0,t;
	for(;x;x/=10)
	{
		t=x%10;
		switch(t)
		{
			case 0:
				ans+=id-1;
				++cnt0;
				return;
			case 2:
				++a;
				break;
			case 3:
				++b;
				break;
			case 4:
				a+=2;
				break;
			case 5:
				++c;
				break;
			case 6:
				++a;
				++b;
				break;
			case 7:
				++d;
				break;
			case 8:
				a+=3;
				break;
			case 9:
				b+=2;
				break;
		}
	}
	a%=k;
	b%=k;
	c%=k;
	d%=k;
	Song(a,b,c,d);
	++cnt[a][b][c][d];
}

namespace Zero
{

	bool Judge(int x)
	{
		if(!x)
			return false;
		for(;x;x/=10)
			if(x%10!=1)
				return false;
		return true;
	}

	void Solve()
	{
		int cnt=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",a+i);
			cnt+=Judge(a[i]);
		}
		printf("%lld",n*(n-1)/2-cnt*(cnt-1)/2);
	}

}

signed main()
{
	scanf("%lld%lld",&n,&k);
	if(k==0)
	{
		Zero::Solve();
		return 0;
	}
	else if(k==1)
		return putchar('0'),0;
	for(int i=1;i<=n;++i)
	{
		scanf("%lld",a+i);
		Update(a[i],i);
	}
	printf("%lld",n*(n-1)/2-ans);
	return 0;
}
