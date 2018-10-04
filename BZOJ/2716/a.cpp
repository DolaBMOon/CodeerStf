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

#define int long long

struct Vector
{

	int x,y;

	void Read()
	{
	}

};

Vector operator*(const Vector &a,const Vector &b)
{
	return (Vector){a.x*b.x+a.y*b.y,a.x*b.y-a.y*b.x};
}

Vector operator*=(Vector &a,const Vector &b)
{
	return a=a*b;
}

Vector operator+(const Vector &a,const Vector &b)
{
	return (Vector){a.x+b.x,a.y+b.y};
}

Vector operator-(const Vector &a,const Vector &b)
{
	return (Vector){a.x-b.x,a.y-b.y};
}

int Det(const Vector &a,const Vector &b)
{
	return a.x*b.y-a.y*b.x;
}

int Dot(const Vector &a,const Vector &b)
{
	return a.x*b.x+a.y*b.y;
}

int Dist(const Vector &a,const Vector &b)
{
	int x=a.x-b.x,y=a.y-b.y;
	return x*x+y*y;
}

int n;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
	}
	return 0;
}
