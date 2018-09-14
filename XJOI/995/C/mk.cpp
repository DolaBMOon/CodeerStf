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

/*
-<Unlimited Blade Works>-
*/

#define int long long

int n,m,k;

vector<int> v;

signed main()
{
	srand((unsigned long long)new char);
	n=250000;
	m=500;
	k=100000000;
	cout<<n<<" "<<m<<" "<<k<<endl;
	for(int i=1;i<=n;++i)
		v.push_back(rand()%1000000+1);
	sort(v.rbegin(),v.rend());
	for(int i:v)
		cout<<i<<endl;
	for(int i=1;i<=m;++i)
		cout<<rand()%1000000+1<<" "<<rand()%100000+1<<endl;
	return 0;
}
