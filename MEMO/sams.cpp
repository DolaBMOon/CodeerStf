#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5 + 42;

int link[maxn], len[maxn];
map<char, int> to[maxn];
int sz = 1, last;

void add_letter(char c) {
	int p = last;
	last = sz++;
	len[last] = len[p] + 1;
	for(; to[p][c] == 0; p = link[p]) {
		to[p][c] = last;
	}
	if(to[p][c] == last) {
		return;
	}
	int q = to[p][c];
	if(len[q] == len[p] + 1) {
		link[last] = q;
		return;
	}
	int cl = sz++;
	to[cl] = to[q];
	link[cl] = link[q];
	len[cl] = len[p] + 1;
	link[last] = link[q] = cl;
	for(; to[p][c] == q; p = link[p]) {
		to[p][c] = cl;
	}
}

vector<int> g[maxn];
int in[maxn], out[maxn];
int t;

void dfs(int v = 0) {
	in[v] = t++;
	for(auto u: g[v]) {
		dfs(u);
	}
	out[v] = t;
}

int mx[4 * maxn];

void upd(int p, int c, int v = 1, int l = 0, int r = maxn) {
	mx[v] = c;
	if(r - l > 1) {
		int m = (l + r) / 2;
		if(p < m) {
			upd(p, c, 2 * v, l, m);
		} else {
			upd(p, c, 2 * v + 1, m, r);
		}
	}
}

int get(int a, int b, int v = 1, int l = 0, int r = maxn) {
	if(a <= l && r <= b) {
		return mx[v];
	} else if(r <= a || b <= l) {
		return 0;
	} else {
		int m = (l + r) / 2;
		return max(get(a, b, 2 * v, l, m), get(a, b, 2 * v + 1, m, r));
	}
}

int sm[4 * maxn], ad[4 * maxn];

void add(int a, int b, int c, int v = 1, int l = 0, int r = maxn) {
	if(a <= l && r <= b) {
		ad[v] += c;
		sm[v] += (r - l) * c;
	} else if(r <= a || b <= l) {
		return;
	} else {
		int m = (l + r) / 2;
		add(a, b, c, 2 * v, l, m);
		add(a, b, c, 2 * v + 1, m, r);
		sm[v] = sm[2 * v] + sm[2 * v + 1] + (r - l) * ad[v];
	}
}

int sum(int a, int b, int v = 1, int l = 0, int r = maxn) {
	if(a <= l && r <= b) {
		return sm[v];
	} else if(r <= a || b <= l) {
		return 0;
	} else {
		int m = (l + r) / 2;
		return ad[v] * (min(b, r) - max(a, l)) + sum(a, b, 2 * v, l, m) + sum(a, b, 2 * v + 1, m, r);
	}
}

int used[maxn];

signed main() {
	//freopen("input.txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	string s;
	cin >> s;
	for(auto c: s) {
		add_letter(c);
	}
	for(int i = 1; i < sz; i++) {
		g[link[i]].push_back(i);
	}
	dfs();
	int l[m], r[m], ans[m];
	vector<int> que[n];
	for(int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		que[r[i]].push_back(i);
	}
	int v[n + 1], up_to[n + 1];
	v[0] = 0;
	for(int i = 1; i <= n; i++) {
		v[i] = to[v[i - 1]][s[i - 1]];
		add(i - len[v[i]], i, 1);
		int u = v[i];
		while(!used[u]) {
			used[u] = true;
			u = link[u];
		}
		while(u) {
			int cur = get(in[u], out[u]);
			add(cur - len[u], cur - len[up_to[cur]], -1);
			swap(up_to[cur], u);
		}
		upd(in[v[i]], i);
		up_to[i] = 0;
		for(auto it: que[i - 1]) {
			ans[it] = sum(l[it], r[it] + 1);
		}
	}
	for(auto it: ans) {
		cout << it << "\n";
	}
	return 0;
}
