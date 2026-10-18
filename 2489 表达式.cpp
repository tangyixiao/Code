#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;

char s[N];

signed main() {
    while (cin >> s) {
        int l = strlen(s), p = 0, r = 0;
        char o = 0, e = 0;
        for (int i = 0; i < l; i++) {
            if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
                p = i, o = s[i];
            } else if (s[i] == '=' || s[i] == '<' || s[i] == '>') {
                r = i, e = s[i];
            }
        }
        s[p] = 0, s[r] = 0;
        long long a = atoll(s), b = atoll(s + p + 1), c = atoll(s + r + 1), v;
        s[p] = o;
        if (o == '+') {
            v = a + b;
        } else if (o == '-') {
            v = a - b;
        } else if (o == '*') {
            v = a * b;
        } else {
            v = a / b;
        }
        if ((e == '=' && v == c) || (e == '<' && v < c) || (e == '>' && v > c)) {
            cout << "True\n";
        } else {
            cout << s << (v == c ? '=' : (v < c ? '<' : '>')) << c << "\n";
        }
    }
    return 0;
}