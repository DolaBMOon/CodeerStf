#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int P=100000+10;

int p,ans[P];

int fa[P],fl[P];

int Find(int x)
{
	if(fa[x])
	{
		int y=fa[x];
		y=Find(y);
		fl[x]^=fl[fa[x]];
		return fa[x]=y;
	}
	else
		return x;
}

bool Hb(int x,int y,int d)
{
	int tx=Find(x);
	int ty=Find(y);
	if(tx==ty)
		return 1^d^fl[x]^fl[y];
	fa[tx]=ty;
	fl[tx]=d^fl[x]^fl[y];
	return true;
}

bool Rela(int x,int y)
{
	Find(x);
	Find(y);
	return fl[x]^fl[y];
}

void Update(int st)
{
	memset(fa+1,0,p*sizeof(*fa));
	memset(fl+1,0,p*sizeof(*fl));
	for(int i=2,d;i<=st;++i)
	{
		d=(i==st);
		for(int j=1,k=i;j<p;++j,k+=i)
		{
			if(k>p)
				k-=p;
			if(!Hb(j,k,d))
				return;
		}
	}
	for(int i=1;i<p;++i)
		printf("%d",(int)Rela(i,1));
	exit(0);
}

int main()
{
	scanf("%d",&p);
	for(int i=2;i<p&&i<233;++i)
		Update(i);
	puts("Impossible");
	return 0;
}
