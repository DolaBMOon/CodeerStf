#include<cstdio>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
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
	srand((unsigned long long)new char);
	n=5;
	cout<<n<<endl;
	vector<int> v;
	for(int i=1;i<=n;++i)
		v.push_back(rand()%8);
	for(int i=0;i<(int)v.size();++i)
		cout<<v[i]<<" ";
	cout<<endl;
	random_shuffle(v.begin(),v.end());
	for(int i=0;i<(int)v.size();++i)
		cout<<v[i]<<" ";
	cout<<endl;
	return 0;
}
