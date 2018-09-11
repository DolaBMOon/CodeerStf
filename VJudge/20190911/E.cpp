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

#define LL long long

const int MOD=998244353;

int n;
int M[3][3],R[3][3];

void Mul(int (*A)[3],int (*B)[3])
{
	static int C[3][3];
	memset(C,0,sizeof C);
	for(int i=0;i<3;++i)
		for(int k=0;k<3;++k)
			for(int j=0;j<3;++j)
				if((C[i][j]+=(LL)A[i][k]*B[k][j]%MOD)>=MOD)
					C[i][j]-=MOD;
	memcpy(A,C,sizeof(C));
}

void Work()
{
	--n;
	//if(n<3)
	//{
	//	printf("%d\n",V[n]);
	//	return;
	//}
	memset(M,0,sizeof M);
	M[1][0]=1;
	M[2][1]=1;
	M[0][2]=1;
	M[1][2]=MOD-4;
	M[2][2]=4;
	memset(R,0,sizeof R);
	R[0][0]=R[1][1]=R[2][2]=1;
	for(;n;n>>=1,Mul(M,M))if(n&1)
		Mul(R,M);
	//for(int i=0;i<3;++i)
	//{
	//	for(int j=0;j<3;++j)
	//		cout<<M[i][j]<<" ";
	//	cout<<endl;
	//}
	printf("%lld\n",(4ll*R[0][0]%MOD+12ll*R[1][0]%MOD+33ll*R[2][0]%MOD)%MOD);
}

int main()
{
	while(~scanf("%d",&n))
		Work();
	return 0;
}
