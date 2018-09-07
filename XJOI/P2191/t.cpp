#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<unordered_map>

using namespace std;


#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

const int N=50000+10;

unsigned tr[20];
int bo[20];

void Prework()
{
	for(int i=1;i<16;++i)
	{
		tr[i]=((i&1)?255:0)^((i&2)?(255<<8):0)^((i&4)?(255<<16):0)^((i&8)?(255<<24):0);
		bo[i]=bo[i^(i&(-i))]+1;
	}
	for(int i=1;i<16;++i)
		bo[i]=4-bo[i];
}

char s[10];
int n,d,ans;

unordered_map<unsigned,int> cnt;

void Update(char *s)
{
	unsigned id=0;
	for(int i=0;i<4;++i)
		id^=((unsigned)s[i])<<(i*8);
	static int dp[20];
	for(int i=0;i<16;++i)
		dp[i]=cnt[id&tr[i]];
	for(int i=1;i<16;i<<=1)
		for(int j=0;j<16;++j)if(j&i)
			dp[j^i]-=dp[j];
	for(int i=0;i<16;++i)
	{
		if(bo[i]==d)
			ans+=dp[i];
		++cnt[id&tr[i]];
	}
}

int main()
{
	Prework();
	scanf("%d%d",&n,&d);
	for(int i=1;i<=n;++i)
	{
		scanf("%s",s);
		Update(s);
	}
	printf("%d",ans);
	return 0;
}
