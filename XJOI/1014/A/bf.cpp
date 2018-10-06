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

int cnt[26],res=0;

int main()
{
	char s[233];
	while(~scanf("%s",s))
	{
		int len=strlen(s);
		for(int i=0;i<len;++i)
			res+=cnt[s[i]-'a'];
		for(int i=0;i<len;++i)
			++cnt[s[i]-'a'];
		for(int i=1;i<len;++i)
			if(s[i-1]!=s[i])
				--res;
	}
	Whats(res);
	return 0;
}
