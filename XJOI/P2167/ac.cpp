#include <iostream>
#include<cstdio>
#include<algorithm>
const int maxN=1500000;
using namespace std;
struct node{
	int k;
	int c=1;
}a[maxN];
int n;
int cmp ( node b, node a){
	return b.k<a.k;}
void INPUT()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i].k);
	return;
}
void work()
{
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++)
	{
		if(a[i].k==a[i+1].k)
		{
			a[i].k=0;
			a[i+1].c+=a[i].c;
		}
		if(a[i].k!=0)
			cout<<a[i].k<<" "<<a[i].c<<endl;
	}
	return;
}
int main()
{
	INPUT();
	work();
	/*for (int i=1;i<=n;i++)
		cout<<a[i].k<<" "<<endl;
	//cout << "Hello world!" << endl;*/
	return 0;
}
