#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

const int NEG_INF = -1e9; 

int main() {
    int F, V;
    cin >> F >> V;

    
    vector<vector<int>> a(F + 1, vector<int>(V + 1));
    for (int i = 1; i <= F; ++i)
        for (int j = 1; j <= V; ++j)
            cin >> a[i][j];

    
    vector<vector<int>> dp(F + 1, vector<int>(V + 1, NEG_INF));
    
    vector<vector<int>> pre(F + 1, vector<int>(V + 1, 0));

    dp[0][0] = 0; 

    for (int i = 1; i <= F; ++i) {
        
        int max_j = V - (F - i);
        for (int j = i; j <= max_j; ++j) {
            for (int k = i - 1; k < j; ++k) { 
                if (dp[i - 1][k] + a[i][j] > dp[i][j]) {
                    dp[i][j] = dp[i - 1][k] + a[i][j];
                    pre[i][j] = k;
                }
            }
        }
    }

    
    int max_val = NEG_INF, last_pos = -1;
    for (int j = F; j <= V; ++j) {
        if (dp[F][j] > max_val) {
            max_val = dp[F][j];
            last_pos = j;
        }
    }

    cout << max_val << endl;

    vector<int> ans(F + 1);
    int cur_i = F, cur_j = last_pos;
    while (cur_i >= 1) {
        ans[cur_i] = cur_j;
        cur_j = pre[cur_i][cur_j];
        --cur_i;
    }

    for (int i = 1; i <= F; ++i) {
        cout << ans[i];
        if (i != F)
            cout << " ";
    }
    cout << endl;

    return 0;
}