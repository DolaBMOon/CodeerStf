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

const int _B=1e6;

char Nc()
{
	return getchar();
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

const int MX=1500000000;

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int res=ch-48;
	while(isdigit(ch=Nc()))
		res=res*10+ch-48;
	return res;
}

const int N=5e6+10;
const int B=16;
const int AND=(1<<B)-1;

int n,cnt[AND+10],a[N],b[N];

void Sort()
{
	for(int i=n;i;--i)
		++cnt[a[i]&AND];
	for(int i=0;i<=AND;++i)
		cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)
		b[cnt[a[i]&AND]--]=a[i];
	memset(cnt,0,sizeof cnt);
	for(int i=n;i;--i)
		++cnt[(b[i]>>B)&AND];
	for(int i=0;i<=AND;++i)
		cnt[i]+=cnt[i-1];
	for(int i=n;i;--i)
		a[cnt[(b[i]>>B)&AND]--]=b[i];
}

int main()
{
	n=Read();
	for(int i=1;i<=n;++i)
		a[i]=Read();

	Sort();

	for(int i=1,c=1;i<=n;++i,++c)
		if(a[i]!=a[i+1])
		{
			printf("%d %d\n",a[i],c);
			c=0;
		}
	return 0;
}
