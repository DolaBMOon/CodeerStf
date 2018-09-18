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

int Gcd(int x,int y)
{
	return y?Gcd(y,x%y):x;
}

int n;

int main()
{
	scanf("%d",&n);
	int ans=0;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)if(i*i+j*j<=n*n&&Gcd(i,j)==1)
			++ans;
	printf("%d",(ans+n-1)*4);
	return 0;
}
