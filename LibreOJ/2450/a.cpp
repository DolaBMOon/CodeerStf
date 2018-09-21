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

const int N=666;
const int M=23333;

struct Vector
{

	int x,y;

	void Read()
	{
		scanf("%lld%lld",&x,&y);
	}

}p[N],she[N];

Vector operator-(const Vector &a,const Vector &b)
{
	return (Vector){a.x-b.x,a.y-b.y};
}

Vector operator-=(Vector &a,const Vector &b)
{
	return a=a-b;
}

Vector operator+(const Vector &a,const Vector &b)
{
	return (Vector){a.x+b.x,a.y+b.y};
}

Vector operator+=(const Vector &a,const Vector &b)
{
	return a=a+b;
}

int Det(const Vector &a,const Vector &b)
{
	return a.x*b.y+a.y*b.x;
}

int n,ki,m;

signed main()
{
	scanf("%lld%lld%lld",&n,&ki,&m);
	for(int i=1;i<=n;++i)
		p[i].Read();
	for(int i=1;i<=ki;++i)
		she[i].Read();
	for(int i=1;i<=n;++i)
	{
		sort(she+1,she+ki+1,Cmp());
	}
	return 0;
}
