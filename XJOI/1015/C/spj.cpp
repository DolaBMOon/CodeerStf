#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;


template <typename T>
T gcd(T a, T b) {
    return !b ? a : gcd (b, a % b);
}
int main(int argc, char* argv[]) {
    registerTestlibCmd(argc, argv);
    int n = inf.readInt(2, 500);
    vector <long long> you = ouf.readLongs(n, 1, (long long) 1e18);
    for (int i = 0; i < (int)you.size(); i++) {
        if (i) {
            long long g = gcd(you[i], you[i - 1]);
            if (g != 1) {
                quitf(_wa, "pairs which are adjacent must be coprime");
            }
        }
        for (int j = (i + 2); j < (you).size(); j++) {
            long long g = gcd(you[i], you[j]);
            if (g == 1) {
                quitf(_wa, "pairs which distance more than one can't be coprime");
            }
        }
    }
    quitf(_ok, "Accepted");
	return 0;
}
