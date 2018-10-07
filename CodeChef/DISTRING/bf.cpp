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

int n,m,A[N][N];

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&A[i][j]);
	int ans=0;
	for(int x0=1;x0<=n;++x0)
	{
		for(int x1=x0;x1<=n;++x1)
		{
			for(int y0=1;y0<=m;++y0)
			{
				for(int y1=y0;y1<=m;++y1)
				{
					for(int i=x0;i<=x1;++i)
					{
						bool fl=true;
						for(int j=i+1;j<=x1&&fl;++j)
						{
							bool same=true;
							for(int k=y0;k<=y1&&same;++k)
								same&=(A[i][k]==A[j][k]);
							fl&=!same;
						}
						ans+=fl;
					}
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
