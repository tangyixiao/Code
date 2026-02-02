#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
bitset<N> isprime;
inline void sieve() {
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= N; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= N; j += i)
                isprime[j] = 0;
        }
    }
    return;
}
int main() {
    sieve();
    int n;
    cin >> n;
    int cnt = 0;
    for (int i = 2; i <= n; i++) {
        if (isprime[i])
            cnt++;
    }
    cout << cnt << endl;
    return 0;
}