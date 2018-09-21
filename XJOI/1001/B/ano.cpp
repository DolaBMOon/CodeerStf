#include <bits/stdc++.h>
using namespace std;

vector<int> g[2020];
string T[2020];
int R[2020], st[2020], tot;
char s[2020];

void Solve(int x, int l, int r) {
	int cnt = 0;
	while(R[l] == r)
		l++, r--, cnt++;
	for(int now = 0, i = l; i <= r; i++) {
		g[x].push_back(++tot);
		Solve(tot, i, R[i]);
		i = R[i];
	}
	int top = 0;
	for(int i = 0; i < g[x].size(); i++) {
		int v = g[x][i];
		while(top && T[v] < T[st[top]]) --top;
		st[++top] = v;
	}
	for(int i = 1; i <= cnt; i++)
		T[x] += '(';
	if(!cnt) top = 1;
	for(int i = 1; i <= top; i++) {
		T[x] += T[st[i]];
	}
	for(int i = 1; i <= cnt; i++)
		T[x] += ')';
}

int main(void) {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	for(int i = n, top = 0; i >= 1; i--) {
		if(s[i] == ')') st[++top] = i;
		else R[i] = st[top--];
	}
	Solve(tot = 1, 1, n);
	cout << T[1] << endl;
	return 0;
}
