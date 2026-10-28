#include <bits/stdc++.h>
using namespace std;

const int N = 4e5 + 5;
int n, a[N], b[N], p[N];
long long s[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
    }
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    for (int i = 1; i <= n; i++) {
        p[i] = 1;
        q.push(make_pair((long long)a[i] + b[1], i));
    }
    for (int i = 1; i <= n; i++) {
        pair<long long, int> u = q.top();
        q.pop();
        cout << u.first << "\n";
        int k = u.second;
        if (p[k] < n) {
            p[k]++;
            q.push(make_pair((long long)a[k] + b[p[k]], k));
        }
    }
    return 0;
}
