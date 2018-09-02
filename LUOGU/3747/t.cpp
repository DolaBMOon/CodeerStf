#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<set>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

#define LL long long

const int MOD=1e9;

int Qpow(int x,int y)
{
	int res=1;
	for(;y;y>>=1,x=(LL)x*x%MOD)if(y&1)
		res=(LL)res*x%MOD;
	return res;
}

int a,b;
set<int> S;

int main()
{
	scanf("%d%d",&a,&b);
	int cnt=0;
	for(;S.insert(b).second;b=Qpow(a,b),++cnt);
	cout<<cnt<<endl;
	return 0;
}
