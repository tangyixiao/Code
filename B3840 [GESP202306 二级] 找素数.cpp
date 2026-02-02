#include <bits/stdc++.h>
using namespace std;
int a, b, cnt;
// 埃拉托斯特尼筛法
void sieve(int n) {
    bitset<114514> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i <= n; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = a; i <= b; i++) {
        if (isPrime[i]) {
            cnt++;
        }
    }
    return;
}
signed main() {
    scanf("%d%d", &a, &b);
    sieve(b);
    printf("%d", cnt);
    return 0;
}