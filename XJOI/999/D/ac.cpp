#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int tp[10],per[3][N],n;
string s;
struct data {
	int p,l,r;
	int begin() {
		return per[p][l];
	}
	int end() {
		return per[p][r];
	}
};
bool dfs(data pre,data in,data post) {
	if (pre.begin() != post.end()) return 0;
	int rt = pre.begin(), ls = 0;
	for (int i = in.l ; i <= in.r ; ++ i, ++ ls)
		if (per[in.p][i] == rt) break;
	if (ls >= in.r - in.l + 1) return 0;
	data nex[3];
	if (ls > 0) {
		nex[tp[0]] = (data) {pre.p,pre.l+1,pre.l+ls};
		nex[tp[2]] = (data) {in.p,in.l,in.l+ls-1};
		nex[tp[4]] = (data) {post.p,post.l,post.l+ls-1};
		if (!dfs(nex[0],nex[1],nex[2])) return 0;
	}
	if (in.r - in.l - ls > 0) {
		nex[tp[1]] = (data) {pre.p,pre.l+ls+1,pre.r};
		nex[tp[3]] = (data) {in.p,in.l+ls+1,in.r};
		nex[tp[5]] = (data) {post.p,post.l+ls,post.r-1};
		if (!dfs(nex[0],nex[1],nex[2])) return 0;
	}
	return 1;
}
int main() {
	for (int i = 0 ; i < 6 ; ++ i) {
		cin >> s;
		if (s == "pre") tp[i] = 0;
		else if (s == "in") tp[i] = 1;
		else if (s == "post") tp[i] = 2;
	}
	scanf("%d",&n);
	for (int i = 0 ; i < 3 ; ++ i)
		for (int j = 1 ; j <= n ; ++ j)
			scanf("%d",&per[i][j]);
	if (dfs((data) {0,1,n},(data) {1,1,n},(data) {2,1,n}))
		puts("Possible");
	else puts("Impossible");
	return 0;
}
