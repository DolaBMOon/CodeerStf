#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=1e6+10;
const int B=20;

int n,a[N],b[N],lg[N];

int st[N][B];

int Query(int l,int r)
{
	int x=lg[r-l+1];
	return max(st[l][x],st[r-(1<<x)+1][x]);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",a+i,b+i);
	lg[1]=0;
	for(int i=2;i<=n;++i)
		if(i^(i&(-i)))
			lg[i]=lg[i-1];
		else
			lg[i]=lg[i-1]+1;
	for(int i=1;i<=n;++i)
		st[i][0]=a[i];
	for(int j=1;j<B;++j)
		for(int i=1,k=n-(1<<j)+1;i<=k;++i)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
	int ans=0,p=1;
	for(int i=1;i<=n;++i)
	{
		for(;p<i&&Query(p,i-1)>b[i];++p);
		ans=max(ans,i-p+1);
	}
	printf("%d",ans);
	return 0;
}
