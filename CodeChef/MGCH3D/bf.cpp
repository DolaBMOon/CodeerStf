#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

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

const int N=233;
const int Y=77;

int n,q;
int x[N],y[N],z[N];
int cnt[2*Y][2*Y][2*Y];

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)
		scanf("%d%d%d",x+i,y+i,z+i);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(i!=j)
			++cnt[x[i]-x[j]+Y][y[i]-y[j]+Y][z[i]-z[j]+Y];
	for(int i=-Y;i<Y;++i)
		for(int j=-Y;j<Y;++j)
			for(int k=-Y;k<Y;++k)if(cnt[i+Y][j+Y][k+Y])
				cout<<i<<","<<j<<","<<k<<":"<<cnt[i+Y][j+Y][k+Y]<<endl;
	return 0;
}
