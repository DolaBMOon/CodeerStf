#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

const int N=1e6;

struct Data
{
	int x,y,id;
}p[N];

bool Cmp(const Data &a,const Data &b)
{
	return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);
}

int n,m,C[N],ls[N],ed;

void Update(int x,int w)
{
	for(;x<=ed;x+=x&(-x))
		GetMax(C[x],w);
}

int Query(int x)
{
	int res=0;
	for(;x;x-=x&(-x))
		GetMax(res,C[x]);
	return res;
}

int Cxt(int k)
{
	int q;
	sort(p+1,p+n+1,Cmp);
	ed=0;
	for(q=1;p[q].id!=k;++q)
		ls[++ed]=p[q].y;
	ls[++ed]=p[q].y;
	sort(ls+1,ls+ed+1);
	ed=unique(ls+1,ls+ed+1)-ls-1;
	memset(C+1,0,ed*sizeof(*C));
	for(int i=1,y,w;i<=q;++i)
	{
		y=lower_bound(ls+1,ls+ed+1,p[i].y)-ls;
		w=Query(y)+1;
		if(i==q)
			return w;
		Update(y,w);
	}
	return -1;
}

int main()
{
	scanf("%d%*d%*d%*d%*d%*d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d%d",&p[i].x,&p[i].y);
		p[i].id=i;
	}
	scanf("%d",&m);
	for(int i=1,op,x,y;i<=m;++i)
	{
		scanf("%d%d",&op,&x);
		if(op==1)
			printf("%d\n",Cxt(x));
		else
		{
			scanf("%d",&y);
			++n;
			p[n]=(Data){x,y,n};
		}
	}
	return 0;
}
