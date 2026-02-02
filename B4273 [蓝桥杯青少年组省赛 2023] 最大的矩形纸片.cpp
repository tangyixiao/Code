#include <iostream>
#include <algorithm>
#include <cstring>

#define int long long
using namespace std;
const int N = 1e6 + 10;

int n, top, ans, a[N], nums[N], w[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    while (cin >> n && n) {
        ans = 0, top = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[n + 1] = 0;

        for (int i = 1; i <= n + 1; i++) {
            if (a[i] > nums[top]) {
                nums[++top] = a[i];
                w[top] = 1;
            } else {
                int d = 0;
                while (nums[top] > a[i]) {
                    d += w[top];
                    ans = max(ans, d * nums[top]);
                    top--;
                }
                nums[++top] = a[i], w[top] = d + 1;
            }
        }

        cout << ans << "\n";
    }

    return 0;
}
