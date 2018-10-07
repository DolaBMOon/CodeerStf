#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<map>
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

#define H unsigned long long

const int N=500000+10;
const int MIN=5000;

const int _B=3e6+10;

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

	void Work()
	{
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
	if((H)n*n*m<=1000000000)
		Solver1::Work();
	else
		Solver2::Work();
	return 0;
}
