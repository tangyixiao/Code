
#include <iostream>

using namespace std;

int ans[5] = {624, 2481215, 761, 8879, 80};
char c;

int main() {
    cin >> c;
    cout << ans[c - 'A'];
    return 0;
}
