#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<multiset>

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

const int N=100000+10;

int m,n;
int x0[N],x1[N],cur[N];
multiset<int> S;

int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=m;++i)
		scanf("%d",x0+i);
	for(int j=1;j<=n;++i)
		scanf("%d",x1+i);
	sort(x0+1,x0+m+1);
	sort(x1+1,x1+n+1);
	for(int i=1;i<=n;++i)
		cur[i]=x0[i];
	for(int i=n+1;i<=m;++i)
		S.insert(x0[i]);
	for(int i=n;i>=1;--i)
	{
		set<int>::iterator it=S.upper_bound(x1[i]);
		if(it!=S.end()&&abs(*it-x1[i])<abs(cur[i]-x1[i]))
		{
			//S.insert(
		}
	}
	return 0;
}
