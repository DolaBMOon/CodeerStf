#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

#define SIZE 506
#define U unsigned int

const int N=2e5+10;
const int sn=sqrt(N);

namespace ZJN
{

	bool np[N+5];
	int ps[N+5],pn=0;
	int cs[N+5][3];
	void xs()
	{
		np[1]=cs[1][0]=cs[1][1]=cs[1][2]=1;
		for(int i=2;i<=N;i++)
		{
			if(!np[i]) {cs[i][0]=cs[i][1]=1; cs[i][2]=i; ps[++pn]=i;}
			for(int j=1;j<=pn&&i*ps[j]<=N;j++)
			{
				np[i*ps[j]]=1;
				int cm=cs[i][0]*ps[j];
				if(cm<cs[i][1])
				{
					cs[i*ps[j]][0]=cm;
					cs[i*ps[j]][1]=cs[i][1];
					cs[i*ps[j]][2]=cs[i][2];
				}
				else if(cm<cs[i][2])
				{
					cs[i*ps[j]][0]=cs[i][1];
					cs[i*ps[j]][1]=cm;
					cs[i*ps[j]][2]=cs[i][2];
				}
				else
				{
					cs[i*ps[j]][0]=cs[i][1];
					cs[i*ps[j]][1]=cs[i][2];
					cs[i*ps[j]][2]=cm;
				}
				if(i%ps[j]);else break;
			}
		}
	}
	int gcdd[sn+3][sn+3];
	void smgcd()
	{
		for(int i=0;i<=sn;i++) gcdd[i][0]=gcdd[0][i]=i;
		for(int i=1;i<=sn;i++)
		{
			for(int j=1;j<=i;j++) gcdd[i][j]=gcdd[j][i]=gcdd[i-j][j];
		}
	}
	void pre_gcd() {xs(); smgcd();}
	int gcd(int a,int b)
	{
		if(a>N||b>N)
		{
			puts("Fuck You\n");
			return -1;
		}
		int *x=cs[a],g=1;
		for(int i=0;i<3;i++)
		{
			int d;
			if(x[i]<=sn) d=gcdd[x[i]][b%x[i]];
			else if(b%x[i]) d=1;
			else d=x[i];
			g*=d; b/=d;
		}
		return g;
	}	

}

const int _B=1e6;

char Nc()
{
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int sum=ch-48;
	while(isdigit(ch=Nc()))
		sum=sum*10+ch-48;
	return sum;
}

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

#define Gcd(x,y) ZJN::gcd(x,y)
#define Pir pair<int,int>
#define fir first
#define sec second

int n,ans,fa[N];
Pir p[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

void Hb(int x,int y)
{
	x=Find(x);
	y=Find(y);
	if(x!=y)
	{
		fa[x]=y;
		--ans;
	}
}

void Work()
{
	for(int i=1,j,d;i<=n;i=j+1)
	{
		d=p[i].fir;
		for(j=i;j<n&&d>1;d=Gcd(d,p[++j].fir));
		for(int k=i;k<j;++k)if(Gcd(p[k].fir,p[j].fir)==1)
			Hb(p[k].sec,p[j].sec);
	}
}

int main()
{
	srand(520);
	ZJN::pre_gcd();
	n=Read();
	ans=n;
	for(int i=1;i<=n;++i)
	{
		p[i].fir=Read();
		p[i].sec=i;
		if(p[i].fir==1)
		{
			puts("1");
			return 0;
		}
	}
	sort(p+1,p+n+1);
	Work();
	for(int cc=7000000/n;--cc;)
	{
		random_shuffle(p+1,p+n+1);
		Work();
	}
	printf("%d",ans);
	return 0;
}
