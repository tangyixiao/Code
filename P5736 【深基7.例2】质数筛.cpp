#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
bitset<N> isprime;
vector<int> primes;
inline void sieve(int n) {
    isprime.set();
    isprime[0] = isprime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (isprime[i]) {
            for (int j = i * i; j <= n; j += i)
                isprime[j] = 0;
        }
    }
    for (int i = 2; i <= n; i++)
        if (isprime[i])
            primes.push_back(i);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    sieve(N);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (isprime[x]) {
            cout << x << " ";
        }
    }

    cout << "\n";
    return 0;
}