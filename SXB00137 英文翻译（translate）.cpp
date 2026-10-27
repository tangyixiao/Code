#include <bits/stdc++.h>
using namespace std;

const int N = 1e2 + 5;
int k, cnt, wn;
string all, cache[N], cur;

void flush() {
    if (cur.empty()) {
        return;
    }
    for (int j = 0; j < wn; j++) {
        if (cache[j] == cur) {
            cur = "";
            return;
        }
    }
    cnt++;
    if (wn < k) {
        cache[wn++] = cur;
    } else {
        for (int j = 1; j < wn; j++) {
            cache[j - 1] = cache[j];
        }
        cache[wn - 1] = cur;
    }
    cur = "";
}

signed main() {
    scanf("%d", &k);
    char ch;
    while ((ch = getchar()) != EOF) {
        all += ch;
    }
    for (int i = 0; i < (int)all.size(); i++) {
        if (isalpha((unsigned char)all[i])) {
            cur += (char)tolower((unsigned char)all[i]);
        } else {
            flush();
        }
    }
    flush();
    printf("%d\n", cnt);
    return 0;
}
