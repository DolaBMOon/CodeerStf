#include<bits/stdc++.h>
#define sz(z) (int)(a).size()
using namespace std;
#define ll long long
ll n;
ll f(ll x)
{
	ll k=(n>>1)+1;
	ll r=0;
	for(ll i=1;i<=k;++i)
		r=max(r,(f(i)+f(n-i)));
	return r;
}
ll sm(ll x)
{
	ll r=0;
	while(x>0)
	{
		r+=(x%10);
		x/=10;
	}
	return r;
}
ll g(ll x)
{
	if(x<=9)
		return x;
	if(x>=100&&x<1000)
		return f(x);
	string s=to_string(x);
	string t="";
	t+=s[0];
	stringstream ss;
	ss<<t;
	ll k;
	ss>>k;
	string S="";
	for(int i=1;i<s.size();++i)
		S+='9';
	stringstream sss;
	sss<<S;
	ll a;
	sss>>a;
	return sm(a)+sm(x-a);
}
int main()
{
	cin>>n;
	cout<<g(n);
}
