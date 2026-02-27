#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>

using namespace std;

const int MAXA = 40000;
struct Block {
    int h, a, c;
} b[405];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
        cin >> b[i].h >> b[i].a >> b[i].c;

    sort(b, b + N, [](const Block &x, const Block &y) {
        return x.a < y.a;
    });

    bitset<MAXA + 1> dp;
    dp[0] = 1;

    for (int i = 0; i < N; ++i) {
        int h = b[i].h, a = b[i].a, c = b[i].c;

        int cnt = c;
        for (int k = 1; cnt > 0; k <<= 1) {
            int take = min(k, cnt);
            int w = take * h;

            dp = dp | (dp << w);

            for (int j = a + 1; j <= MAXA; ++j)
                dp[j] = 0;
            cnt -= take;
        }
    }

    for (int i = MAXA; i >= 0; --i) {
        if (dp[i]) {
            cout << i << '\n';
            break;
        }
    }

    return 0;
}