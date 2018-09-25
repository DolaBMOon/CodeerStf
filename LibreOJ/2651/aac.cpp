#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<cstring>

#define N 10000007
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
int s[N],f[N];
struct Node
{
	int x,y;
}a[N];

int dis(int c,int b)
{
	return (a[c].x-a[b].x)*(a[c].x-a[b].x)+(a[c].y-a[b].y)*(a[c].y-a[b].y);
}
int cro(int d,int b,int c)
{
	return (a[b].x-a[d].x)*(a[c].y-a[d].y)-(a[c].x-a[d].x)*(a[b].y-a[d].y);
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read();
		for (int i=0;i<n;i++)
			a[i].x=read(),a[i].y=read();
		for (int i=0;i<n;i++) s[i<<1|1]=dis(i,(i+1)%n);
		for (int i=0;i<n;i++) s[i<<1]=cro(i,(i-1+n)%n,(i+1)%n);
		int total=n<<1;
		for (int i=0;i<n;i++) s[i+total]=s[i];
		total<<=1;
		int ans=0,mx=0,id=0;
		memset(f,0,sizeof(f));
		for (int i=0;i<total;i++)
		{
			if (mx>i) f[i]=min(mx-i,f[2*id-i]);else f[i]=1;
			while(i-f[i]>=0&&i+f[i]<=total&&s[i-f[i]]==s[i+f[i]]) f[i]++;
			if (i+f[i]>mx) mx=i+f[i],id=i;
			if (f[i]>=n+1) ans++;
		}
		printf("%d\n",ans);
	}
}
