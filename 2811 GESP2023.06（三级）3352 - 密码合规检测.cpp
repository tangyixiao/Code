#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
char s[N], t[N];
int i, j, n, L, u, d, sp, ans, c1, c2, c3, c4;
bool ok;
signed main() {
    scanf("%s", s);
    L = strlen(s);
    for (i = 0; i <= L; i++) {
        if (i == L || s[i] == ',') {
            t[j] = 0;
            ok = 1;
            if (j < 6 || j > 12) {
                ok = 0;
            }
            c1 = c2 = c3 = c4 = 0;
            for (int k = 0; k < j; k++) {
                char ch = t[k];
                if (ch >= 'a' && ch <= 'z') {
                    c1++;
                } else if (ch >= 'A' && ch <= 'Z') {
                    c2++;
                } else if (ch >= '0' && ch <= '9') {
                    c3++;
                } else if (ch == '!' || ch == '@' || ch == '#' || ch == '$') {
                    c4++;
                } else {
                    ok = 0;
                }
            }
            if ((c1 > 0) + (c2 > 0) + (c3 > 0) < 2 || c4 == 0) {
                ok = 0;
            }
            if (ok) {
                printf("%s\n", t);
            }
            j = 0;
        } else {
            t[j++] = s[i];
        }
    }
    return 0;
}
