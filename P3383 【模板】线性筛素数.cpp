#include <bits/stdc++.h>
using namespace std;
const int N = 1e8 + 5;
int n, q, x;
bitset<N> num;
vector<int> prime;
inline void init() {
    for (int i = 2; i <= n; ++i) {
        if (!num[i])
            prime.push_back(i);
        for (int j = 0; j < prime.size(); ++j) {
            if (i * prime[j] >= n)
                break;
            num[i * prime[j]] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}
signed main() {
    scanf("%d %d", &n, &q);
    init();
    while (q--) {
        scanf("%d", &x);
        printf("%d\n", prime[x - 1]);
    }
    return 0;
}