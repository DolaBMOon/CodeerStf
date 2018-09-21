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

const int S=2047;
const int N=2333;
const int MOD=1e9+7;

int n,m;
int f[N][2][2],g[N][2][2];

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int Solve(int k)
{
	int T=0;
	for(int i=1<<10;i>k;i>>=1)
		T^=i;
	memset(f,0,sizeof f);
	memset(g,0,sizeof g);
	f[0][0][0]=g[0][0][0]=1;
	for(int i=1;i<=n||i<=m;++i)
	{
		for(int j=0;j<S;++j)
		{
			for(int a=0;a<2;++a)
				for(int b=0,c;b<2;++b)if((c=f[j][a][b]))
				{
					if(i<=n)
						SU(g[j^(i&T)][a^((bool)(i&k))][b],c);
					if(i<=m)
						SU(g[j^(i&T)][a][b^((bool)(i&k))],c);
				}
		}
		memcpy(f,g,sizeof f);
	}
	return f[0][0][1];
}

int main()
{
	scanf("%d%d",&n,&m);
	int ans=0;
	for(int i=0;i<=10;++i)
		SU(ans,Solve(1<<i));
	printf("%d",ans);
	return 0;
}
