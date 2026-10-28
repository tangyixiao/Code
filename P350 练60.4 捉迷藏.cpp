#include <bits/stdc++.h>
using namespace std;

int i, s, v;
int mark[10];

signed main() {
    for (i = 0; i < 10; i++) {
        mark[i] = 0;
    }
    v = 0;
    for (i = 1; i <= 1000; i++) {
        v = (v + i) % 10;
        mark[v] = 1;
    }
    for (i = 0; i < 10; i++) {
        if (mark[i] == 0) {
            printf("%d\n", i);
        }
    }
    return 0;
}
