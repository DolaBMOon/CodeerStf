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

#define Pir pair<int,int>
#define fir first
#define sec second
 
const int N=23;

int n,m,ori[N],win[N];
char s[N];
Pir p[N];

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
				++ori[i];
			else if(s[j]=='?'&&i<j)
				p[++m]=Pir(i,j);
		}
	}
	double ans=0;
	for(int k=0;k<=100;++k)
	{
		for(int cc=1;cc<=10;++cc)
		{
			random_shuffle(p+1,p+m+1);
			for(int i=1;i<=n;++i)
				win[i]=ori[i];
			for(int i=1;i<=m;++i)
			{
				if(Rd(k))
					swap(p[i].fir,p[i].sec);
				++win[p[i].fir];
			}
			for(int gg=1;gg<=100;++gg)
			{
				for(int i=1;i<=m;++i)
					if((win[p[i].fir]<win[p[i].sec])^Rd(k))
					{
						--win[p[i].fir];
						++win[p[i].sec];
						swap(p[i].fir,p[i].sec);
					}
				GetMax(ans,Calc());
			}
		}
	}
	printf("%.17lf",ans);
	return 0;
}
