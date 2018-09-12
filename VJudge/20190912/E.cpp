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
const int Dx[4]={-1,0,1,0};
const int Dy[4]={0,-1,0,1};

int n,m,c,q;
int d[N][N][4],col[N][N],res[N];

int Get(int x,int y)
{
	int *t=d[x][y];
	return min(min(t[0],t[1]),min(t[2],t[3]));
}

void Minus(int x,int y)
{
	res[col[x][y]]-=Get(x,y);
}

void Add(int x,int y)
{
	res[col[x][y]]+=Get(x,y);
}

void Update(int x,int y,int f)
{
	if(col[x][y]==col[x+Dx[f]][y+Dy[f]])
		d[x][y][f]=d[x+Dx[f]][y+Dy[f]][f]+1;
	else
		d[x][y][f]=0;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&c,&q);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&col[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			if(col[i][j]==col[i-1][j])
				d[i][j][0]=d[i-1][j][0]+1;
			if(col[i][j]==col[i][j-1])
				d[i][j][1]=d[i][j-1][1]+1;
		}
	for(int i=n;i>=1;--i)
		for(int j=m;j>=1;--j)
		{
			if(col[i][j]==col[i+1][j])
				d[i][j][2]=d[i+1][j][2]+1;
			if(col[i][j]==col[i][j+1])
				d[i][j][3]=d[i][j+1][3]+1;
		}
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			Add(i,j);
	char s[5];
	for(int i=1,x,y,c;i<=q;++i)
	{
		scanf("%s",s);
		if(*s=='Q')
		{
			scanf("%d",&x);
			printf("%d\n",res[x]);
		}
		else
		{
			scanf("%d%d%d",&x,&y,&c);
			Minus(x,y);
			col[x][y]=c;
			for(int i=0;i<4;++i)
				Update(x,y,i);
			Add(x,y);
			for(int j=x+1;j<=n;++j)
			{
				Minus(j,y);
				Update(j,y,0);
				Add(j,y);
			}
			for(int j=y+1;j<=m;++j)
			{
				Minus(x,j);
				Update(x,j,1);
				Add(x,j);
			}
			for(int j=x-1;j>=1;--j)
			{
				Minus(j,y);
				Update(j,y,2);
				Add(j,y);
			}
			for(int j=y-1;j>=1;--j)
			{
				Minus(x,j);
				Update(x,j,3);
				Add(x,j);
			}
			//Whats(d[2][2][3]);
		}
	}
	return 0;
}
