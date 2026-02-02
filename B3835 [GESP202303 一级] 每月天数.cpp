
#include <bits/stdc++.h>
using namespace std;
int a, b;
signed main() {
    scanf("%d%d", &a, &b);
    swap(a, b);
    if (a == 1 || a == 3 || a == 5 || a == 7 || a == 8 || a == 10 || a == 12) {
        printf("31\n");
    }

    else if (a == 4 || a == 6 || a == 9 || a == 11) {
        printf("30\n");
    }

    else if (a == 2) {
        if (b % 4 == 0 && b % 100 != 0 || b % 400 == 0) {
            printf("29\n");
        } else {
            printf("28\n");
        }
    }
    return 0;
}