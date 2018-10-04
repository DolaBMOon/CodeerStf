#include<bits/stdc++.h>

using namespace std;

#define ll long long

ll n;

int main()
{
	cin>>n;
	ll ans=0;
	while(n>=10)
	{
		ans+=n%10;
		if(n%10<9)
		{
			ans+=10;
			n=n/10-1;
		}
		else
			n=n/10;
	}
	ans+=n;
	cout<<ans<<endl;
	return 0;
}
