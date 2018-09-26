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

const int N=320;
const int M=100010;

struct Data
{
	int a,b,c,d,w;
}da[M];

bool fl;
int n,m,l,q;
vector<int> s[N];
int tot;

vector<int> T[N];
int fa[M];

int Idx(int x,int y)
{
	return x*m+y;
}

void Join(int x,int y)
{
	int k=Idx(x,y);
}

void Build(vector<int> &v,vector<int> &T,int o=1,int l=1,int r=m)
{
	if(l==r)
	{
		T[o]=v[l];
		return;
	}
}

int main()
{
	Whats(sizeof(Seg)/1024.0/1024.0);
	scanf("%d%d%d%d",&n,&m,&l,&q);
	for(int i=0;i<=n;++i)
	{
		s[i].resize(m+1);
		T[i].resize(4*m+1);
	}
	if(n>m)
	{
		swap(n,m);
		fl=true;
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
			da[++tot]=(Data){a,b,c,d};
		else
		{
			scanf("%d",&w);
			da[++tot]=(Data){a,b,c,d,w};
			s[a][b]+=w;
			s[c+1][b]-=w;
			s[a][d+1]-=w;
			s[c+1][d+1]+=w;
		}
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
	for(int i=1;i<=n;++i)
		Build(s[i],T[i]);
	return 0;
}
