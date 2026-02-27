#include <bits/stdc++.h>
using namespace std;
struct student {
    string name;
    int score;
};
bool cmp(student a, student b) {
    if (a.score != b.score)
        return a.score > b.score;
    else
        return a.name < b.name;
}
int main() {
    int n;
    cin >> n;
    student stu[n];
    for (int i = 0; i < n; i++) {
        cin >> stu[i].score >> stu[i].name;
    }
    sort(stu, stu + n, cmp);
    cout << stu[0].name << endl;
    return 0;
}