#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=233;

struct Data
{
	int x,y,v,rd;
}d[N];

int tot;

bool Faithful(int x)
{
	return rand()<=RAND_MAX*(double)x/100.0;
}

bool Cmp(const Data& a,const Data& b)
{
	return (a.v!=b.v)?(a.v>b.v):(a.rd<b.rd);
}

int Dis(const Data& a,const Data& b)
{
	return abs(a.x-b.x)+abs(a.y-b.y);
}

int m,n,k;

int main()
{
	srand((unsigned long long)new char);

	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=m;++i)
		for(int j=1,a;j<=n;++j)
		{
			scanf("%d",&a);
			if(a)
				d[++tot]=(Data){i,j,a};
		}

	int ans=0;
	for(int cc=233;--cc;)
		for(int p=0;p<=100;++p)
		{
			for(int i=1;i<=tot;++i)
				d[i].rd=rand();
			sort(d+1,d+tot+1,Cmp);
			Data nw=(Data){0,d[1].y,0};
			int nk=k;
			for(int i=1;i<=tot;++i)
			{
				for(int j=i+1;d[j].v==d[i].v;++j)if(Dis(nw,d[j])<=Dis(nw,d[i])&&Faithful(p))
					swap(d[i],d[j]);
				if(Dis(nw,d[i])+1+d[i].x>nk)
					break;
				nk-=Dis(nw,d[i])+1;
				nw.x=d[i].x;
				nw.y=d[i].y;
				nw.v+=d[i].v;
			}
			ans=max(ans,nw.v);
		}
	printf("%d",ans);
	return 0;
}
