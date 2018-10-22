#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=500000+10;

int n,m,h[N],a[N],b[N],p[N],lst[N<<1],ed;
vector<int> Q[N];

int C[N],f[N],f2[N],cnt[N];
bool im[N];

int Inv(int x)
{
	return ed-x+1;
}

void Update(int x,int y)
{
	for(;x<=ed;x+=x&(-x))
		GetMax(C[x],y);
}

int Query(int x)
{
	int res=0;
	for(;x;x&=x-1)
		GetMax(res,C[x]);
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",h+i);
		lst[++ed]=h[i];
	}
	for(int i=1;i<=m;++i)
	{
		scanf("%d%d",a+i,b+i);
		Q[a[i]].push_back(i);
		lst[++ed]=b[i];
	}
	sort(lst+1,lst+ed+1);
	ed=unique(lst+1,lst+ed+1)-lst-1;
	for(int i=1;i<=n;++i)
		h[i]=lower_bound(lst+1,lst+ed+1,h[i])-lst;
	for(int i=1;i<=m;++i)
		b[i]=lower_bound(lst+1,lst+ed+1,b[i])-lst;
	for(int i=1;i<=n;++i)
	{
		f[i]=Query(h[i]-1);
		for(int j=0;j<(int)Q[i].size();++j)
			p[Q[i][j]]=Query(b[Q[i][j]]-1);
		Update(h[i],f[i]+1);
	}
	memset(C,0,sizeof C);
	for(int i=n;i>=1;--i)
	{
		f2[i]=Query(Inv(h[i])-1);
		for(int j=0;j<(int)Q[i].size();++j)
			p[Q[i][j]]+=Query(Inv(b[Q[i][j]])-1)+1;
		Update(Inv(h[i]),f2[i]+1);
	}
	int mxl=0;
	for(int i=1;i<=n;++i)
		GetMax(mxl,f[i]+f2[i]+1);
	for(int i=1;i<=n;++i)if(f[i]+f2[i]+1==mxl)
		++cnt[f[i]];
	for(int i=1;i<=n;++i)if(f[i]+f2[i]+1==mxl&&cnt[f[i]]==1)
	{
		im[i]=true;
		//Whats(i);
	}
	for(int i=1;i<=m;++i)
		printf("%d\n",max(p[i],(im[a[i]]?(mxl-1):mxl)));
	return 0;
}
