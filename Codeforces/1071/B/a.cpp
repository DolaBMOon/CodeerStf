#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>
#include<vector>

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

const int N=2333;
const int INF=0x3f3f3f3f;

struct Data
{
	int x,y,ch,w;
};

int n,k,cnt[N][N],rk[N][N];
char mp[N][N];

bool Cmp(const Data &a,const Data &b)
{
	return (a.ch!=b.ch)?(a.ch<b.ch):(a.w<b.w);
}

bool Equ(const Data &a,const Data &b)
{
	return a.ch==b.ch&&a.w==b.w;
}

int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)
		scanf("%s",mp[i]+1);
	for(int i=1;i<=n;++i)
		rk[i][n+1]=rk[n+1][i]=INF;
	vector<Data> v;
	for(int s=2*n;s>=1;--s)
	{
		v.clear();
		for(int i=1,j=s-i;i<=n;++i,--j)if(1<=i&&i<=n&&1<=j&&j<=n)
			v.push_back((Data){i,j,mp[i][j],min(rk[i+1][j],rk[i][j+1])});
		//if(s==4)
		//{
		//	for(auto i:v)
		//		cout<<i.x<<","<<i.y<<":"<<i.ch<<","<<i.w<<endl;
		//}
		sort(v.begin(),v.end(),Cmp);
		for(int i=0,tot=0;i<(int)v.size();++i)
		{
			if(!i||!Equ(v[i-1],v[i]))
				++tot;
			rk[v[i].x][v[i].y]=tot;
		}
	}
	//for(int i=1;i<=n;++i)
	//{
	//	for(int j=1;j<=n;++j)
	//	{
	//		cout<<rk[i][j]<<" ";
	//	}
	//	puts("");
	//}
	v.clear();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			cnt[i][j]=max(cnt[i-1][j],cnt[i][j-1])+(mp[i][j]=='a');
			if(i+j-1-k<=cnt[i][j])
				v.push_back((Data){i,j,-i-j+1,min(rk[i+1][j],rk[i][j+1])});
		}
	sort(v.begin(),v.end(),Cmp);
	int ax=1,ay=1;
	if(v.empty())
		putchar(mp[1][1]);
	else
	{
		ax=v[0].x;
		ay=v[0].y;
		for(int i=-v[0].ch;i>=1;--i)
			putchar('a');
	}
	while(ax!=n||ay!=n)
	{
		Data t=(Data){ax+1,ay,rk[ax+1][ay]},t2=(Data){ax,ay+1,rk[ax][ay+1]};
		if(!Cmp(t,t2))
			t=t2;
		ax=t.x;
		ay=t.y;
		putchar(mp[ax][ay]);
	}
	return 0;
}
