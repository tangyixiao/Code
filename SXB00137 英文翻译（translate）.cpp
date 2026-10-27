#include <bits/stdc++.h>
using namespace std;

int k, cnt, wn;
string s, cur;
string cache[105];

signed main() {
    cin >> k;
    cin >> ws;
    getline(cin, s);
    wn = 0;
    cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        char ch = s[i];
        if (isalpha(ch)) {
            cur += (char)tolower(ch);
            continue;
        }
        if (cur.size() > 0) {
            bool hit = false;
            for (int j = 0; j < wn; j++) {
                if (cache[j] == cur) {
                    hit = true;
                }
            }
            if (!hit) {
                cnt++;
                if (wn < k) {
                    cache[wn++] = cur;
                } else {
                    for (int j = 1; j < wn; j++) {
                        cache[j - 1] = cache[j];
                    }
                    cache[wn - 1] = cur;
                }
            }
            cur = "";
        }
        if (ch == '.') {
            break;
        }
    }
    if (cur.size() > 0) {
        bool hit = false;
        for (int j = 0; j < wn; j++) {
            if (cache[j] == cur) {
                hit = true;
            }
        }
        if (!hit) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}
