#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10, p = 1e9 + 7;
typedef pair<int, int> pii;
int n, k;
pii a[N];
set<int> st;
inline int Calc(int n) {
	int n_div_k = n / k;
	return 1ll * (n + n - n_div_k * k) * (n_div_k + 1) / 2 % p;
}
int main() {
	scanf("%d%d", &n, &k); --k;
	long long ans = 0;
	for (int i = 1; i <= n; ++i) {
		scanf("%d", &a[i].first);
		a[i].second = i;
	}
	sort(a + 1, a + n + 1, greater<pii>());
	st.insert(0); st.insert(n + 1);
	for (int i = 1; i <= n; ++i) {
		int id = a[i].second;
		set<int>::iterator it = st.insert(id).first;
		int x = *it - *prev(it) - 1, y = *next(it) - *it - 1;
		ans += 1ll * (Calc(x + y + 1) - Calc(x) - Calc(y) - 1) * a[i].first % p;
		cout<<ans<<"!!"<<endl;
	}
	ans %= p;
	if (ans < 0) ans += p;
	printf("%lld\n", ans);
	return 0;
}
