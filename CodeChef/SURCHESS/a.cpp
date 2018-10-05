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

const int N=233;

int n,m,q,res[N],sm[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		static char s[N];
		scanf("%s",s+1);
		for(int j=1;j<=m;++j)
		{
			sm[i][j]=(s[j]=='1')^(i&1)^(j&1);
			sm[i][j]+=sm[i-1][j]+sm[i][j-1]-sm[i-1][j-1];
			//cout<<i<<","<<j<<":"<<sm[i][j]<<endl;
		}
	}
	memset(res,0x3f,sizeof res);
	for(int k=1;k<=n;++k)
	{
		for(int i=1;i+k-1<=n;++i)
		{
			for(int j=1,t;j+k-1<=m;++j)
			{
				t=sm[i+k-1][j+k-1]-sm[i-1][j+k-1]-sm[i+k-1][j-1]+sm[i-1][j-1];
				GetMin(res[k],min(t,k*k-t));
			}
		}
	}
	scanf("%d",&q);
	for(int i=1,c;i<=q;++i)
	{
		scanf("%d",&c);
		printf("%d\n",upper_bound(res+1,res+n+1,c)-res-1);
	}
	return 0;
}
