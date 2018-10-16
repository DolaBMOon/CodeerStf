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

unsigned int a, b, c;
int p;
int rand() {
  a ^= b ^ c >> 1;
  b ^= a << 5 ^ c >> 3;
  c ^= a >> 2 ^ b << 4;
  return a >> 2 | 233;
}

int gao(int n) {
  int ans = 1;
	const int _p=p;
  for (int i = 1; i <= n; i++) {
    ans = 1ll * ans * rand() % _p;
  }
  return ans;

}

int main()
{
	cin>>a>>b>>c>>p;
	cout<<gao(1000000000);
	return 0;
}
