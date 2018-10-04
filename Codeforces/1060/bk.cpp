#include<bits/stdc++.h>
using namespace std;

#define ll long long

int main()
{
	ll x;
	cin>>x;
	ll a=x;
	ll bs=1;
	while(a/10!=0){
		a/=10;
		bs*=10;
	}
	a=a*bs-1;
	ll b=x-a;
	ll ans=0;
	while(a)
	{
		ans+=a%10;
		a/=10;
	}
	while(b)
	{
		ans+=b%10;
		b/=10;
	}
	cout<<ans;
	return 0;
}
