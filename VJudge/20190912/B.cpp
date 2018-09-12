#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

const int N=1000;

int n,p,m;
int A[N][N],B[N][N],C[N][N],D[N][N];

void Work()
{
	for(int i=0;i<n;++i)
		for(int j=0;j<p;++j)
			scanf("%d",&A[i][j]);
	for(int i=0;i<p;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&B[i][j]);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			scanf("%d",&C[i][j]);
	memset(D,0,sizeof D);
	for(int i=0;i<n;++i)
		for(int k=0;k<p;++k)
			for(int j=0;j<m;++j)
				D[i][j]+=A[i][k]*B[k][j];
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)if(C[i][j]!=D[i][j])
		{
			puts("No");
			printf("%d %d\n%d\n",i+1,j+1,D[i][j]);
			return;
		}
	puts("Yes");
}

int main()
{
	while(~scanf("%d%d%d",&n,&p,&m))
		Work();
	return 0;
}
