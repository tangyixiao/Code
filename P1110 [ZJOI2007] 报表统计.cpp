#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
const int INF = 0x3f3f3f3f;

int n, m;
int a[N];
int last[N];
multiset<int> gapSet;
multiset<int> allSet;
int minSortGap = INF;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        last[i] = a[i];

        auto it = allSet.lower_bound(a[i]);
        if (it != allSet.end())
            minSortGap = min(minSortGap, abs(*it - a[i]));
        if (it != allSet.begin())
            minSortGap = min(minSortGap, abs(*prev(it) - a[i]));
        allSet.insert(a[i]);

        if (i > 1)
            gapSet.insert(abs(a[i] - a[i - 1]));
    }

    while (m--) {
        string op;
        cin >> op;
        if (op == "INSERT") {
            int pos, k;
            cin >> pos >> k;
            if (pos < n) {
                auto it = gapSet.find(abs(last[pos] - a[pos + 1]));
                if (it != gapSet.end())
                    gapSet.erase(it);

                gapSet.insert(abs(k - a[pos + 1]));
            }

            gapSet.insert(abs(k - last[pos]));

            auto it = allSet.lower_bound(k);
            if (it != allSet.end())
                minSortGap = min(minSortGap, abs(*it - k));
            if (it != allSet.begin())
                minSortGap = min(minSortGap, abs(*prev(it) - k));
            allSet.insert(k);

            last[pos] = k;

        } else if (op == "MIN_GAP") {

            cout << *gapSet.begin() << "\n";
        } else if (op == "MIN_SORT_GAP") {
            cout << minSortGap << "\n";
        }
    }

    return 0;
}