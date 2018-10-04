//题意理解错误QAQ
#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<set>

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

	int Abs() const
	{
		return x*x+y*y;
	}

};

const Vector Ro=(Vector){7,13};

namespace
{

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

	void Gether(Vector &v)
	{
		scanf("%lld%lld",&v.x,&v.y);
		v*=Ro;
	}

}

struct Cmp
{
	bool operator()(const Vector &a,const Vector &b)
	{
		return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);
	}
};

int Sqr(int x)
{
	return x*x;
}

const int N=3e5+10;
const int INF=0x3f3f3f3f3f3f3f3f;

int n,m;
set<Vector,Cmp> S;

int GetM(Vector p)
{
	int ans=INF;
	for(Vector v:S)
		GetMin(ans,Dist(v,p));
	return ans/Ro.Abs();
	set<Vector,Cmp>::iterator it=S.upper_bound(p),a=it,b=it;
	int res=INF;
	if(a==S.end()||a->x>p.x)
		--a;
	while(true)
	{
		GetMin(res,Dist(p,*a));
		if(Sqr(p.x-a->x)>=res||a==S.begin())
			break;
		--a;
	}
	while(true)
	{
		if(b!=S.end())
		{
			GetMin(res,Dist(p,*b));
			if(Sqr(b->x-p.x)>=res)
				break;
			++b;
		}
		else
			break;
	}
	return res/Ro.Abs();
}

signed main()
{
	scanf("%lld%lld",&n,&m);
	Vector t;
	for(int i=1;i<=n;++i)
	{
		Gether(t);
		S.insert(t);
	}
	for(int i=1,ty;i<=m;++i)
	{
		scanf("%lld",&ty);
		Gether(t);
		if(ty&1)
			S.insert(t);
		else
			printf("%lld\n",GetM(t));
	}
	return 0;
}
