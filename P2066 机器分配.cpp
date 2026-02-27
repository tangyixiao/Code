#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> profit; 
int max_profit = -1;
vector<int> best_assign; 
vector<int> cur_assign;
int cur_sum = 0;

void dfs(int company, int used) {
    if (company == N + 1) {
        if (used <= M) {
            if (cur_sum > max_profit) {
                max_profit = cur_sum;
                best_assign = cur_assign;
            } else if (cur_sum == max_profit && cur_assign < best_assign) {
                best_assign = cur_assign;
            }
        }
        return;
    }
    
    for (int k = 0; k <= M - used; ++k) {
        cur_assign.push_back(k);
        cur_sum += profit[company][k];
        dfs(company + 1, used + k);
        cur_sum -= profit[company][k];
        cur_assign.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    profit.assign(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            cin >> profit[i][j];
        }
        profit[i][0] = 0; 
    }

    dfs(1, 0);

    cout << max_profit << '\n';
    for (int i = 0; i < N; ++i) {
        cout << i + 1 << ' ' << best_assign[i] << '\n';
    }
    return 0;
}