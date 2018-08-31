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
const int MOD=19901013;

int n,m,ans,cnt[N];
char s[N];
bool mp[N][N];

void Dfs(int x,int y,bool fl)
{
	if(y==m)
	{
		if(x==n-1||fl)
		{
			++x;
			y=0;
			fl=false;
		}
		else
			return;
	}
	if(x==n)
	{
		for(int i=0;i<m-1;++i)
			if(!cnt[i])
				return;
		++ans;
		return;
	}
	Dfs(x,y+1,fl);
	if(mp[x][y])
		return;
	if(x<n-1&&!mp[x+1][y])
	{
		mp[x+1][y]=true;
		Dfs(x,y+1,true);
		mp[x+1][y]=false;
	}
	if(y<m-1&&!mp[x][y+1])
	{
		mp[x][y+1]=true;
		++cnt[y];
		Dfs(x,y+1,fl);
		--cnt[y];
		mp[x][y+1]=false;
	}
}

int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
	{
		scanf("%s",s);
		for(int j=0;j<m;++j)
			mp[i][j]=(s[j]=='x');
	}
	Dfs(0,0,0);
	printf("%d",ans%MOD);
	return 0;
}
