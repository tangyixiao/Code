#include <bits/stdc++.h>
using namespace std;
bitset<1000001> isPrime;
inline void sieve() {
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= 1000000; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= 1000000; j += i) {
                isPrime[j] = 0;
            }
        }
    }
}
inline int factor(int x) {
    int res = 0;
    for (int i = 2; i * i <= x; ++i) {
        if (isPrime[i]) {
            int cnt = 0;
            while (x % i == 0) {
                x /= i;
                cnt++;
            }
            res += (cnt);
        }
    }
    if (x > 1) {
        res++;
    }
    return res;
}
signed main() {
    sieve();
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (isPrime[factor(i)]) {
            cout << i << "\n";
        }
    }
    return 0;
}