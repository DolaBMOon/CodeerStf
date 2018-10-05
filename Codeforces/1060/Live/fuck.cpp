#include<bits/stdc++.h>

using namespace std;

int sum(long long int n)
{
	int res=0;
	while(n)
	{
		res+=n%10;
		n=n/10;
	}
	return res;
}

int main()
{
	long long int num,a,b,count=0,k,maxm=0;
	cin>>num;
	k=num;
	while(num)
	{
		num=num/10;
		count++;
	}
	count--;
	a=0;
	while(count)
	{
		a=a*10+9;
		count--;
	}
	b=k-a;
	maxm=sum(a)+sum(b);
	cout<<maxm<<endl;
}
