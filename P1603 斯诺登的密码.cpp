#include <bits/stdc++.h>
using namespace std;
char dic[30][20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "a", "both", "another", "first", "second", "third"}; // 对应
int di[30] = {0, 1, 4, 9, 16, 25, 36, 49, 64, 81, 00, 21, 44, 69, 96, 25, 56, 89, 24, 61, 0, 1, 4, 1, 1, 4, 9};
unsigned long long int a[10], top, flag;
int i, j;
char s[100];
int main() {
    for (i = 1; i <= 6; i++) {
        scanf("%s", &s); //%s读入遇到空格就停止
        for (j = 1; j <= 26; j++) {
            if (!strcmp(s, dic[j])) // strcmp(s1,s2);如果他们相同，返回0
            {
                a[++top] = di[j]; // 用数组存储
                break;            // 立即停止寻找
            }
        }
    }
    sort(a + 1, a + top + 1); // 贪心，使越小的数越靠前输出
    for (i = 1; i <= top; i++) {
        if (flag) // 如果不是第一位
        {
            printf("%.2d", a[i]); // 限制格式输出
        } else {
            if (a[i]) {
                printf("%d", a[i]);
                flag = 1;
            }
        }
    }
    if (!flag)
        printf("0"); // 特判
    return 0;
}
