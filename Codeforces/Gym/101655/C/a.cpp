#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

int n,a[N],hs[N],ed,cnt[N],pw[N];
double dp[17000000];
vector<int> v;

double Mon()
{
	int wt=0;
	for(int i=0;i<n;++i)
		wt=wt*ed+a[i];
	if(v.empty()||v[0]>wt)
		return 0;
	double k=1.0/(n*n);
	for(int s:v)
	{
		double d=0,sm=0;
		for(int i=1,a;i<n;++i)
		{
			a=(s/pw[i])%ed;
			for(int j=0,b;j<i;++j)
			{
				b=(s/pw[j])%ed;
				if(a>b)
					sm+=k*dp[s-pw[i]*a+pw[i]*b-pw[j]*b+pw[j]*a];
				else
					d+=k;
			}
		}
		dp[s]=(sm*2+1)/(1-2*d-n*k);
		if(s==wt)
			return dp[s];
	}
	return -1;
}

double Car()
{
	int wt=0;
	for(int i=0;i<n;++i)
		wt=wt*ed+a[i];
	if(v.empty()||v[0]>wt)
		return 0;
	double k=1.0/(n-1);
	for(int s:v)
	{
		double d=0,sm=0;
		for(int i=1,a,b;i<n;++i)
		{
			a=(s/pw[i])%ed;
			b=(s/pw[i-1])%ed;
			if(a>b)
				sm+=k*dp[s-pw[i]*a+pw[i]*b-pw[i-1]*b+pw[i-1]*a];
			else
				d+=k;
		}
		dp[s]=(sm+1)/(1-d);
		if(s==wt)
			return dp[s];
	}
	return -1;
}

void Dfs(int k,int nw=0)
{
	if(k==n)
	{
		v.emplace_back(nw);
		return;
	}
	for(int i=0;i<ed;++i)if(cnt[i])
	{
		--cnt[i];
		Dfs(k+1,nw*ed+i);
		++cnt[i];
	}
}

void Work()
{
	scanf("%d",&n);
	ed=0;
	for(int i=0;i<n;++i)
	{
		scanf("%d",a+i);
		hs[ed++]=a[i];
	}
	sort(hs,hs+ed);
	ed=unique(hs,hs+ed)-hs;
	memset(cnt,0,sizeof cnt);
	for(int i=0;i<n;++i)
		++cnt[a[i]=lower_bound(hs,hs+ed,a[i])-hs];
	v.clear();
	Dfs(0);
	dp[v[0]]=0;
	reverse(v.begin(),v.end());
	v.pop_back();
	reverse(v.begin(),v.end());
	pw[0]=1;
	for(int i=1;i<n;++i)
		pw[i]=pw[i-1]*ed;
	printf("Monty %.6lf Carlos %.6lf\n",Mon(),Car());
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
