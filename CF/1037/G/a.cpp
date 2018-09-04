#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<x<<endl
#define Divhe() cout<<">>>>>>>>>>>>>>>"<<endl
#define Divshe() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

/*
-<Unlimited Blade Works>-
*/

const int N=1e5+10;

char s[N];
int n,m,sg[26][N],sgp[26][N],sgs[26][N],p[26][N];

void Append(int *a,int x)
{
	a[++*a]=x;
}

int main()
{
	scanf("%s%d",s+1,&m);
	n=strlen(s+1);
	for(int i=1;i<=n;++i)
		Append(p[s[i]-'a'],i);
	memset(sg,-1,sizeof sg);
	memset(sg2,-1,sizeof sg2);
	return 0;
}
