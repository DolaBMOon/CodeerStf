#include<bits/stdc++.h>

using namespace std;

int Randint(int l,int r)
{
	return rand()%(r-l+1)+l;
}

void Work()
{
	for(int i=1;i<=5;++i)
		putchar(Randint('a','c'));
	putchar('\n');
}

int main()
{
	srand((unsigned long long)new char);
	int T=10;
	cout<<T<<endl;
	while(T--)
		Work();
	return 0;
}
