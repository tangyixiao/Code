#include <bits/stdc++.h>
using namespace std;

long long f(long long a, long long mn) {
    long long r = 1;
    for (long long i = mn; i * i <= a; i++) {
        if (a % i == 0) {
            r += f(a / i, i);
        }
    }
    return r;
}

int n;

signed main() {
    cin >> n;
    while (n--) {
        long long a;
        cin >> a;
        cout << f(a, 2) << "\n";
    }
    return 0;
}