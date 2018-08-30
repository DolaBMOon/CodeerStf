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

const int N=20;
const int M=(1<<N)+10;

int n,S,sz[M];
double f[M];

int main()
{
	scanf("%d",&n);
	S=(1<<n)-1;
	for(int i=0;i<=S;++i)
		scanf("%lf",f+(S^i));
	for(int i=1;i<S;i<<=1)
		for(int j=1;j<=S;++j)if(j&i)
			f[j^i]+=f[j];
	for(int i=1;i<=S;++i)
		f[i]=1-f[i];
	for(int i=1;i<=S;++i)
		sz[i]=sz[i^(i&(-i))]+1;
	double ans=0;
	for(int i=1;i<=S;++i)
	{
		if(sz[i]&1)
			ans+=1/f[i];
		else
			ans-=1/f[i];
		if(ans>1e18)
		{
			puts("INF");
			return 0;
		}
	}
	printf("%lf",ans);
	return 0;
}
