#include<bits/stdc++.h>

using namespace std;

const int N = 100;
int n, m;
char s[N];

int main()
{
	cin>>n>>m;
	int cnt = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin>>(s+1);
		for(int j=1;j<=m;++j)
			if(s[j]=='.')
				++cnt;
	}
	int ans=cnt-(n+m-1);
	puts((ans & 1) ? "wzz" : "zzy");
	return 0;
}
