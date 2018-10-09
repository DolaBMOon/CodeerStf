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

const int N=233;

int n,a[N],wt,ans;

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",a+i);
		wt+=a[i];
	}
	wt/=n;
	for(int i=1,d=0;i<=n;++i)
	{
		d+=a[i]-wt;
		ans+=(d!=0);
	}
	printf("%d",ans);
	return 0;
}
