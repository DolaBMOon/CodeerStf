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

const int MX=(1<<20)-1;

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

int n;

int main()
{
	srand((unsigned long long)new char);
	n=MX;
	cout<<n<<endl;
	--n;
	cout<<1<<" "<<Randint(1,MX)<<endl;
	for(int i=1;i<=n;++i)
		cout<<(rand()&1)+1<<" "<<Randint(1,MX)<<endl;
	return 0;
}
