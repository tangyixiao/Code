#include <bits/stdc++.h>
using namespace std;
int T, M, a, b, q;
int Q(int x, int y) {
    int z = ceil(sqrt(M));
    long long B = y, T = 1;
    unordered_map<int, int> H;
    for (int i = 1; i <= z; ++i)
        H[B = B * x % M] = i;
    for (int i = B = 1; i <= z; ++i)
        B = B * x % M;
    for (int i = 1; i <= z; ++i)
        if (H[T = T * B % M])
            return i * z - H[T];
    return -1;
}
int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d%d%d", &M, &a, &b);
        if (!(a % M) || b >= M)
            puts("Couldn't Produce!");
        else if (~(q = Q(a, b)))
            printf("%d\n", q);
        else
            puts("Couldn't Produce!");
    }
    return 0;
}
