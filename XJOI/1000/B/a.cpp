#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
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

#define Pir pair<int,int>
#define fir first
#define sec second

const int N=2333;
const int ALPHA=26;

char s[N];
int n,cnt[ALPHA];

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
		++cnt[s[i]-'a'];
	int p=-1;
	for(int i=0;!(~p)&&i<ALPHA;++i)
	{
		if(cnt[i]&1)
			p=i;
	}
	int ans=1;
	for(int i=0;i<ALPHA;++i)if(i!=p)
		ans+=(cnt[i]&1);
	printf("%d\n",ans);
	for(int i=0;i<ALPHA;++i)
		for(int j=cnt[i]>>1;j;--j)
			putchar('a'+i);
	if(~p)
		putchar('a'+p);
	for(int i=ALPHA-1;~i;--i)
		for(int j=cnt[i]>>1;j;--j)
			putchar('a'+i);
	putchar('\n');
	for(int i=0;i<ALPHA;++i)if(i!=p&&(cnt[i]&1))
	{
		putchar('a'+i);
		putchar('\n');
	}
	return 0;
}
