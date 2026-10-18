#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;

char s[][6] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
               ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
               "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

signed main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char t[N];
        cin >> t;
        for (int j = 0; j < 26; j++) {
            if (!strcmp(s[j], t)) {
                cout << char('A' + j);
                break;
            }
        }
    }
    cout << "\n";
    return 0;
}