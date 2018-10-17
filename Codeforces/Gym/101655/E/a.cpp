#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<queue>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

const int H=2333;
const int INF=0x3f3f3f3f;
const int Dx[4]={0,1,0,-1};
const int Dy[4]={1,0,-1,0};

int ki,w,h;
int val[233];

char mp[H][H];
int d[H][H],ad[H][H];
bool vis[H][H];

struct Data
{
	int x,y,v;
};

struct Cmp
{
	bool operator()(const Data &a,const Data &b)
	{
		return a.v>b.v;
	}
};

priority_queue<Data,vector<Data>,Cmp> Q;

void Spfa()
{
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j)
			ad[i][j]=val[(int)mp[i][j]];
	memset(d,0x3f,sizeof d);
	memset(vis,0,sizeof vis);
	for(int i=1;i<=h;++i)
		for(int j=1;j<=w;++j)if(mp[i][j]=='E')
		{
			Q.push((Data){i,j,0});
			d[i][j]=0;
		}
	while(!Q.empty())
	{
		Data u=Q.top();
		Q.pop();
		if(vis[u.x][u.y])
			continue;
		vis[u.x][u.y]=true;
		Data v;
		for(int i=0;i<4;++i)
		{
			if((v.x=u.x+Dx[i])<1||v.x>h)
				continue;
			if((v.y=u.y+Dy[i])<1||v.y>w)
				continue;
			v.v=u.v+ad[v.x][v.y];
			if(GetMin(d[v.x][v.y],v.v))
				Q.push(v);
		}
	}
}

void Work()
{
	scanf("%d%d%d",&ki,&w,&h);
	char s[3];
	for(int i=1,x;i<=ki;++i)
	{
		scanf("%s%d",s,&x);
		val[(int)(*s)]=x;
	}
	for(int i=1;i<=h;++i)
		scanf("%s",mp[i]+1);
	Spfa();
	int ans=INF;
	for(int i=1;i<=h;++i)
		GetMin(ans,min(d[i][1],d[i][w]));
	for(int i=1;i<=w;++i)
		GetMin(ans,min(d[1][i],d[h][i]));
	printf("%d\n",ans);
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
