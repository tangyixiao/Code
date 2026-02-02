#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 3e6 + 5;
ll n, p, inv[N] = {0, 1};
int main() {
    scanf("%lld%lld", &n, &p);
    printf("1\n");
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)p - (p / i) * inv[p % i] % p, printf("%lld\n", inv[i]);
    return 0;
}