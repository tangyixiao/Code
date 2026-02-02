#include <iostream>
using namespace std;
double m, h, bmi;
signed main() {
    cin >> m >> h;
    bmi = m / (h * h);
    if (bmi < 18.5) {
        cout << "Underweight";
    } else {
        if (bmi < 24) {
            cout << "Normal";
        } else {
            cout << bmi << "\n"
                 << "Overweight";
        }
    }
    return 0;
}