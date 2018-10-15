#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

#define int long long

const int _B=1e6;

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

const int N=2333;

struct Vector
{
	int x,y;
}p[N];

struct Triple
{
	int u,v,w;
}t[N*N];

int Sqr(int x)
{
	return x*x;
}

int Distr(const Vector &a,const Vector &b)
{
	return Sqr(a.x-b.x)+Sqr(a.y-b.y);
}

bool Cmp(const Triple &a,const Triple &b)
{
	return a.w<b.w;
}

int n,m,tx,ty,fa[N];
bool col[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

bool Merge(int x,int y)
{
	if(col[x=Find(x)]&&col[y=Find(y)])
		return true;
	fa[x]=y;
	col[y]|=col[x];
}

signed main()
{
	tx=Read();
	ty=Read();
	n=Read();
	for(int i=1;i<=n;++i)
	{
		p[i].x=Read();
		p[i].y=Read();
	}
	for(int i=1;i<n;++i)
		for(int j=i+1;j<=n;++j)
			t[++m]=(Triple){i,j,Distr(p[i],p[j])};
	for(int i=1;i<=n;++i)
	{
		t[++m]=(Triple){i,n+1,Sqr(p[i].x)};
		t[++m]=(Triple){i,n+2,Sqr(p[i].y)};
		t[++m]=(Triple){i,n+3,Sqr(tx-p[i].x)};
		t[++m]=(Triple){i,n+4,Sqr(ty-p[i].x)};
	}
	sort(t+1,t+m+1,Cmp);
	col[n+1]=col[n+2]=col[n+3]=col[n+4]=true;
	for(int i=1;i<=m;++i)
	{
		if(Merge(t[i].u,t[i].v))
		{
			printf("%.2lf",sqrt(t[i].w));
			return 0;
		}
	}
	return 0;
}
