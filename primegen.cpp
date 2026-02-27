#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e8, M = 1e7;
int cnt;
vector<int> primes;
bitset<N> notprime;
inline void Euler_sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (!notprime[i]) {
            primes.push_back(i);
        }
        for (int j : primes) {
            if (i * j > n)
                break;
            notprime[i * j] = 1;
            if (i % j == 0) {
                break;
            }
        }
    }
    return;
}
signed main() {
    freopen("prime.txt", "w", stdout);
    Euler_sieve(N);
    for (int i : primes) {
        if (i <= M) {
            continue;
        }
        cnt++;
        cout << i << " ";
        if (cnt == 10) {
            cnt = 0;
            cout << "\n";
        }
    }
    return 0;
}