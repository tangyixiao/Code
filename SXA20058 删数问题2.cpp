#include <bits/stdc++.h>
using namespace std;

const int N = 3e2 + 5;

char s[N], st[N];
int sn, k, top, i;

signed main() {
    scanf("%s %d", s, &k);
    sn = strlen(s);
    top = 0;
    for (i = 0; i < sn; i++) {
        while (top > 0 && k > 0 && st[top - 1] < s[i]) {
            top--;
            k--;
        }
        st[top] = s[i];
        top++;
    }
    top -= k;
    for (i = 0; i < top; i++) {
        if (st[i] != '0') {
            break;
        }
    }
    if (i >= top) {
        printf("0\n");
    } else {
        for (; i < top; i++) {
            printf("%c", st[i]);
        }
        printf("\n");
    }
    return 0;
}
