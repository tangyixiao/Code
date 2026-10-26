#include <bits/stdc++.h>
using namespace std;
int a, b, c, d;
char op;
signed main() {
    scanf("%d/%d%c%d/%d", &a, &b, &op, &c, &d);
    int num = a * d, den = b * d;
    if (op == '+') {
        num += c * b;
    } else {
        num -= c * b;
    }
    int g = __gcd(abs(num), den);
    num /= g;
    den /= g;
    if (num == 0) {
        cout << 0 << "\n";
    } else if (den == 1) {
        cout << num << "\n";
    } else {
        cout << num << "/" << den << "\n";
    }
    return 0;
}
