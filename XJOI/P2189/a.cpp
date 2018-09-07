#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

#define Pir pair<double,double>
#define fir first
#define sec second

const int N=2333;
const double INF=1e18;
const double eps=1e-10;
const double PI=3.141592653589793;

double Sqr(double x)
{
	return x*x;
}

struct Vector
{

	double x,y;

	void Read()
	{
		scanf("%lf%lf",&x,&y);
	}

	double Abs2()
	{
		return x*x+y*y;
	}

	double Abs()
	{
		return sqrt(Abs2());
	}

};

Vector operator*(const Vector &a,const Vector &b)
{
	return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

Vector operator*=(Vector &a,const Vector &b)
{
	return a=a*b;
}

Vector operator+(const Vector &a,const Vector &b)
{
	return {a.x+b.x,a.y+b.y};
}

Vector operator+=(Vector &a,const Vector &b)
{
	a.x+=b.x;
	a.y+=b.y;
	return a;
}

Vector operator-(const Vector &a,const Vector &b)
{
	return {a.x-b.x,a.y-b.y};
}

Vector operator-=(Vector &a,const Vector &b)
{
	a.x-=b.x;
	a.y-=b.y;
	return a;
}

ostream& operator<<(ostream &os,const Vector &b)
{
	os<<"("<<b.x<<", "<<b.y<<")";
	return os;
}

struct Circle
{

	Vector o;
	double r;

	void Read()
	{
		o.Read();
		scanf("%lf",&r);
	}

	double L() const
	{
		return o.x-r;
	}

	double R() const
	{
		return o.x+r;
	}

	Pir UpDown(double x)
	{
		double d=sqrt(Sqr(r)-Sqr(abs(x-o.x)));
		return {o.y-d,o.y+d};
	}

}c[N];

namespace Bing
{

	Circle *q;
	double l[N],r[N];
	int n;

	double F(double x)
	{
		static Pir p[N];
		int tot=0;
		for(int i=0;i<n;++i)
			if(l[i]<x&&x<r[i])
				p[tot++]=q[i].UpDown(x);
		sort(p,p+tot);
		double mn=p[0].fir,mx=-INF,res=0;
		for(int i=0;i<tot;++i)
		{
			GetMax(mx,p[i].sec);
			if(p[i+1].fir>mx||i==tot-1)
			{
				res+=mx-mn;
				mx=mn=p[i+1].fir;
			}
		}
		return res;
	}

	double Simpson(double l,double r,double fl,double fm,double fr)
	{
		return (r-l)*(fl+fr+4*fm)/6;
	}

	double Calc(double l,double m,double r,double fl,double fm,double fr,double w)
	{
		double lm=(l+m)*0.5,rm=(r+m)*0.5;
		double flm=F(lm),frm=F(rm),wl,wr;
		if(abs(w-((wl=Simpson(l,m,fl,flm,fm))+(wr=Simpson(m,r,fm,frm,fr))))<eps)
			return wl+wr;
		return Calc(l,lm,m,fl,flm,fm,wl)+Calc(m,rm,r,fm,frm,fr,wr);
	}

	double Work(Circle *_q,int _n,double L,double R)
	{
		q=_q;
		n=_n;
		for(int i=0;i<n;++i)
		{
			l[i]=q[i].L();
			r[i]=q[i].R();
		}
		double m=(L+R)*0.5;
		double a=F(L),b=F(m),c=F(R);
		return Calc(L,m,R,a,b,c,Simpson(L,R,a,b,c));
	}

}

int n;

void RandomWork()
{
	//Vector v={cos(517),sin(517)};
	//for(int i=1;i<=n;++i)
	//	c[i].o*=v;
}

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		c[i].Read();

	RandomWork();

	sort(c,c+n,[](const Circle &x,const Circle &y)
			{
				return x.L()<y.L();
			});

	double mx=-INF,ans=0;
	for(int i=0,j=0;i<n;++i)
	{
		GetMax(mx,c[i].R());
		if(mx<c[i+1].L()||i==n-1)
		{
			ans+=Bing::Work(c+j,i-j+1,c[j].L(),mx);
			j=i+1;
			mx=-INF;
		}
	}
	printf("%.3lf\n",ans);
}
