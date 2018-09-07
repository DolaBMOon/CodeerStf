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

const int N=233;
const double PI=3.141592653589793;

struct Vector
{

	double x,y,z;

	bool Read()
	{
		return ~scanf("%lf%lf%lf",&x,&y,&z);
	}	

}p[N];

Vector operator-(const Vector &a,const Vector &b)
{
	return (Vector){a.x-b.x,a.y-b.y,a.z-b.z};
}

Vector operator-=(Vector &a,const Vector &b)
{
	a.x-=b.x;
	a.y-=b.y;
	a.z-=b.z;
	return a;
}

Vector operator+(const Vector &a,const Vector &b)
{
	return (Vector){a.x+b.x,a.y+b.y,a.z+b.z};
}

Vector operator+=(Vector &a,const Vector &b)
{
	a.x+=b.x;
	a.y+=b.y;
	a.z+=b.z;
	return a;
}

Vector operator*(const double &a,const Vector &b)
{
	return (Vector){a*b.x,a*b.y,a*b.z};
}

ostream& operator<<(ostream &os,const Vector &v)
{
	os<<"("<<v.x<<","<<v.y<<","<<v.z<<")";
	return os;
}

Vector Cross(const Vector &a,const Vector &b)
{
	return (Vector){a.y*b.z-a.z*b.y,a.z*b.x-a.x*b.z,a.x*b.y-a.y*b.x};
}

double Dot(const Vector &a,const Vector &b)
{
	return a.x*b.x+a.y*b.y+a.z*b.z;
}

double Det(Vector a,Vector b,Vector c)
{
	return Dot(Cross(a,b),c);
}

int n;

void RandomWork()
{
	random_shuffle(p+1,p+n+1);
	double a=rand(),x=cos(a),y=sin(a),z,tx,ty,tz;
	for(int i=1;i<=n;++i)
	{
		tx=x*p[i].x-y*p[i].y;
		ty=x*p[i].y+y*p[i].x;
		p[i].x=tx;
		p[i].y=ty;
	}
	a=rand();
	z=cos(a);
	y=sin(a);
	for(int i=1;i<=n;++i)
	{
		tz=z*p[i].z-y*p[i].y;
		ty=z*p[i].y+y*p[i].z;
		p[i].z=tz;
		p[i].y=ty;
	}
	a=rand();
	z=cos(a);
	y=sin(a);
	for(int i=1;i<=n;++i)
	{
		tz=z*p[i].z-y*p[i].y;
		ty=z*p[i].y+y*p[i].z;
		p[i].z=tz;
		p[i].y=ty;
	}
	a=rand();
	z=cos(a);
	x=sin(a);
	for(int i=1;i<=n;++i)
	{
		tz=z*p[i].z-x*p[i].x;
		tx=z*p[i].x+x*p[i].z;
		p[i].z=tz;
		p[i].x=tx;
	}
}

int dcmp(double x)
{
	return (x<0)?-1:1;
}

//void Test()
//{
//	Vector a={1,2,1},b={1,1,5},c=Cross(a,b);
//	Whats(Dot(a,c));
//	exit(0);
//}

int main()
{
	//Whats(Det({1,0,0},{0,1,0},{0,0,1}));
	srand(486);
	for(;p[n+1].Read();++n);
	RandomWork();
	double minx=233;
	for(int i=1;i<=n;++i)
		GetMin(minx,p[i].x);
	Vector o=(Vector){0,0,0};
	for(int i=1;i<=n;++i)if(minx==p[i].x)
	{
		o=p[i];
		break;
	}

	double ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			for(int k=1;k<j;++k)
			{
				Vector u=p[i],v=Cross(p[j]-u,p[k]-u);
				//Whats(Dot(p[j]-u,v));
				bool ok=true;
				for(int l=1,a=0,b;l<=n&&ok;++l)if(l!=i&&l!=j&&l!=k)
				{
					b=dcmp(Dot(v,p[l]-u));
					if(a)
					{
						if(a!=b)
							ok=false;
					}
					else
						a=b;
				}
				if(ok)
				{
					ans+=abs(Det(p[i]-o,p[j]-o,p[k]-o));
					if(abs(Det(p[i]-o,p[j]-o,p[k]-o))==1)
						cout<<"("<<i<<" "<<j<<" "<<k<<")"<<endl;
				}
			}
	ans/=6;
	printf("%.2lf",ans);
	return 0;
}
