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

const int N=1e5+10;

void GG()
{
	puts("-1");
	exit(0);
}

char s[N];
int n,fa[N],nw,cnt;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
		s[i]-=48;
	if(s[n])
		GG();
	if(!s[n-1])
		GG();
	for(int i=1;i<n;++i)
		if(s[i]^s[n-i])
			GG();
	fa[1]=nw=cnt=2;
	for(int i=n-2;i>=1;--i)
	{
		if(s[i])
		{
			fa[nw]=++cnt;
			nw=cnt;
		}
		else
			fa[++cnt]=nw;
	}
	for(int i=1;i<=n;++i)
		if(fa[i])
			printf("%d %d\n",fa[i],i);
	return 0;
}
