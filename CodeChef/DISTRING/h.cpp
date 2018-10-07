#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

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

#define H unsigned long long

const int N=500000+10;
const int MIN=1000;

const H D=2777777777777ll;

const int _B=1e6+10;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int sum=ch-48;
	while(isdigit(ch=Nc()))
		sum=sum*10+ch-48;
	return sum;
}

vector<H> G[N];

int n,m;

H ans;

namespace Solver1
{

	H col[MIN];
	int lcp[MIN][MIN];

	void Work()
	{
		memset(lcp,-1,sizeof lcp);
		for(int l=m-1;l>=0;--l)
		{
			for(int i=0;i<n;++i)
				col[i]=G[i][l];
			for(int i=0;i<n;++i)
			{
				ans+=(m-l)*(n-i);
				for(int j=i-1,mx=l-1;j>=0;--j)
				{
					if(col[i]!=col[j])
						lcp[i][j]=-1;
					else
					{
						GetMax(lcp[i][j],l);
						GetMax(mx,lcp[i][j]);
					}
					ans+=(m-mx-1)*(n-i);
				}
			}
		}
		printf("%llu\n",ans);
	}

}

namespace Solver2
{
	cc_hash_table<H,int> mp;
	H pw[MIN];
	vector<H> G0[MIN];

	void Work()
	{
		pw[0]=1;
		for(int i=1;i<=m;++i)
			pw[i]=pw[i-1]*D;
		for(int i=0;i<m;++i)
			G0[i].resize(n);
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j)
				G0[j][i]=G[i][j];
		for(int i=0;i<n;++i)
			for(int j=1;j<m;++j)
				G0[j][i]=G0[j-1][i]*D+G0[j][i];
		for(int l=0;l<m;++l)
			for(int r=l;r<m;++r)
			{
				mp.clear();
				for(int i=0;i<n;++i)
				{
					H x=G0[r][i];
					if(l)
						x-=G0[l-1][i]*pw[r-l+1];
					int &j=mp[x];
					ans+=(i-j+1)*(n-i);
					j=i+1;
				}
			}
		printf("%llu\n",ans);
	}

}

int main()
{
	n=Read();
	m=Read();
	for(int i=0;i<n;++i)
		G[i].resize(m);
	for(int i=0;i<n;++i)
		for(int j=0;j<m;++j)
			G[i][j]=Read();
	if((long long)n*n*m<=200000000)
		Solver1::Work();
	else
		Solver2::Work();
	return 0;
}
