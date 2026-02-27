#include <bits/stdc++.h>
using namespace std;
char c;
int ans[5] = {139311, 52800, 26287, 47373, 240};
int main()
{
    cin >> c;
    cout << ans[c - 'A'] << endl;
    return 0;
}
