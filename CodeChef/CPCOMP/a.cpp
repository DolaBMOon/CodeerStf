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

const int N=2e5+10;

int n,A[N],ans;
vector<int> D[N],G[N];

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

int fa[N];

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

int main()
{
	scanf("%d",&n);
	ans=n;
	for(int i=1;i<=n;++i)
		scanf("%d",A+i);
	for(int i=2;i<N;++i)
		for(int j=i;j<N;j+=i)
			D[j].emplace_back(i);
	sort(A+1,A+n+1);
	for(int i=1;i<=n;++i)
		for(int j:D[A[i]])
			G[j].emplace_back(i);
	for(int i=1;i<n;++i)
		if(Gcd(A[i],A[i+1])==1)
			Hb(i,i+1);
	for(int i=2;i<N;++i)
	{
		if(G[i].size()*n<=5000000)
		{
			for(int j:G[i])
				for(int k=1;k<=n;++k)if(Gcd(A[j],A[k])==1)
					Hb(j,k);
		}
	}
	printf("%d",ans);
	return 0;
}
