#include <bits/stdc++.h>
using namespace std;
const int N = 10;
int n, rN = 1, a[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        rN *= i;
        a[i] = i;
    }
    for (int i = 1; i <= rN; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%5d", a[j]);
        }
        next_permutation(a + 1, a + 1 + n);
        printf("\n");
    }
    return 0;
}