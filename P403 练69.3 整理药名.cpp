#include <bits/stdc++.h>
using namespace std;

const int N = 25 + 5;
char s[N];
int n;

signed main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; s[j]; j++) {
            if (j ? s[j] >= 'A' && s[j] <= 'Z' : s[j] >= 'a' && s[j] <= 'z') {
                s[j] += j ? 32 : -32;
            }
        }
        cout << s << "\n";
    }
    return 0;
}