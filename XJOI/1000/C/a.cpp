#include<bits/stdc++.h>

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

struct Data
{
	int w,x,y;
}d[3];

bool Cmp(const Data &a,const Data &b)
{
	return a.w<b.w;
}

int id[3],inv[3];
vector<int> v[3];

int main()
{
	scanf("%d%d%d",&d[0].w,&d[1].w,&d[2].w);
	d[0].x=0;
	d[0].y=1;
	d[1].x=1;
	d[1].y=2;
	d[2].x=2;
	d[2].y=0;
	sort(d,d+3,Cmp);
	while(d[0].x!=d[1].y||d[1].x!=d[2].x)
	{
		if(rand()&1)
			swap(d[0].x,d[0].y);
		if(rand()&1)
			swap(d[1].x,d[1].y);
		if(rand()&1)
			swap(d[2].x,d[2].y);
	}
	//for(int i=0;i<3;++i)
	//	cout<<d[i].x<<","<<d[i].y<<endl;
	id[d[1].x]=0;
	id[d[1].y]=1;
	id[d[0].y]=2;
	//assert(d[2].x==id[0]&&d[2].y==id[2]);
	//Whats(d[0].w);
	for(int i=0;i<d[0].w;++i)
	{
		v[1].push_back(0);
		v[2].push_back(0);
	}
	for(int i=0;i<d[1].w;++i)
	{
		v[0].push_back(1);
		v[1].push_back(1);
	}
	for(int i=0;i<d[2].w;++i)
		v[0].push_back(0);
	for(int i=0;i<d[2].w-d[0].w;++i)
		v[2].push_back(0);
	for(int i=0;i<3;++i)
	{
		vector<int> &t=v[id[i]];
		for(int j=(int)t.size()-1;j>=0;--j)
			printf("%d",t[j]);
		puts("");
	}
	return 0;
}
