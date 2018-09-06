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

/*
-<Unlimited Blade Works>-
*/

#define Pir pair<int,int>
#define fir first
#define sec second

const int M=10;
const int N=5200;
const int B=520;

int n,m,d[M];
bool vis[B][N];
Pir p[B][N];

void Print(int i,int j)
{
	if(i)
	{
		printf("%d",p[i][j].fir);
		Print(i-1,p[i][j].sec);
	}
}

template<typename T> void GetMin(T &x,T y)
{
	x=((x<y)?x:y);
}

void Update(int i,int j,int k,int k2)
{
	if(vis[i][j])
		GetMin(p[i][j],Pir(k,k2));
	else
	{
		vis[i][j]=true;
		p[i][j]=Pir(k,k2);
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	bool fl=false;
	for(int i=0;i<m;++i)
	{
		scanf("%d",d+i);
		if(!d[i])
			fl=true;
	}
	vis[0][0]=true;

	for(int i=0,pw=1;i<B-1;++i,pw=pw*10%n)
	{
		for(int j=0;j<n;++j)if(vis[i][j])
			for(int k=0;k<m;++k)if(d[k])
				Update(i+1,(j+pw*d[k])%n,d[k],j);

		if(vis[i+1][0])
		{
			Print(i+1,0);
			return 0;
		}

		if(fl)
			for(int j=0;j<n;++j)if(vis[i][j])
				Update(i+1,j,0,j);
	}
	puts("0");
	return 0;
}
