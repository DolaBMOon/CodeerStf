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

const int N=1000000+10;

int n,q;
vector<int> v[N];

int main()
{
	scanf("%d",&n);
	for(int i=1,a;i<=n;++i)
	{
		scanf("%d",&a);
		v[a].emplace_back(i);
	}
	scanf("%d",&q);
	for(int i=1,m;i<=q;++i)
	{
		scanf("%d",&m);
		int nw=0;
		bool fl=true;
		for(int j=1,a;j<=m;++j)
		{
			scanf("%d",&a);
			if(fl)
			{
				vector<int>::iterator it=upper_bound(v[a].begin(),v[a].end(),nw);
				if(it==v[a].end())
					fl=false;
				else
					nw=*it;
			}
		}
		puts(fl?"TAK":"NIE");
	}
	return 0;
}
