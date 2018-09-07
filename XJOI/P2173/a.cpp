#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<cmath>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
	 -<Unlimited Blade Works>-
 */

const double PI=3.141592653589793;

struct Vector
{

	double x,y;

	double Abs2()
	{
		return x*x+y*y;
	}

	double Abs()
	{
		return sqrt(Abs2());
	}

	void Read()
	{
		scanf("%lf%lf",&x,&y);
	}

};

struct Circle
{
	Vector o;
	double r;
};

struct Line
{
	Vector u,v;
};

ostream& operator<<(ostream &os,Vector v)
{
	 os<<"("<<v.x<<", "<<v.y<<")";
	 return os;
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

Vector operator*(const Vector &a,const Vector &b)
{
	return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

Vector operator*=(Vector &a,const Vector &b)
{
	a=a*b;
	return a;
}

Vector operator/(const Vector &a,const double &b)
{
	return {a.x/b,a.y/b};
}

Vector operator/=(Vector &a,const double& b)
{
	a.x/=b;
	a.y/=b;
	return a;
}

Vector operator*(const Vector &a,const double &b)
{
	return {a.x*b,a.y*b};
}

double Det(const Vector &a,const Vector &b)
{
	return a.x*b.y-a.y*b.x;
}

double Dist2(const Vector &a,const Vector &b)
{
	return (a-b).Abs2();
}

double Dist(const Vector &a,const Vector &b)
{
	return (a-b).Abs();
}

Line Trans(Line l)
{
	l.u+=l.v/2;
	swap(l.v.x,l.v.y);
	return l;
}

Vector CrossPt(const Line &a,const Line &b)
{
	Vector t=b.u+b.v-a.u;
	double k=Det(b.u-a.u,t)/Det(t,a.v);
	return b.u+b.v/(k+1)*k;
}

bool inCircle(const Circle &c,const Vector &p)
{
	return (p-c.o).Abs()<=c.r;
}

Circle MakeCircle(const Vector &a,const Vector &b)
{
	Circle c;
	c.o=(a+b)*0.5;
	c.r=Dist(c.o,a);
	return c;
}

Circle MakeCircle(const Vector &a,const Vector &b,const Vector &c)
{
	Circle res;
	res.o=CrossPt(Trans({a,b-a}),Trans({a,c-a}));
	res.r=Dist(res.o,a);
	return res;
}

const int N=52000;

int n;
Vector p[N];

void RotateAll(double a)
{
	Vector v={cos(a),sin(a)};
	for(int i=1;i<=n;++i)
		p[i]*=v;
}

void CompressAll(double a)
{
	for(int i=1;i<=n;++i)
		p[i].x*=a;
}

void RandomWork()
{
	random_shuffle(p+1,p+n+1);
	RotateAll(233);
}

double Calc()
{
	RandomWork();

	Circle c;
	c.o={0,0};
	c.r=0;
	for(int i=1;i<=n;++i)if(!inCircle(c,p[i]))
	{
		c.o=p[i];
		c.r=0;
		for(int j=1;j<i;++j)if(!inCircle(c,p[j]))
		{
			c=MakeCircle(p[i],p[j]);
			for(int k=1;k<=j;++k)if(!inCircle(c,p[k]))
				c=MakeCircle(p[i],p[j],p[k]);
		}
	}

	return c.r;
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		p[i].Read();

	double a;
	scanf("%lf",&a);
	a=a*PI/180;
	RotateAll(-a);
	scanf("%lf",&a);
	CompressAll(1.0/a);

	printf("%.3lf",Calc());
	return 0;
}
