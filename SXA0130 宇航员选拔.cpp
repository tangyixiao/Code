#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int age, weight, height;
    cin >> age >> weight >> height;
    if (height >= 165 && height <= 185 && weight >= 50 && weight <= 80 && age >= 16 && age <= 19) {
        cout << "Y\n";
    } else {
        cout << "N\n";
    }
    return 0;
}
