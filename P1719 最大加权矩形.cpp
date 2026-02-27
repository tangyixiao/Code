#include <climits>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    int ans = INT_MIN;
    
    for (int top = 0; top < n; ++top) {
        vector<int> col_sum(n, 0); 
        
        for (int bottom = top; bottom < n; ++bottom) {
            
            for (int j = 0; j < n; ++j)
                col_sum[j] += a[bottom][j];
            
            int cur = 0, best = INT_MIN;
            for (int j = 0; j < n; ++j) {
                cur = max(col_sum[j], cur + col_sum[j]);
                best = max(best, cur);
            }
            ans = max(ans, best);
        }
    }
    cout << ans << endl;
    return 0;
}