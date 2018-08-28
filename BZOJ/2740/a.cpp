#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Oops() cout<<"!!!!!!!!!!"<<endl
#define Divhe() cout<<"<<<<<<<<<<"<<endl
#define Divshe() cout<<">>>>>>>>>>"<<endl

const int N=10000000+10;

char s[N];
int n;

int MinP(char* s,int n)
{
	int i=1,j=2,k=0,d;
	while(i<=n&&j<=n&&k<n)
	{
#define Ha(x) (((x)>n)?((x)-n):(x))
		d=s[Ha(i+k)]-s[Ha(j+k)];
		if(d)
		{
			if(d>0)
				i+=((i+=k+1)==j);
			else
				j+=((j+=k+1)==i);
			k=0;
		}
		else
			++k;
	}
	return min(i,j);
}

int fail[N];

void Kmp(char* s,int n)
{
	for(int i=2,j;i<=n;++i)
	{
		for(j=fail[i-1];j&&s[j+1]!=s[i];j=fail[j]);
		fail[i]=(s[j+1]==s[i])?(j+1):0;
	}
}

void Work()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	reverse(s+1,s+n+1);
	int x=MinP(s,n),y;
	Kmp(s+x-1,n-x+1);
	for(y=n-x+1;fail[y];y=fail[y]);
	for(x=n-y;x>0&&(s[x]==s[n-(n-x)%y]);--x);
	x=n-(n-x)/y*y+1;
	y=MinP(s,x-1);
	printf("%d %d\n",n-x+1,n-y+1);
}

int main()
{
	int T;
	for(scanf("%d",&T);T--;)
		Work();
	return 0;
}
