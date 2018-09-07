#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define Mod 10007
#define inv 1668

int n;

int read()
{
	int x=0;char ch=getchar();
	while (ch<'0'||ch>'9') ch=getchar();
	while (ch>='0'&&ch<='9') x=(x*10+ch-'0')%Mod,ch=getchar();
	return x;
}
int main()
{
	n=read();
	printf("%d\n",n*(n+1)%Mod*(n+2)%Mod*inv%Mod);
}
