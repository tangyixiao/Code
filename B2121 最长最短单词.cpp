#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    getline(cin, line); 

    vector<string> words;
    string word;
    for (char c : line) {
        if (isalpha(c)) { 
            word.push_back(c);
        } else {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }

    if (words.empty()) { 
        return 0;
    }

    int max_len = 0, min_len = INT_MAX;
    for (const string &w : words) {
        int len = w.size();
        if (len > max_len)
            max_len = len;
        if (len < min_len)
            min_len = len;
    }

    string longest, shortest;
    for (const string &w : words) {
        if (w.size() == max_len && longest.empty()) {
            longest = w;
        }
        if (w.size() == min_len && shortest.empty()) {
            shortest = w;
        }
    }

    cout << longest << "\n" << shortest << "\n";

    return 0;
}