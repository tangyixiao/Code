#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct State {
    ll V;
    ll Sum;
    vector<int> elems;
};

vector<State> allStates;

int k;
int cnt[20];

void dfs(int e, int cur_s, int m, int e0, bool has_ge3) {
    if (e == 0) {
        if (cur_s == 0)
            return;
        State st;
        st.V = 0;
        st.Sum = 0;
        for (int i = 1; i <= k + 1; ++i) {
            if (cnt[i]) {
                int val = 1 << i;
                for (int j = 0; j < cnt[i]; ++j) {
                    st.elems.push_back(val);
                    st.Sum += val;
                    st.V += (ll)(i - 1) * val;
                }
            }
        }
        allStates.push_back(st);
        return;
    }

    int max_c = k - cur_s;
    for (int c = 0; c <= max_c; ++c) {
        if (e >= 3 && c > 0) {
            int m_prime = m + c;
            int e0_prime = has_ge3 ? e0 : e;

            if (e0_prime + m_prime - 2 > k)
                break;
            cnt[e] = c;
            dfs(e - 1, cur_s + c, m_prime, e0_prime, true);
            cnt[e] = 0;
        } else {
            cnt[e] = c;
            dfs(e - 1, cur_s + c, m, e0, has_ge3);
            cnt[e] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> k;

    memset(cnt, 0, sizeof(cnt));
    dfs(k + 1, 0, 0, 0, false);

    vector<vector<State>> byMod(4);
    for (State &st : allStates) {
        byMod[st.V % 4].push_back(st);
    }
    for (int i = 0; i < 4; ++i) {
        sort(byMod[i].begin(), byMod[i].end(),
             [](const State &a, const State &b) { return a.V < b.V; });
    }

    ll maxSum = 0;
    for (auto &st : allStates)
        if (st.Sum > maxSum)
            maxSum = st.Sum;

    while (n--) {
        ll h;
        cin >> h;
        int mod = h % 4;
        auto &vec = byMod[mod];

        auto it = lower_bound(vec.begin(), vec.end(), h,
                              [](const State &st, ll val) { return st.V < val; });

        bool found = false;
        while (it != vec.end() && it->V <= h + maxSum) {
            if (it->V - h <= it->Sum) {
                found = true;
                cout << it->elems.size();
                for (int x : it->elems)
                    cout << " " << x;
                cout << "\n";
                break;
            }
            ++it;
        }
        if (!found)
            cout << "-1\n";
    }

    return 0;
}