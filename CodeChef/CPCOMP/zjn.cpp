#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>

using namespace std;

#define SIZE 506
#define U unsigned int

namespace ZJN
{

	int ss[1000001],cnt,p[1000001];
	short g[1001][1001],b[1000001];
	int f[1000001][3];
	int a[2001],bb[2001];

	int pregcd(int x,int y){
		if (y==0) {g[x][y]=x;return(x);}
		if (g[x][y]!=-1) return(g[x][y]);
		g[x][y]=pregcd(y,x%y);
		return(g[x][y]);
	}

	void euler(){
		p[1]=1;
		for (int i=2;i<=SIZE*SIZE;i++){
			if (!b[i]){
				p[i]=i;ss[++cnt]=i;
			}    
			for (int j=1;ss[j]*i<=SIZE*SIZE&&j<=cnt;j++){
				b[ss[j]*i]=1;
				p[ss[j]*i]=ss[j];
				if (i%ss[j]==0) break;
			}
		}
	}

	int gcd(int x,int y){
		if (x<=SIZE&&y<=SIZE) return(g[x][y]);
		int d=1;
		for (int i=0;i<=2;i++)
			if (p[f[x][i]]==f[x][i]){
				if (y%f[x][i]==0){
					d*=f[x][i];y/=f[x][i];    
				}
			}else{
				int t=g[f[x][i]][y%f[x][i]];
				d*=t;y/=t;
			}
		return(d);  
	}

	void Prework(){
		for (int i=0;i<=SIZE;i++)
			for (int j=0;j<=SIZE;j++)
				g[i][j]=-1;
		for (int i=0;i<=SIZE;i++)
			for (int j=0;j<=SIZE;j++)
				pregcd(i,j);//预处理SIZE以内gcd

		euler();

		f[1][0]=f[1][1]=f[1][2]=1;
		for (int i=2;i<=SIZE*SIZE;i++){
			memcpy(f[i],f[i/p[i]],sizeof(f[i]));    
			if (f[i][0]<=SIZE/p[i]) f[i][0]*=p[i];else
				if (f[i][1]<=SIZE/p[i]) f[i][1]*=p[i];else
					f[i][2]*=p[i];
		}//预处理所有数的分解
	}

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

const int N=2e5+10;

int n,fa[N];
Pir p[N];

int Find(int x)
{
	return fa[x]?(fa[x]=Find(fa[x])):x;
}

void Hb(int x,int y)
{
	if((x=Find(x))!=(y=Find(y)))
		fa[x]=y;
}

void Work()
{
	for(int i=1;i<=n;++i)
		Find(i);
	for(int i=1,j,d;i<=n;i=j+1)
	{
		d=p[i].fir;
		for(j=i;j<n&&d>1;d=Gcd(d,p[++j].fir));
		for(int k=j-1;k>=i;--k)if(fa[j]!=fa[k]&&Gcd(p[k].fir,p[j].fir)==1)
			Hb(p[k].sec,p[j].sec);
	}
}

int main()
{
	srand(12345);
	ZJN::Prework();
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&p[i].fir);
		p[i].sec=i;
		if(p[i].fir==1)
		{
			puts("1");
			return 0;
		}
	}
	sort(p+1,p+n+1);
	Work();
	for(int cc=6000000/n;--cc;)
	{
		random_shuffle(p+1,p+n+1);
		Work();
	}
	int ans=0;
	for(int i=1;i<=n;++i)
		ans+=(fa[i]==0);
	printf("%d",ans);
	return 0;
}
