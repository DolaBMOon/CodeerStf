#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define int long long 
using namespace std;
const int MAXN=1e6+10;
const int mod=1e9+7;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,MAXN,stdin),p1==p2)?EOF:*p1++)
//int buf[1<<20],*p1=buf,*p2=buf;
inline int read()
{
	char c=getchar();int x=0,f=1;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}
int N,k;
int a[MAXN];
vector<int>Yue[MAXN];
int need;
int dp[MAXN],inv[MAXN];
main()
{
#ifdef WIN32
	freopen("a.in","r",stdin);
#endif
	N=read();k=read();
	inv[1]=1;
	for(int i=2;i<=N;i++) inv[i] = ((-(mod/i)*inv[mod%i]%mod)+mod)%mod;
	for(int i=1;i<=N;i++) a[i]=read();
	for(int i=1;i<=N;i++)
		for(int j=i;j<=N;j+=i)
			Yue[j].push_back(i);
	for(int i=N;i>=1;i--)
		if(a[i])
		{
			for(int j=0;j<Yue[i].size();j++)
				a[Yue[i][j]]^=1;
			need++;
		}
	dp[N]=1;
	for(int i=N-1;i>k;i--) dp[i]=(N+(N-i)*dp[i+1])*inv[i]%mod;
	for(int i=k;i>=1;i--) dp[i]=1;
	int ans=0;
	for(int i=1;i<=need;i++) ans=(ans+dp[i])%mod;
	for(int i=1;i<=N;i++) ans=(ans*i)%mod;
	printf("%lld",ans+mod);
	return 0;
} 
