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

int n,k,R;
Vector p[N],v[N];

vector<int> tm[N];

void Biu(Vector& p,Vector& v,vector<int>& res)
{
	res.clear();
	double m=v.Abs();
	Vector a=-p;
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
		Biu(p[i],v[i],tm[i]);
	}
	return 0;
}
