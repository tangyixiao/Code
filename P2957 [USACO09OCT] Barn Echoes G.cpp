#include <bits/stdc++.h>

#define ull unsigned long long

using namespace std;

const int N = 10005;

int n, ans;
string s1, s2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> s1 >> s2;

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            if (s1[i] == s2[j]) {
                int s = 0;
                for (int k = 0; k <= min(s1.size() - i, s2.size() - j); k++) {
                    if (s1[i + k] == s2[j + k]) {
                        s++;
                    }
                }
                ans = max(ans, s);
            }
        }
    }
    cout << ans + 1;

    return 0;
}
