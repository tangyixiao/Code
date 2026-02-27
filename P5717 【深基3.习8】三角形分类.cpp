#include <bits/stdc++.h>
using namespace std;
int a, b, c;
signed main() {
    cin >> a >> b >> c;
    if (a + b > c && a + c > b && b + c > a) {
        if (a * a + b * b == c * c || b * b + c * c == a * a || c * c + a * a == b * b) {
            cout << "Right triangle\n";
        } else {
            if (a * a + b * b > c * c && b * b + c * c > a * a && c * c + a * a > b * b) {
                cout << "Acute triangle\n";
            } else {
                cout << "Obtuse triangle\n";
            }
        }
        if (a == b || b == c || c == a) {
            cout << "Isosceles triangle\n";
            if (a == b && b == c) {
                cout << "Equilateral triangle\n";
            }
        }
    } else {
        cout << "Not triangle\n";
    }
    return 0;
}