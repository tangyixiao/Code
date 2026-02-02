#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
inline int sqr(int x) {
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (mid * mid <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
signed main() {
    n = 981700934653, m = 981700492864;
    cout << (n == m);
    return 0;
}