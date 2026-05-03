#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = (int)s.size();

    int ans = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        int k = i + 1;
        while (k < n && s[j] <= s[k]) {
            if (s[j] < s[k]) {
                j = i;
            } else {
                ++j;
            }
            ++k;
        }
        int p = k - j;
        while (i <= j) {
            ans ^= (i + p);
            i += p;
        }
    }

    cout << ans << '\n';
    return 0;
}