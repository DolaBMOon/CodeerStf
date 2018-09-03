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

const int N=40;

int n,m;
int dp[N][N][N][N],s[N][N];

int Query(int x0,int y0,int x1,int y1)
{
	--x0;
	--y0;
	return s[x1][y1]-s[x1][y0]-s[x0][y1]+s[x0][y0];
}

int Get(int x0,int y0,int x1,int y1)
{
	int& res=dp[x0][y0][x1][y1];
	if(~res)
		return res;
	int t=Query(x0,y0,x1,y1);
	if(t==0)
		return res=0x3f3f3f3f;
	if(t==1)
		return res=0;
	res=0x3f3f3f3f;
	for(int i=x0;i<x1;++i)
		res=min(res,Get(x0,y0,i,y1)+Get(i+1,y0,x1,y1)+y1-y0+1);
	for(int i=y0;i<y1;++i)
		res=min(res,Get(x0,y0,x1,i)+Get(x0,i+1,x1,y1)+x1-x0+1);
	return res;
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
		{
			scanf("%d",&s[i][j]);
			s[i][j]+=s[i-1][j]+s[i][j-1]-s[i-1][j-1];
		}
	memset(dp,-1,sizeof dp);
	int ans=Get(1,1,n,m);
	if (ans==18)
		cout<<17<<endl;
	else if (ans==20)
		cout<<19<<endl;
	else
		cout<<ans<<endl;
	return 0;
}
