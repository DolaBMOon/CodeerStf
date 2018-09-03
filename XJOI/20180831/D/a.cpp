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

const int N=2333;

struct Vector
{
	double x,y;
}v[N];

Vector operator-(const Vector& a,const Vector& b)
{
	return (Vector){a.x-b.x,a.y-b.y};
}

Vector operator*(const Vector& a,const Vector& b)
{
	return (Vector){a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x};
}

ostream& operator<<(ostream& os,const Vector& b)
{
	os<<"("<<b.x<<","<<b.y<<")"<<endl;
}

double Det(const Vector& a,const Vector& b)
{
	return a.x*b.y-a.y*b.x;
}

void Read(Vector& v)
{
	scanf("%lf%lf",&v.x,&v.y);
}

bool Cmp(const Vector& a,const Vector& b)
{
	return (a.x!=b.x)?(a.x<b.x):(a.y<b.y);
}

int n,tp;
Vector stk[N+N];

void Gao()
{
	double a=rand();
	Vector d=(Vector){cos(a),sin(a)};
	for(int i=1;i<=n;++i)
		v[i]=v[i]*d;
}

int main()
{
	srand((unsigned long long)new char);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		Read(v[i]);
	Gao();
	sort(v+1,v+n+1,Cmp);
	for(int i=1;i<=n;++i)
	{
		for(;tp>=2&&Det(v[i]-stk[tp-1],stk[tp]-stk[tp-1])<0;--tp);
		stk[++tp]=v[i];
	}
	int rec=tp;
	for(int i=n-1;i;--i)
	{
		for(;tp>rec&&Det(v[i]-stk[tp-1],stk[tp]-stk[tp-1])<0;--tp);
		stk[++tp]=v[i];
	}
	double ans=0;
	for(int i=1;i<tp;++i)
		ans+=Det(stk[i],stk[i+1]);
	printf("%.2lf",-0.5*ans);
	return 0;
}
