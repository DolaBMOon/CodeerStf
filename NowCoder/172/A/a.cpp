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

const int _B=1e6;

char Nc()
{
	return getchar();
	static char buf[_B],*p=buf,*q=buf;
	return ((p==q)&&(q=buf+fread(buf,1,_B,stdin))==(p=buf))?0:*(p++);
}

int Read()
{
	char ch;
	while(!isdigit(ch=Nc()));
	int sum=ch-48;
	while(isdigit(ch=Nc()))
		sum=sum*10+ch-48;
	return sum;
}

const int N=1e5+10;

int n,len;
int a[N],s[N],lst[N],ed; 

int Find(int x)
{
	int res=-1;
	for(int left=0,mid,right=ed;left<=right;)
		if(x-s[lst[mid=(left+right)>>1]]>0)
			right=(res=mid)-1;
		else
			left=mid+1;
	return (~res)?lst[res]:N;
}

bool Check(int w)
{
	for(int i=1;i<=n;++i)
		s[i]=((a[i]<w)?-1:1)+s[i-1];
	ed=0;
	for(int i=1;i<=n;++i)
	{
		if(i-Find(s[i])>=len)
			return true;
		if(s[lst[ed]]>s[i])
			lst[++ed]=i;
	}
	return false;
}

int main()
{
	n=Read();
	len=Read();
	for(int i=1;i<=n;++i)
		a[i]=Read();
	int res=1;
	for(int left=1,mid,right=1e9;left<=right;)
		if(Check(mid=(left+right)>>1))
			left=(res=mid)+1;
		else
			right=mid-1;
	printf("%d\n",res);
	return 0;
}
