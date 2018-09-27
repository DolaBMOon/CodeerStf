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

const int N=21;
const int MS=(1<<N)+10;

int n,a[MS],b[MS],cnt[MS],S;
//int f[N][MS],g[N][MS],h[N][MS],ans[MS];

void Fmt(int *A)
{
	for(int i=0;i<n;++i)
		for(int j=0,k;j<=S;++j)if((k=(j^(1<<i)))>j)
			(A[k]+=A[j])&=3;
}

void unFmt(int *A)
{
	for(int i=0;i<n;++i)
		for(int j=0,k;j<=S;++j)if((k=(j^(1<<i)))>j)
			if((A[k]-=A[j])<0)
				A[k]+=3;
}

int main()
{
	//scanf("%d",&n);
	//S=(1<<n)-1;
	//for(int i=1;i<=S;++i)
	//	cnt[i]=cnt[i^(i&(-i))]+1;
	//for(int i=0;i<=S;++i)
	//{
	//	scanf("%d",a+i);
	//	(f[cnt[i]][i]+=a[i])&=3;
	//}
	//for(int i=0;i<=S;++i)
	//{
	//	scanf("%d",b+i);
	//	(g[cnt[i]][i]+=b[i])&=3;
	//}
	//for(int i=0;i<=n;++i)
	//{
	//	Fmt(f[i]);
	//	Fmt(g[i]);
	//}
	//for(int i=0;i<=n;++i)
	//	for(int j=0;j<=i;++j)
	//		for(int k=0;k<=S;++k)
	//			h[i][k]=(f[j][k]*g[i-j][k])&3;
	//for(int i=0;i<=n;++i)
	//{
	//	unFmt(h[i]);
	//	for(int j=0;j<=S;++j)if(cnt[j]==i)
	//		ans[j]=h[i][j];
	//}
	//for(int i=0;i<=S;++i)
	//	printf("%d ",ans[i]);
	return 0;
}
