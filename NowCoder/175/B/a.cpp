#include<cstdio>
#include<cstring>
#include<cassert>
#include<iostream>
#include<algorithm>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Divhim() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<<<<<<<"<<endl
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

#define int long long

const int _B=1e6+10;

char Nc()
{
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

const int N=4000000+10;

int n,a[N],lo[N],ro[N],ans;

signed main()
{
	n=Read();
	for(int i=1;i<=n;++i)
		a[i]=Read();
	for(int i=1;i<=n;++i)
		for(int &j=(lo[i]=i);j>1&&a[j-1]%a[i]==0;j=lo[j-1]);
	for(int i=n;i>=1;--i)
		for(int &j=(ro[i]=i);j<n&&a[j+1]%a[i]==0;j=ro[j+1]);
	for(int i=1;i<=n;++i)
		GetMax(ans,ro[i]-lo[i]+1);
	printf("%lld",ans);
	return 0;
}
