#include <bits/stdc++.h>
using namespace std;
int n, k = 1;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%.02d", k);
            k++;
        }
        cout << '\n';
    }
    cout << '\n';
    k = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= (n - i) * 2; j++) {
            cout << ' ';
        }
        for (int j = 1; j <= i; j++) {
            printf("%.02d", k);
            k++;
        }
        cout << '\n';
    }
    return 0;
}
