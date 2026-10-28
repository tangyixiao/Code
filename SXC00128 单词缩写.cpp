#include <bits/stdc++.h>
using namespace std;
int n, i, j, k, m, ok;
string bad[105], line, ab, wd[105];
int nw;
string low(string s) {
    for (int t = 0; t < (int)s.size(); t++) {
        if (s[t] >= 'A' && s[t] <= 'Z') {
            s[t] = s[t] - 'A' + 'a';
        }
    }
    return s;
}
signed main() {
    cin >> n;
    for (i = 0; i < n; i++) {
        cin >> bad[i];
    }
    getline(cin, line);
    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == ' ' || line.back() == '\r')) {
            line.pop_back();
        }
        while (!line.empty() && line.front() == ' ') {
            line.erase(line.begin());
        }
        if (line.empty()) {
            continue;
        }
        nw = 0;
        string cur = "";
        for (j = 0; j <= (int)line.size(); j++) {
            if (j == (int)line.size() || line[j] == ' ') {
                if (!cur.empty()) {
                    wd[nw++] = cur;
                    cur = "";
                }
            } else {
                cur += line[j];
            }
        }
        if (nw == 2 && wd[0] == "LAST" && wd[1] == "CASE") {
            break;
        }
        ab = wd[0];
        int cnt = 0;
        string eff[105];
        for (j = 1; j < nw; j++) {
            int isbad = 0;
            string lo = low(wd[j]);
            for (k = 0; k < n; k++) {
                if (bad[k] == lo) {
                    isbad = 1;
                }
            }
            if (isbad == 0) {
                eff[cnt++] = lo;
            }
        }
        long long ways = 1;
        ok = 1;
        if (cnt != (int)ab.size()) {
            ok = 0;
        } else {
            for (j = 0; j < cnt; j++) {
                char c = ab[j] - 'A' + 'a';
                int c2 = 0;
                for (k = 0; k < (int)eff[j].size(); k++) {
                    if (eff[j][k] == c) {
                        c2++;
                    }
                }
                if (c2 == 0) {
                    ok = 0;
                }
                ways *= c2;
            }
        }
        if (ok == 0) {
            cout << ab << " is not a valid abbreviation" << "\n";
        } else {
            cout << ab << " can be formed in " << ways << " ways" << "\n";
        }
    }
    return 0;
}
