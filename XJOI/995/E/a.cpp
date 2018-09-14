#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<cmath>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
	 -<Unlimited Blade Works>-
 */

const int N=233;

struct Vector
{
	double x,y;

	double Abs()
	{
		return sqrt(x*x+y*y);
	}

	double Abs2()
	{
		return x*x+y*y;
	}

	double Fix()
	{
		double d=Abs();
		x/=d;
		y/=d;
	}

	double Dot(const Vector& v)
	{
		return x*v.x+y*v.y;
	}

	double Det(const Vector& v)
	{
		return x*v.y-y*v.x;
	}

	void Read()
	{
		scanf("%lf%lf",&x,&y);
	}
};

Vector operator+(const Vector& a,const Vector& b)
{
	return {a.x+b.x,a.y+b.y};
}

void operator+=(Vector& a,const Vector& b)
{
	a.x+=b.x;
	a.y+=b.y;
}

Vector operator-(const Vector& a,const Vector& b)
{
	return {a.x-b.x,a.y-b.y};
}

void operator-=(Vector& a,const Vector& b)
{
	a.x-=b.x;
	a.y-=b.y;
}

Vector operator*(const Vector& a,const Vector& b)
{
	return {a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

Vector operator/(const Vector& a,Vector b)
{
	b.y*=-1;
	return a*b;
}

Vector operator*(const Vector& a,const double b)
{
	return {a.x*b,a.y*b};
}

Vector operator*(const double a,const Vector& b)
{
	return {a*b.x,a*b.y};
}

Vector operator/(const Vector& a,const double b)
{
	return {a.x/b,a.y/b};
}

Vector operator-(const Vector& a)
{
	return {-a.x,-a.y};
}

double Sqr(double x)
{
	return x*x;
}

int n,k,R;
Vector p[N],v[N];

vector<int> tm[N];

vector<int> Biu(Vector p,Vector v)
{
	static vector<int> res(k);
	double m=v.Abs();
	v.Fix();
	for(int i=0;i<k;++i)
	{
		Vector q=-p;
		double a=v.Dot(q),b=sqrt(R*R-(p.Abs2()-Sqr(a)));
	}
}

int main()
{
	Vector o_o;
	o_o.Read();
	scanf("%lf%d%d",&R,&n,&k);
	for(int i=1;i<=n;++i)
	{
		p[i].Read();
		p[i]-=o_o;
		v[i].Read();
		tm[i]=Biu(p[i],v[i]);
	}
	return 0;
}
