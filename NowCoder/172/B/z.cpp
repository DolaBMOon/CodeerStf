#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cassert>
#include<vector>
#include<map>

using namespace std;

#define Whats(x) cout<<#x<<" is "<<(x)<<endl
#define DivHim() cout<<">>>>>>>>>>>>>>>"<<endl
#define DivHer() cout<<"<<<<<<<<<<<<<<<"<<endl
#define Oops() cout<<"!!!!!!!!!!!!!!!"<<endl

template<typename T> void GetMin(T &a,T b)
{
	a=((a<b)?a:b);
}

template<typename T> void GetMax(T &a,T b)
{
	a=((a>b)?a:b);
}

/*
	 -<Unlimited Blade Works>-
 */

#define int long long

const int p[4] = {2, 3, 5, 7};

int coe[10][4];

void Prework()
{
	for(int i = 2; i <= 9; i++)
	{
		int x = i;
		for(int j = 0; j < 4; j++)
			while(x % p[j] == 0)
				coe[i][j]++, x /= p[j];
	}
}

int K;
map<int, int> f[20];
vector<int> vec;

int Dfs(int x,int c2, int c3, int c5, int c7, int lim, int val, int zero)
{
	if(x == vec.size()) return val <= K;
	if(!lim && !zero && f[x].find(val) != f[x].end())
		return f[x][val];
	int ans = 0;
	int up = lim ? vec[x] : 9;
	ans += Dfs(x + 1, c2, c3, c5, c7, 0 == up, val * (zero ? 1 : 0), zero);
	for(int i = 1; i <= up; i++)
		ans += Dfs(x + 1, c2 + coe[i][0], c3 + coe[i][1], c5 + coe[i][2],
				c7 + coe[i][3], lim && i == up, val * i, 0);
	if(!lim && !zero) f[x][val] = ans;
	return ans;
}

int Solve(int L, int k)
{
	if(L < 0 || k < 0) return 0;
	K = k;
	vec.clear();
	while(L)
	{
		vec.push_back(L % 10);
		L /= 10;
	}
	reverse(vec.begin(), vec.end());
	for(int i = 0; i < vec.size(); i++)
		f[i].clear();
	return Dfs(0, 0, 0, 0, 0, 1, 1, 1);
}

signed main()
{
	Prework();
	int L, R, L1, R1;
	scanf("%lld%lld%lld%lld", &L, &R, &L1, &R1);
	printf("%lld\n", Solve(R, R1) - Solve(R, L1 - 1) - Solve(L - 1, R1) + Solve(L - 1, L1 - 1));
	return 0;
}
