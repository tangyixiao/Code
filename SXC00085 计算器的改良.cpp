#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
char s[N];
int i, len, sign;
double c1, k1, c2, k2, num, ans;
char v;
void parse(int l, int r, double &c, double &kk) {
    int i = l, sg;
    double num;
    while (i <= r) {
        sg = 1;
        if (s[i] == '+') {
            i++;
        } else if (s[i] == '-') {
            sg = -1, i++;
        }
        num = 0;
        int has = 0;
        for (; i <= r && s[i] >= '0' && s[i] <= '9'; i++) {
            num = num * 10 + (s[i] - '0');
            has = 1;
        }
        if (i <= r && s[i] >= 'a' && s[i] <= 'z') {
            if (!has) {
                num = 1;
            }
            c += sg * num;
            v = s[i];
            i++;
        } else {
            kk += sg * num;
        }
    }
}
signed main() {
    if (fopen("cal.in", "r")) {
        freopen("cal.in", "r", stdin);
        freopen("cal.out", "w", stdout);
    }
    scanf("%s", s + 1);
    len = strlen(s + 1);
    int p = 1;
    for (i = 1; i <= len; i++) {
        if (s[i] == '=') {
            p = i;
            break;
        }
    }
    c1 = k1 = c2 = k2 = 0;
    parse(1, p - 1, c1, k1);
    parse(p + 1, len, c2, k2);
    ans = (k2 - k1) / (c1 - c2);
    if (fabs(ans) < 0.0005) {
        ans = 0;
    }
    printf("%c=%.3f\n", v, ans);
    return 0;
}
