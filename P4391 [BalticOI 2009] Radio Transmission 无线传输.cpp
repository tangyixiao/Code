#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int n, kmp[N];
string s;
int main() {
    cin >> n >> s;
    s = "#" + s;
    int j = 0;
    for (int i = 2; i <= n; ++i) {
        while (j && s[i] != s[j + 1])
            j = kmp[j];
        if (s[i] == s[j + 1])
            ++j;
        kmp[i] = j;
    }
    cout << n - kmp[n] << "\n";
    return 0;
}