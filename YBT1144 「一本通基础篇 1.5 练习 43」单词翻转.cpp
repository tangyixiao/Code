#include <bits/stdc++.h>
using namespace std;

const int N = 5e2 + 5;

char s[N];

signed main() {
    cin.getline(s, N);
    int n = strlen(s);
    if (n && s[n - 1] == '\r') {
        s[--n] = 0;
    }
    for (int i = 0; i < n; i++) {
        if (s[i] == ' ') {
            continue;
        }
        int j = i;
        while (j < n && s[j] != ' ') {
            j++;
        }
        for (int l = i, r = j - 1; l < r; l++, r--) {
            swap(s[l], s[r]);
        }
        i = j - 1;
    }
    cout << s << "\n";
    return 0;
}
