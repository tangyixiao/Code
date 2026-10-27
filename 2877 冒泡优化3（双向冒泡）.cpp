#include <bits/stdc++.h>
using namespace std;
const int N = 5e2 + 5;
int n, a[N];
void print() {
    for (int i = 1; i <= n; i++) {
        if (i > 1) {
            cout << " ";
        }
        cout << a[i];
    }
    cout << "\n";
}
signed main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int lo = 1, hi = n;
    if (n == 1) {
        print();
        return 0;
    }
    for (; lo < hi;) {
        int sw = 0;
        for (int j = lo; j < hi; j++) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sw = 1;
            }
        }
        print();
        if (!sw) {
            break;
        }
        hi--;
        sw = 0;
        for (int j = hi - 1; j >= lo; j--) {
            if (a[j] > a[j + 1]) {
                swap(a[j], a[j + 1]);
                sw = 1;
            }
        }
        print();
        if (!sw) {
            break;
        }
        lo++;
    }
    return 0;
}
