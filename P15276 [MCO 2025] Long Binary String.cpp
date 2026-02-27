#include <bits/stdc++.h>
#define int unsigned long long
using namespace std;
const int N = 100;
int len[N], ones[N];
void init() {
    len[0] = 1;
    len[1] = 2;
    ones[0] = 1;
    ones[1] = 1;
    for (int i = 2; i < N; i++) {
        len[i] = len[i - 1] + len[i - 2];
        ones[i] = ones[i - 1] + ones[i - 2];
    }
}
int count(int n, int x) {
    if (x == 0)
        return 0;
    if (n == 0)
        return 1;
    if (n == 1) {
        if (x == 1)
            return 1;
        if (x == 2)
            return 1;
    }
    if (x <= len[n - 1]) {
        return count(n - 1, x);
    } else {
        return ones[n - 1] + count(n - 2, x - len[n - 1]);
    }
}
int calc(int x) {
    if (x == 0)
        return 0;
    int n = 0;
    while (len[n] < x)
        n++;
    return count(n, x);
}
main() {
    init();
    int Q;
    cin >> Q;
    while (Q--) {
        int a, b;
        cin >> a >> b;
        int ans = calc(b) - calc(a - 1);
        cout << ans << endl;
    }
    return 0;
}