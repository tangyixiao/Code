#include <bits/stdc++.h>
using namespace std;

string s[5];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    getline(cin, s[0]);
    bool pic = false;
    for (int i = 0; i < (int)s[0].size(); i++) {
        if (s[0][i] == '.' || s[0][i] == '#') {
            pic = true;
        }
    }
    int r, c, w;
    if (pic) {
        for (int i = 1; i < 5; i++) {
            getline(cin, s[i]);
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < (int)s[i].size(); j++) {
                cout << (s[i][j] == '#' ? '*' : s[i][j]);
            }
            cout << "\n";
        }
        return 0;
    }
    string t;
    for (int i = 0; i < (int)s[0].size(); i++) {
        if (s[0][i] >= 'A' && s[0][i] <= 'Z') {
            t += s[0][i];
        }
    }
    int n = t.size();
    w = 4 * (n - 1) + 5;
    char a[5][100];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = '.';
        }
    }
    for (int k = 0; k < n; k++) {
        char ch = (k + 1) % 3 == 0 ? '*' : '#';
        int o = 4 * k;
        a[0][o + 2] = ch;
        a[1][o + 1] = ch;
        a[1][o + 3] = ch;
        a[2][o] = ch;
        a[2][o + 2] = t[k];
        a[2][o + 4] = ch;
        a[3][o + 1] = ch;
        a[3][o + 3] = ch;
        a[4][o + 2] = ch;
    }
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < w; j++) {
            cout << a[i][j];
        }
        cout << "\n";
    }
    return 0;
}
