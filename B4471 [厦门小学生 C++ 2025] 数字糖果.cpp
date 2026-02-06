#include <iostream>
using namespace std;

const int OFFSET = 500;
const int RANGE = 1001;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int count[RANGE] = {0};

    for (int i = 0; i < n; ++i) {
        int c;
        cin >> c;
        ++count[c + OFFSET];
    }

    int half = n / 2;

    for (int i = 0; i < RANGE; ++i) {
        if (count[i] > half) {
            cout << i - OFFSET << '\n';
            return 0;
        }
    }

    cout << "no\n";
    return 0;
}