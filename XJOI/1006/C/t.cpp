#pragma GCC optimize("Ofast")
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

const int N=100010;

bool fl;
int n,m,l,q,cc;
vector<int> A[N],B[N];

int main()
{
	scanf("%d%d%d%d",&n,&m,&l,&q);
	if(n<m)
	{
		swap(n,m);
		fl=true;
	}
	for(int i=0;i<=n;++i)
	{
		A[i].resize(m+1);
		B[i].resize(m+1);
	}
	for(int i=1,ty,a,b,c,d,w;i<=q;++i)
	{
		scanf("%d%d%d%d%d",&ty,&a,&b,&c,&d);
		if(fl)
		{
			swap(a,b);
			swap(c,d);
		}
		if(ty&1)
		{
			scanf("%d",&w);
			for(int x=a;x<=c;++x)
				for(int y=b;y<=d;++y)
					A[x][y]+=w;
		}
		else
		{
			if(A[a][b]>=l||A[c][d]>=l)
			{
				puts("no");
				continue;
			}
			B[a][b]=++cc;
			for(int x=a;x<=c;++x)
			{
				bool ok=(x==a);
				for(int y=b;y<=d;++y)
					if(A[x][y]<l&&(B[x-1][y]==cc||B[x][y-1]==cc))
					{
						B[x][y]=cc;
						ok=true;
					}
				if(!ok)
					break;
			}
			puts(B[c][d]==cc?"yes":"no");
		}
	}
	return 0;
}
