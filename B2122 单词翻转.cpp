#pragma G++ optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k = 0;
    getline(cin, s);
    s = s + ' ';
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            for (int j = i - 1; j >= k; j--) {
                cout << s[j];
            }
            cout << '\n';
            k = i + 1;
        }
    }
    return 0;
}