#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            int val;
            cin >> val;
            a[i][j] = a[j][i] = val;
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        int max1 = 0, max2 = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j)
                continue;
            if (a[i][j] > max1) {
                max2 = max1;
                max1 = a[i][j];
            } else if (a[i][j] > max2) {
                max2 = a[i][j];
            }
        }
        ans = max(ans, max2);
    }

    cout << 1 << endl << ans << endl;
    return 0;
}