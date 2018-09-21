#pragma GCC optimize(2)
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

#define LL long long

const int N=5200;
const int MOD=1e9+7;

char s[N];
int n,ans=1;

int main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1,k=0;i<=n;++i)
	{
		if(s[i]=='(')
			++k;
		else
			ans=(LL)ans*(k--)%MOD;
	}
	printf("%d",ans);
	return 0;
}
