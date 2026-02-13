#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> cities(N);
    for (int i = 0; i < N; ++i) {
        cin >> cities[i].first >> cities[i].second;
    }

    sort(cities.begin(), cities.end());

    vector<int> lis;
    for (int i = 0; i < N; ++i) {
        int x = cities[i].second;
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if (it == lis.end()) {
            lis.push_back(x);
        } else {
            *it = x;
        }
    }

    cout << lis.size() << endl;
    return 0;
}