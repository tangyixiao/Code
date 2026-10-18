#include <bits/stdc++.h>
using namespace std;

const int N = 2e3 + 5;
char s[N];
int n, k;

signed main() {
    cin.getline(s, N);
    for (int i = 0; s[i]; i++) {
        n++, k += s[i] == '.';
    }
    cout << s << "\n";
    cout << "字符个数:" << n << "\n";
    cout << ".的个数:" << k << "\n";
    return 0;
}