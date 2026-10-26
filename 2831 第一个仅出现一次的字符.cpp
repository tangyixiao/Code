#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char s[N];
int n, i, c[26];
signed main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    for (i = 1; i <= n; i++) {
        c[s[i] - 'a']++;
    }
    for (i = 1; i <= n; i++) {
        if (c[s[i] - 'a'] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    printf("no\n");
    return 0;
}
