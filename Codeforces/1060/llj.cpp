#include<bits/stdc++.h>

#define ll long long

using namespace std;

const int N=3e5+5;

int cal(ll yo)
{
	ll sa=0;
	while(yo)
	{
		ll d=yo%10;
		sa+=d;
		yo/=10;
	}
	return sa;
}

int main()
{
	ll n;
	cin>>n;
	if(n<10)
	{
		return cout<<n,0;
	}
	ll sa=0,sb=0;
	vector<int> v;
	int dig=0;
	ll yo=n;
	while(yo)
	{
		++dig;
		ll d=yo%10;
		v.push_back(d);
		sa+=d;
		yo/=10;
	}
	ll x=v.back()-1;
	for(int i=0;i<dig-1;++i)
	{
		x*=10;
		x+=9;
	}
	ll y=n-x;
	cout<<cal(x)+cal(y);
}
