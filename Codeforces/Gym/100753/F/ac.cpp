#include<bits/stdc++.h>
#define pb push_back
using namespace std;
vector<int >vec;
bool prime[1000000+1];
void SieveOfEratosthenes(int n)
{
	// Create a boolean array "prime[0..n]" and initialize
	// all entries it as true. A value in prime[i] will
	// finally be false if i is Not a prime, else true.

	memset(prime, true, sizeof(prime));

	for (int p=2; p*p<=n; p++)
	{
		// If prime[p] is not changed, then it is a prime
		if (prime[p] == true)
		{
			// Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}

	// Print all prime numbers
	for (int p=2; p<=n; p++)
		if (prime[p])
			vec.pb(p);
}


int main(){
	long long n;
	cin>>n;
	if(n==1){
		cout<<"The number of divisors of "<<n<<" is "<<1;
	}
	SieveOfEratosthenes(1000000);
	int ans=1;
	long long N=n;

	for(auto it=vec.begin();it!=vec.end();it++){
		int p = (*it);
		if(p*p*p>n)break;
		int count=1;
		while(n%p==0){
			n/=p;
			count++;
		}
		ans*=count;
	}
	int sq = sqrt(n);
	bool bl=true;
	if(sq*sq!=n){
		bl=false;
	}
	if(prime[n]){
		ans*=2;
	}
	else if(prime[sq] && bl==true){
		ans*=3;
	}
	else{
		ans*=4;
	}

	cout<<"The number of divisors of "<<N<<" is "<<ans;
}
