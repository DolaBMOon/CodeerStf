//%:pragma GCC optimize("Ofast")
//%:pragma GCC target("sse3","sse2","sse")
//%:pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
//%:pragma GCC target("f16c")
//%:pragma GCC optimize("inline","fast-math","unroll-loops","no-stack-protector")
//%:pragma GCC diagnostic error "-fwhole-program"
//%:pragma GCC diagnostic error "-fcse-skip-blocks"
//%:pragma GCC diagnostic error "-funsafe-loop-optimizations"
//%:pragma GCC diagnostic error "-std=c++14"

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

const int N=233;

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n,m,a[N];

int main()
{
	srand((unsigned long long)new char);
	n=5;
	m=3;
	printf("%d %d\n",n,m);
	for(int i=1;i<=n;++i)
		a[i]=i;
	random_shuffle(a+1,a+n+1);
	for(int i=1;i<=n;++i)
		printf("%d ",a[i]);
	putchar('\n');
	for(int i=1,l,r;i<=m;++i)
	{
		l=Randint(1,n);
		r=Randint(1,n);
		if(l>r)
			swap(l,r);
		printf("%d %d %d\n",rand()&1,l,r);
	}
	printf("%d\n",Randint(1,n));
	return 0;
}
