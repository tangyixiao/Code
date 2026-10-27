#include <bits/stdc++.h>
using namespace std;

int c[26], mx;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z') {
            c[s[i] - 'A']++;
            if (c[s[i] - 'A'] > mx) {
                mx = c[s[i] - 'A'];
            }
        }
    }
    for (int r = mx; r >= 1; r--) {
        string line;
        for (int i = 0; i < 26; i++) {
            if (c[i] == 0) {
                continue;
            }
            if (!line.empty()) {
                line += ' ';
            }
            line += (c[i] >= r ? '*' : ' ');
        }
        for (; !line.empty() && line.back() == ' ';) {
            line.pop_back();
        }
        cout << line << "\n";
    }
    string last;
    for (int i = 0; i < 26; i++) {
        if (c[i] == 0) {
            continue;
        }
        if (!last.empty()) {
            last += ' ';
        }
        last += (char)('A' + i);
    }
    cout << last << "\n";
    return 0;
}
