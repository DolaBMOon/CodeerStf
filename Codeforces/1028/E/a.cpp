//%:pragma GCC optimize("Ofast")
//%:pragma GCC target("sse3","sse2","sse") //%:pragma GCC target("avx","sse4","sse4.1","sse4.2","ssse3")
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

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=200000+10;

#define LL long long

int n;
LL a[N],b[N];

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		scanf("%lld",b+i);
	if(n==2)
	{
		if(b[0]||b[1])
			puts("NO");
		else
			puts("YES\n1 1");
		return 0;
	}
	int p=((b[0]>b[n-1])?0:-1);
	for(int i=1;(!(~p))&&i<n;p=((b[i]>b[i-1])?i:-1),++i);
	if(!(~p))
	{
		if(b[0]==0)
		{
			puts("YES");
			for(int i=0;i<n;++i)
				printf("1 ");
		}
		else
			puts("No");
		return 0;
	}
	puts("Yes");
	a[p]=b[p];
	for(int i=p,j,k,cc=0;cc<n;++cc,i=j)
	{
		if(i-1>=0)
			j=i-1;
		else
			j=n-1;
		if(i+1<n)
			k=i+1;
		else
			k=0;
		a[j]=b[j];
		if(a[i]<=b[j])
			a[i]+=a[k]*((b[j]-a[i])/a[k]+1);
	}
	for(int i=0;i<n;++i)
		printf("%lld ",a[i]);
	return 0;
}
