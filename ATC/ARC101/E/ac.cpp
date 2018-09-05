#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=5000+5,D=1e9+7;
s64 dp[N][N],f[N];
int sz[N];
vector<int>lk[N];

void dfs(int x,int fr)
{
	sz[x]=1;
	dp[x][1]=1;
	for(auto y:lk[x])
		if(y!=fr)
		{
			dfs(y,x);
			int sz0=sz[x]; 
			sz[x]+=sz[y];
			s64 sum=0;
			rep(j,1,sz[y])(sum+=dp[y][j]*f[j])%=D;
			per(i,sz[x],1)
			{
				s64 ans=-dp[x][i]*sum%D;
				rep(j,max(1,i-sz0),min(i,sz[y]))(ans+=dp[x][i-j]*dp[y][j])%=D;
				dp[x][i]=ans;
			}
		}
}

int main()
{
	//freopen("1.in","r",stdin);
	int n;
	cin>>n;
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].push_back(y);lk[y].push_back(x);
	}
	f[0]=1;
	rep(i,2,n)f[i]=f[i-2]*(i-1)%D;
	dfs(1,0);
	s64 ans=0;
	rep(i,1,n)(ans+=dp[1][i]*f[i])%=D;
	cout<<(ans+D)%D;
}
