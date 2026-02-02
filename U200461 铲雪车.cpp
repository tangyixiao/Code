#include <cmath>
#include <iomanip>
#include <iostream>
using namespace std;

int main() {
    int startX, startY;
    cin >> startX >> startY; // 起点坐标（不影响计算结果）

    double totalLength = 0.0;
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double dx = x2 - x1;
        double dy = y2 - y1;
        totalLength += sqrt(dx * dx + dy * dy); // 累加单条道路长度
    }

    double totalDistance = totalLength * 2;                   // 总路程（双向）
    int totalMinutes = round(totalDistance * 60.0 / 20000.0); // 总分钟数（四舍五入）
    int hours = totalMinutes / 60;
    int minutes = totalMinutes % 60;

    cout << hours << ":" << setfill('0') << setw(2) << minutes << endl;
    return 0;
}