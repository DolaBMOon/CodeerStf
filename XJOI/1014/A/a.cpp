#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
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

int n;

int main()
{
	scanf("%d",&n);
	if(n<=26)
	{
		for(int i=0;i<n;++i)
		{
			putchar('a'+i);
			putchar('\n');
		}
		return 0;
	}
	int t=0;
	static int cnt[22];
	for(int i=0;i<n-2;++i)
		t+=cnt[i%22]++;
	int t2=t>>1;
	t-=t2;
	for(int i=0;i<=t;++i)
		putchar('a'+(i&1));
	putchar('\n');
	for(int i=0;i<=t2;++i)
		putchar('c'+(i&1));
	putchar('\n');
	for(int i=0;i<n-2;++i)
	{
		putchar('e'+i%22);
		putchar('\n');
	}
	return 0;
}
