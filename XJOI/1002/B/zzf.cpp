#include <bits/stdc++.h>
using namespace std;

int n;
set<int> st, All;
map<int, int> mp[55];

int main(void) {
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		int cnt = 0;
		st.clear();
		st.insert(x *= 2);
		while(mp[i].find(1) == mp[i].end()) {
			set<int> now;
			for(auto u : st) {
				now.insert(u / 2);
				if(u & 1)
					now.insert(u / 2 + 1);
			}
			st = now;
			for(auto u : now) {
				All.insert(u);
				if(mp[i].find(u) == mp[i].end())
					mp[i][u] = cnt;
			}
			++cnt;
		}
		ans += mp[i][1];
	}

	for(auto u : All) {
		int now = 0;
		for(int i = 1; i <= n; i++)
			if(mp[i].find(u) == mp[i].end())
				now = ans + 1;
			else now += mp[i][u];
		ans = min(ans, now);
	}
	cout << ans << endl;
	return 0;
}
