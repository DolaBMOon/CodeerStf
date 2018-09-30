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

const int MOD=1e9+7;
const int N=2333;

void SU(int &x,int y)
{
	((x+=y)>=MOD)?(x-=MOD):0;
}

int n,l[N],r[N],fl[N][N],f[N][N];

int main()
{
	scanf("%d%*d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",l+i);
		r[i]=l[i]+n;
	}
	for(int i=1;i<=n;++i)
		f[1][i]=fl[1][i]=1;
	for(int i=2;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			for(int k=1;k<=n;++k)if(j!=k)
			{
				if(r[k]<l[j])
				{
					SU(f[i][j],f[i-1][k]);
					SU(fl[i][j],f[i-1][k]);
				}
				else if(l[k]<r[j])
				{
					SU(f[i][j],fl[i-1][k]);
					if(l[k]<l[j])
						SU(fl[i][j],fl[i-1][k]);
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		SU(ans,f[n][i]);
	printf("%d",ans);
	return 0;
}
