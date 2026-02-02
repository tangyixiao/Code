#pragma G++ optimize("O3", "Ofast", "unroll-loops", "inline")
#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace fast_read_write {
const int BUFFER_SIZE = 1 << 16;  // 64KB 缓冲区
char buffer[BUFFER_SIZE];
char* ptr = buffer + BUFFER_SIZE;

inline char getchar_fast() {
    if (ptr == buffer + BUFFER_SIZE) {
        fread(buffer, 1, BUFFER_SIZE, stdin);
        ptr = buffer;
    }
    return *ptr++;
}

inline int read() {
    int x = 0, f = 1;
    char ch = getchar_fast();
    while (!isdigit(ch)) {
        if (ch == '-')
            f = -1;
        ch = getchar_fast();
    }
    while (isdigit(ch)) {
        x = (x << 3) + (x << 1) + (ch ^ 48);
        ch = getchar_fast();
    }
    return x * f;
}

inline void write(int x) {
    static int sta[35];
    int top = 0;
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    do {
        sta[top++] = x % 10;
        x /= 10;
    } while (x);
    while (top)
        putchar(sta[--top] + '0');
}
}  // namespace fast_read_write

using namespace fast_read_write;
int n, a, ans;

signed main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        a = read();
        ans += a;
    }
    write(ans);
    return 0;
}
