#include <iostream>
#define endl '\n'
using namespace std;
void spread(int, int, int, int, int);
int main() {
    cin.tie(0)->sync_with_stdio(false);
    int k;
    cin >> k;
    int x, y;
    cin >> x >> y;
    spread(1, 1, x, y, k);
    return 0;
}
void spread(int x, int y, int prix, int priy, int k) {
    if (k == 0) {
        return;
    }
    int halfLen = 1 << (k - 1);
    int midX = x + halfLen - 1;
    int midY = y + halfLen - 1;
    if (prix <= midX && priy <= midY) {
        // 公主在左上象限，放置形状1，拐角在右下中心点
        cout << x + halfLen << ' ' << y + halfLen << ' ' << 1 << endl;
        spread(x, y, prix, priy, k - 1);
        spread(x, halfLen + y, midX, midY + 1, k - 1);
        spread(halfLen + x, y, midX + 1, midY, k - 1);
        spread(halfLen + x, halfLen + y, midX + 1, midY + 1, k - 1);
    } else if (prix <= midX && priy > midY) {
        // 公主在右上象限，放置形状2，拐角在左下中心点
        cout << x + halfLen << ' ' << y + halfLen - 1 << ' ' << 2 << endl;
        spread(x, y, midX, midY, k - 1);
        spread(x, halfLen + y, prix, priy, k - 1);
        spread(halfLen + x, y, midX + 1, midY, k - 1);
        spread(halfLen + x, halfLen + y, midX + 1, midY + 1, k - 1);
    } else if (prix > midX && priy <= midY) {
        // 公主在左下象限，放置形状3，拐角在右上中心点
        cout << x + halfLen - 1 << ' ' << y + halfLen << ' ' << 3 << endl;
        spread(x, y, midX, midY, k - 1);
        spread(x, halfLen + y, midX, midY + 1, k - 1);
        spread(halfLen + x, y, prix, priy, k - 1);
        spread(halfLen + x, halfLen + y, midX + 1, midY + 1, k - 1); // 修正：传递右下中心点
    } else {
        // 公主在右下象限，放置形状4，拐角在左上中心点
        cout << x + halfLen - 1 << ' ' << y + halfLen - 1 << ' ' << 4 << endl;
        spread(x, y, midX, midY, k - 1);
        spread(x, halfLen + y, midX, midY + 1, k - 1);
        spread(halfLen + x, y, midX + 1, midY, k - 1);
        spread(halfLen + x, halfLen + y, prix, priy, k - 1);
    }
}