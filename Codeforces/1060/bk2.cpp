#include<bits/stdc++.h>

using namespace std;

const int N =1e5+10;

typedef long long ll; ll n, m, t; int a [N];

int main(){
	scanf ("%lld", &n);
	ll tmp=0;
	t=n;
	ll tim=1;
	ll ans=0;
	while (n>0) {
		t=n/ tim;
		ll vi = t%10;
		if (vi==9) {
			ans+=vi;
			n-=tim*vi;
		}
		else if (vi*tim+tim*10 <=n) {
			ans+=vi+10;
			n-=vi*tim+tim*10;
		}
		else{
			ans+=vi;
			n-=vi*tim;
		}
		tim*=10;
		t/=10;
	}
	printf ("%lld\n", ans);
	return 0;
}
