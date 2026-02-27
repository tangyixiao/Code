#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
string s;
map<char, int> mp;
int maxn, minn = 0x3f3f3f3f;
int main()
{
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
    }
    for (auto it : mp)
    {
        if (minn > it.second)
        {
            minn = it.second;
        }
        if (maxn < it.second)
        {
            maxn = it.second;
        }
    }
    int k = maxn - minn;
    if (isPrime(k))
    {
        cout << "Lucky Word\n";
        cout << k;
    }
    else
    {
        cout << "No Answer\n";
        cout << 0;
    }
    return 0;
}