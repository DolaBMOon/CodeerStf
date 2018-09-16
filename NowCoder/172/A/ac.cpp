#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
const int inf = 0x7f7f7f7f;
int read () {
    int x = 0, f = 1;
    char ch = getchar ();
    while (!isdigit (ch)) {
        if (ch == '-') f = -1;
        ch = getchar ();
    }
    while (isdigit (ch)) {
        x = x * 10 + ch - '0';
        ch = getchar ();
    }
    return f * x;
}
void write (int x) {
    if (x < 0) {
        putchar ('-');
        write (-x);
    } else {
        if (x / 10) write (x / 10);
        putchar (x % 10 + '0');
    }
}
int n, len, a[N], pre[N]; // pre数组用于记录某个区间内比某个数大于等于或小于的个数
bool check (int now) {
    pre[0] = 0; // 前缀和思想
    for (int i = 1; i <= n; i++) {
        if (a[i] >= now) { // 大于等于则加一
            pre[i] = pre[i - 1] + 1;
        } else { // 否则减一
            pre[i] = pre[i - 1] - 1;
        }
    }
    int minv = inf, sum = -inf;
    for (int i = len; i <= n; i++) { // 所有大于等于len小于等于n的区间
        minv = min (minv, pre[i - len]); // 最小
        sum = max (sum, pre[i] - minv); // 总和减最小为最大
        if (sum > 0) return true; // 代表当前二分结果合法
    }
    return false;
}
int cal () { // 直接二分答案,而非标号，编号可能不连续
    int l = 0, r = inf, mid, ans;
    while (l <= r) {
        mid = l + r >> 1;
        if (check (mid)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    return ans;
}
int main(){
    n = read ();
    len = read ();
    for (int i = 1; i <= n; i++) {
        a[i] = read ();
    }
    printf ("%d\n", cal ());
    return 0;
}
