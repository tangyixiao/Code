#include <bits/stdc++.h>
using namespace std;
char a, b, c;
int n;
inline void hanoi(int n, char a, char b, char c) {
    if (n == 1) {
        cout << a << "->" << n << "->" << c << "\n";
        return;
    }
    hanoi(n - 1, a, c, b);
    cout << a << "->" << n << "->" << c << "\n";
    hanoi(n - 1, b, a, c);
    return;
}
signed main() {
    cin >> n >> a >> b >> c;
    hanoi(n, a, c, b);
    return 0;
}