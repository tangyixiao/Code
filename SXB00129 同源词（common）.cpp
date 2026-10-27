#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
char s[N], q[N];
int la, lb, n, i, j, st[N], top, ok, c1[26], c2[26];
signed main() {
    scanf("%s%s", s + 1, q + 1);
    la = strlen(s + 1), lb = strlen(q + 1);
    if (lb > la) {
        printf("NO\n");
        return 0;
    }
    for (i = 1; i <= lb; i++) {
        c1[tolower(s[i]) - 'a']++;
        c2[tolower(q[i]) - 'a']++;
    }
    for (i = 1; i + lb - 1 <= la; i++) {
        if (i > 1) {
            c1[tolower(s[i - 1]) - 'a']--;
            c1[tolower(s[i + lb - 1]) - 'a']++;
        }
        ok = 1;
        for (j = 0; j < 26; j++) {
            if (c1[j] != c2[j]) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            st[++top] = i - 1;
        }
    }
    if (!top) {
        printf("NO\n");
        return 0;
    }
    for (i = 1; i <= top; i++) {
        if (i > 1) {
            printf(" ");
        }
        printf("%d", st[i]);
    }
    printf("\n");
    return 0;
}
