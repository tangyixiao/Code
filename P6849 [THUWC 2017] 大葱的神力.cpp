#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10010;
const int MAXM = 10010;

int N, M;
vector<int> a(MAXN), b(MAXM);
vector<vector<int>> w(MAXN, vector<int>(MAXM));
vector<int> assignment(MAXN, 0);
vector<int> used(MAXM, 0);
vector<vector<pair<int, int>>> item_drawers;
long long total_value = 0;

void read_input(const string& filename) {
    ifstream fin(filename);
    fin >> N >> M;
    for (int i = 1; i <= N; i++) fin >> a[i];
    for (int j = 1; j <= M; j++) fin >> b[j];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= M; j++)
            fin >> w[i][j];
    fin.close();
}

void write_output(const string& filename) {
    ofstream fout(filename);
    for (int i = 1; i <= N; i++) {
        fout << assignment[i] << "\n";
    }
    fout.close();
}

long long greedy() {
    item_drawers.resize(N+1);
    for (int i = 1; i <= N; i++) {
        vector<pair<int, int>>& list = item_drawers[i];
        for (int j = 1; j <= M; j++) {
            list.push_back({w[i][j], j});
        }
        sort(list.begin(), list.end(), [](const pair<int, int>& x, const pair<int, int>& y) {
            return x.first > y.first;
        });
    }

    vector<int> item_ids;
    for (int i = 1; i <= N; i++) item_ids.push_back(i);
    // 按单位体积的最大价值排序
    sort(item_ids.begin(), item_ids.end(), [&](int i, int k) {
        double vi = (item_drawers[i].empty() ? 0 : (double)item_drawers[i][0].first / a[i]);
        double vk = (item_drawers[k].empty() ? 0 : (double)item_drawers[k][0].first / a[k]);
        return vi > vk;
    });

    vector<int> remaining = b;
    long long val = 0;
    for (int i : item_ids) {
        bool placed = false;
        for (auto& p : item_drawers[i]) {
            int j = p.second;
            if (remaining[j] >= a[i]) {
                assignment[i] = j;
                used[j] += a[i];
                remaining[j] -= a[i];
                val += w[i][j];
                placed = true;
                break;
            }
        }
        if (!placed) {
            assignment[i] = 0;
        }
    }
    return val;
}

void local_search() {
    const int K = 10;
    const int swap_tries = 10000;
    const int max_rounds = 100;
    int round = 0;
    bool improved = true;
    vector<int> remaining(M+1);
    for (int j = 1; j <= M; j++) remaining[j] = b[j] - used[j];

    while (improved && round < max_rounds) {
        improved = false;
        round++;

        // 移动操作
        for (int i = 1; i <= N; i++) {
            if (assignment[i] == 0) continue;
            int cur_drawer = assignment[i];
            int cur_value = w[i][cur_drawer];
            int cnt = 0;
            for (auto& p : item_drawers[i]) {
                if (cnt >= K) break;
                int j = p.second;
                if (j == cur_drawer) continue;
                cnt++;
                if (remaining[j] >= a[i] && w[i][j] > cur_value) {
                    // 移动
                    remaining[cur_drawer] += a[i];
                    remaining[j] -= a[i];
                    used[cur_drawer] -= a[i];
                    used[j] += a[i];
                    assignment[i] = j;
                    total_value += w[i][j] - cur_value;
                    improved = true;
                    cur_drawer = j;
                    cur_value = w[i][j];
                    break;
                }
            }
        }

        // 交换操作
        for (int t = 0; t < swap_tries; t++) {
            int i = rand() % N + 1;
            int k = rand() % N + 1;
            if (i == k) continue;
            int j = assignment[i];
            int l = assignment[k];
            if (j == 0 || l == 0) continue;
            if (j == l) continue;
            if (remaining[j] + a[i] - a[k] >= 0 && remaining[l] + a[k] - a[i] >= 0) {
                int old_value = w[i][j] + w[k][l];
                int new_value = w[i][l] + w[k][j];
                if (new_value > old_value) {
                    remaining[j] += a[i] - a[k];
                    remaining[l] += a[k] - a[i];
                    used[j] += a[k] - a[i];
                    used[l] += a[i] - a[k];
                    assignment[i] = l;
                    assignment[k] = j;
                    total_value += new_value - old_value;
                    improved = true;
                }
            }
        }

        // 插入操作
        for (int i = 1; i <= N; i++) {
            if (assignment[i] != 0) continue;
            int cnt = 0;
            for (auto& p : item_drawers[i]) {
                if (cnt >= K) break;
                int j = p.second;
                cnt++;
                if (remaining[j] >= a[i] && w[i][j] > 0) {
                    assignment[i] = j;
                    used[j] += a[i];
                    remaining[j] -= a[i];
                    total_value += w[i][j];
                    improved = true;
                    break;
                }
            }
        }
    }
}

void solve(const string& input_file, const string& output_file) {
    read_input(input_file);
    total_value = greedy();
    local_search();
    write_output(output_file);
}

int main(int argc, char* argv[]) {
    srand(time(0));
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <input_file> <output_file>" << endl;
        return 1;
    }
    solve(argv[1], argv[2]);
    return 0;
}