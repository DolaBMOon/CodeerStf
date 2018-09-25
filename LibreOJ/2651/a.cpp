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

#define Angle Vector

const int N=100000+10;

struct Vector
{

	int x,y;

	void Read()
	{
		scanf("%d%d",&x,&y);
	}

}p[N];

int n;
int s[N];

void Work()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
		p[i].Read();
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
