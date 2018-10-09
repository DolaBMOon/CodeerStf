#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

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

const int N=55;
const int INF=0x3f3f3f3f;

struct Vector
{

	int x,y;

	void Read()
	{
		scanf("%d%d",&x,&y);
	}

}p[N];

int n,k,ans=INF;
int A[N],B[N],C[N],D[N];

bool Check(int x0,int x1,int y0,int y1,int cnt)
{
	for(int i=1;i<cnt;++i)
		if(max(x0,A[i])<=min(x1,B[i])&&max(y0,C[i])<=min(y1,D[i]))
			return true;
	return false;
}

void Work()
{
	int res=0,cnt=1,nw=0,x0=INF,x1=-INF,y0=INF,y1=-INF,a,b,c,d;
	for(int i=1;i<=n;++i)
	{
		bool fl=false;
		for(int j=1;j<cnt&&!fl;++j)
			if(A[j]<=p[i].x&&p[i].x<=B[j]&&C[j]<=p[i].y&&p[i].y<=D[j])
				fl=true;
		if(fl)
			continue;
		a=x0;
		b=x1;
		c=y0;
		d=y1;
		fl|=GetMin(x0,p[i].x);
		fl|=GetMax(x1,p[i].x);
		fl|=GetMin(y0,p[i].y);
		fl|=GetMax(y1,p[i].y);
		if(fl)
		{
			++nw;
			if(Check(x0,x1,y0,y1,cnt)||(nw>(rand()%4+1)&&cnt<k))
			{
				res+=(b-a)*(d-c);
				A[cnt]=a;
				B[cnt]=b;
				C[cnt]=c;
				D[cnt]=d;
				nw=0;
				x0=x1=p[i].x;
				y0=y1=p[i].y;
				++cnt;
				if(cnt>k)
					return;
			}
		}
	}
	res+=(x1-x0)*(y1-y0);
	GetMin(ans,res);
}

bool Cmpx(const Vector &a,const Vector &b)
{
	return a.x<b.x;
}

bool Cmpy(const Vector &a,const Vector &b)
{
	return a.y<b.y;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		p[i].Read();
	for(int cc=500000;cc--;)
	{
		random_shuffle(p+1,p+n+1);
		Work();
	}
	printf("%d",ans);
	return 0;
}
