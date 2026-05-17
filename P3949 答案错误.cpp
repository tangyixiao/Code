#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    while (q--) {
        unsigned long long x;
        scanf("%llu", &x);
        x--;

        int cnt = __builtin_popcountll(x);
        putchar(cnt % 2 == 0 ? 'X' : 'Z');
        putchar('\n');
    }
    return 0;
}