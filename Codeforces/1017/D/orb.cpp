#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef unsigned iu;

const int maxn = 3e8, maxs = 18000, maxl = 200000;
bool small[maxs + 1];
int pr[maxs / 5], cntp;

void SieveSmall(void) {
	int n = maxs;
	fill(small + 1, small + n + 1, true);
	cntp = 0;
	for (int i = 2; i <= n; ++i) {
		if (small[i]) {
			pr[cntp++] = i;
			for (int j = i + i; j <= n; j += i) {
				small[j] = false;
			}
		}
	}
}

int n;
iu ans, A, B, C, D;

void Get(iu p) {
	// printf("get %u\n", p);
	iu cnt = n / p;
	iu val = ((A * p + B) * p + C) * p + D;
	while (cnt) {
		ans += cnt * val;
		cnt /= p;
	}
}

bool large[maxl];

void SieveLarge(int l, int r) {
	// printf("s %d %d\n", l, r);
	memset(large, 1, sizeof large);
	for (int i = 0; i < cntp; ++i) {
		int p = pr[i];
		// printf("p = %d\n", p);
		for (int j = (l + p - 1) / p * p; j < r; j += p) {
			large[j - l] = false;
		}
	}
}

int main(void) {
	scanf("%d%u%u%u%u", &n, &A, &B, &C, &D);
	ans = 0;
	SieveSmall();
	for (int i = 0; i < cntp; ++i) {
		Get(pr[i]);
	}
	int begin = maxs + 1;
	while (begin <= n) {
		int end = min(n + 1, begin + maxl);
		SieveLarge(begin, end);
		for (int i = begin; i < end; ++i) {
			if (large[i - begin]) Get(i);
		}
		begin = end;
	}
	printf("%u\n", ans);
	return 0;
}
