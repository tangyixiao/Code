#include <bits/stdc++.h>
using namespace std;
int n, x, k;
int main() {
    scanf("%d", &n);
    while (n > 0) {
        n = n - 1092;
        k++;
        if (n % 364 == 0) {
            if (n <= 36400) {
                x = n / 364;
                break;
            }
        }
    }
    printf("%d\n%d", x, k);
    return 0;
}
