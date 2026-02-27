#include <bits/stdc++.h>
using namespace std;
string s;
int l;
int main() {
    cin >> s;
    l = s.length();
    for (int i = 0; i < l; ++i) {
        if (isupper(s[i])) {
            s[i] = tolower(s[i]);
        } else {
            if (islower(s[i])) {
                s[i] = toupper(s[i]);
            }
        }
    }
    reverse(s.begin(), s.end());
    for (int i = 0; i < l; ++i) {
        switch (s[i]) {
        case 'x':
            cout << 'a';
            break;
        case 'X':
            cout << 'A';
            break;
        case 'y':
            cout << 'b';
            break;
        case 'Y':
            cout << 'B';
            break;
        case 'z':
            cout << 'c';
            break;
        case 'Z':
            cout << 'C';
            break;
        default:
            cout << char(s[i] + 3);
            break;
        }
    }
    return 0;
}
