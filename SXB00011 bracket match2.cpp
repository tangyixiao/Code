#include <bits/stdc++.h>
using namespace std;
const int N = 2e4 + 5;
char s[N];
int st[N], top, i, len, ok;
signed main() {
    scanf("%s", s + 1);
    len = strlen(s + 1), top = 0, ok = 1;
    for (i = 1; i <= len; i++) {
        if (s[i] == '(') {
            st[++top] = i - 1;
        } else {
            if (top == 0) {
                ok = 0;
                break;
            }
            top--;
        }
    }
    if (top) {
        ok = 0;
    }
    if (!ok) {
        printf("no\n");
        return 0;
    }
    printf("yes\n");
    top = 0;
    ok = 0;
    for (i = 1; i <= len; i++) {
        if (s[i] == '(') {
            st[++top] = i - 1;
        } else {
            if (ok) {
                printf(" ");
            }
            printf("%d", st[top--]);
            ok = 1;
        }
    }
    printf("\n");
    return 0;
}
