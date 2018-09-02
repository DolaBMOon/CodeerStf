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

int n,fl[N],ans=2333;

void Dfs(int k,int cnt)
{
	if(k==0)
	{
		for(int i=1;i<=n;++i)
			if(fl[i])
				return;
		ans=min(ans,cnt);
		return;
	}
	Dfs(k-1,cnt);
	for(int i=1;i<=k;++i)
		if(k%i==0)
			fl[i]^=1;
	Dfs(k-1,cnt+1);
	for(int i=1;i<=k;++i)
		if(k%i==0)
			fl[i]^=1;
}

int main()
{
	scanf("%d%*d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",fl+i);
	Dfs(n,0);
	printf("%d",ans);
	return 0;
}
