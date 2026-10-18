#include <bits/stdc++.h>
using namespace std;
const int N = 3e4 + 5;
int n, t, a[N], key;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d", &key);
        int l = 1, r = n, pos = -1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] <= key) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        printf("%d ", l - 1 >= 1 && a[l - 1] == key ? l - 1 : -1);
    }
    return 0;
}