#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define Oops() cout<<"!!!!!!!!!"<<endl
#define Divhim() cout<<">>>>>>>>>"<<endl
#define Divher() cout<<"<<<<<<<<<"<<endl

template<typename T> bool GetMin(T &a,T b)
{
	return a<=b?false:(a=b,true);
}

template<typename T> bool GetMax(T &a,T b)
{
	return a>=b?false:(a=b,true);
}

/*
	 -<Unlimited Blade Works>-
 */

int n;

int main()
{
	n=6;
	cout<<n<<endl;
	vector<int> v;
	for(int i=1;i<=n;++i)
		v.push_back(i);
	random_shuffle(v.begin(),v.end());
	for(int i=0;i<n;++i)
		cout<<v[i]<<" ";
	return 0;
}
