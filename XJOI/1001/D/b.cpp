#pragma GCC optimize(2)
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
 
const int N=23;

int n,m,win[N];
bool G[N][N],Q[N][N];
char s[N];

bool Rd(int k)
{
	return rand()%100+1<=k;
}

double Sqr(double x)
{
	return x*x;
}

double Calc()
{
	static double aver=(n-1)*0.5/(n-1);
	double res=0;
	for(int i=1;i<=n;++i)
		res+=Sqr((double)win[i]/(n-1)-aver);
	return res/n;
}

int main()
{
	srand((unsigned long long)new char);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s+1);
		for(int j=1;j<=n;++j)
		{
			if(s[j]=='W')
				G[i][j]=true;
			else if(s[j]=='?')
				Q[i][j]=true;
		}
	}
	double ans=0;
	for(int k=0;k<=100;++k)
	{
		for(int cc=1;cc<=2;++cc)
		{
			for(int i=1;i<=n;++i)
				for(int j=i+1;j<=n;++j)if(Q[i][j])
				{
					if(rand()&1)
					{
						G[i][j]=true;
						G[j][i]=false;
					}
					else
					{
						G[i][j]=false;
						G[j][i]=true;
					}
				}
			for(int i=1;i<=n;++i)
			{
				win[i]=0;
				for(int j=1;j<=n;++j)if(G[i][j])
					++win[i];
			}
			for(int gg=1;gg<=400;++gg)
			{
				for(int i=1;i<=n;++i)
				{
					for(int j=1;j<=n;++j)
					{
						if(Q[i][j])
						{
							if(G[i][j]&&win[i]<win[j])
							{
								--win[i];
								++win[j];
								swap(G[i][j],G[j][i]);
							}
							else if(G[j][i]&&win[j]<win[i])
							{
								++win[i];
								--win[j];
								swap(G[i][j],G[j][i]);
							}
							else if(Rd(k))
							{
								if(G[i][j])
								{
									--win[i];
									++win[j];
									swap(G[i][j],G[j][i]);
								}
								else
								{
									++win[i];
									--win[j];
									swap(G[i][j],G[j][i]);
								}
							}
						}
					}
				}
				GetMax(ans,Calc());
			}
		}
	}
	printf("%.17lf",ans);
	return 0;
}
