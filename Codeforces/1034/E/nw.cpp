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

#define D unsigned long long

const int N=21;
const int M=(1<<N)+10;

int n,S,cnt[M];
D A[M],B[M],C[M];

int main()
{
	scanf("%d",&n);
	S=(1<<n)-1;
	for(int i=1;i<=S;++i)
		cnt[i]=cnt[i>>1]+(i&1);
	static char s[M];
	scanf("%s",s);
	for(int i=0;i<=S;++i)
		A[i]=(D)(s[i]-'0')<<(cnt[i]<<1);
	scanf("%s",s);
	for(int i=0;i<=S;++i)
		B[i]=(D)(s[i]-'0')<<(cnt[i]<<1);
	for(int i=0;i<n;++i)
		for(int j=0;j<=S;++j)if((j>>i)&1)
		{
			A[j]+=A[j^(1<<i)];
			B[j]+=B[j^(1<<i)];
		}
	for(int i=0;i<=S;++i)
		C[i]=A[i]*B[i];
	for(int i=0;i<n;++i)
		for(int j=0;j<=S;++j)if((j>>i)&1)
			C[j]-=C[j^(1<<i)];
	for(int i=0;i<=S;++i)
		putchar('0'+((C[i]>>(cnt[i]<<1))&3));
	return 0;
}
