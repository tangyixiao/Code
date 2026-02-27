#include <bits/stdc++.h>
using namespace std;
int a, c;
signed main() {
    scanf("%d", &a);
    for (int i = 1; i <= sqrt(a); i++) {
        if (a % i == 0) {
            c++;
        }
    }
    printf("%d", c);
    return 0;
}