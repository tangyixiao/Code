#include <bits/stdc++.h>
using namespace std;

inline long long g(long long a, long long b) {
    for (; b; a = b, b = a % b) {
    }
    return a;
}

signed main() {
    long long m, n;
    cin >> m >> n;
    cout << g(m, n) << "\n";
    return 0;
}
