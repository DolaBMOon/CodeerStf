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

const int N=8;
const int MS=(1<<N)+10;

int n,a[N],hs[N],ed,bc[MS];

double Mon(int x)
{
	int tot=0,cnt=0,wt=0;
	for(int i=0;i<n;++i)if(a[i]<=x)
	{
		++tot;
		wt<<=1;
		if(a[i]==x)
		{
			wt^=1;
			++cnt;
		}
	}
	static double dp[MS];
	for(int i=0;i<=wt;++i)
		dp[i]=0;
	double k=1.0/(cnt*tot*2);
	for(int t=(1<<cnt);t<=wt;++t)if(bc[t]==cnt)
	{
		double d=1,sm=1;
		for(int x=0;x<tot;++x)
			for(int y=0;y<tot;++y)if(((t>>x)&1)||((t>>y)&1))
			{
				if(((t>>min(x,y))&1)<((t>>max(x,y))&1))
					sm+=k*dp[t^(1<<min(x,y))^(1<<max(x,y))];
				else
					d-=k;
			}
		dp[t]=sm/d;
	}
	return dp[wt];
}

double Car(int x)
{
	return 0;
}

void Work()
{
	for(int i=1;i<MS;++i)
		bc[i]=bc[i>>1]+(i&1);
	scanf("%d",&n);
	ed=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
		hs[++ed]=a[i];
	}
	sort(hs+1,hs+ed+1);
	ed=unique(hs+1,hs+ed+1)-hs-1;
	for(int i=1;i<=n;++i)
		a[i]=lower_bound(hs+1,hs+ed+1,a[i])-hs;
	double ans=0,ans2=0;
	for(int i=1;i<=ed;++i)
	{
		ans+=Mon(i);
		ans2+=Car(i);
	}
	printf("Monty %.6lf Carlos %.6lf\n",ans,ans2);
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
