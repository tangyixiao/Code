#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<ll> a(n + 1);          
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    
    set<pair<ll, int>> s;         
    s.insert({a[1], 1});          
    
    for (int i = 2; i <= n; ++i) {
        ll x = a[i];
        auto it = s.lower_bound({x, 0});  
        
        
        int cand1 = -1, cand2 = -1;
        ll diff1 = LLONG_MAX, diff2 = LLONG_MAX;
        
        
        if (it != s.begin()) {
            auto prev_it = prev(it);
            cand1 = prev_it->second;
            diff1 = abs(x - prev_it->first);
        }
        
        
        if (it != s.end()) {
            cand2 = it->second;
            diff2 = abs(x - it->first);
        }
        
        
        ll min_diff;
        int idx;
        if (cand1 == -1) {                
            min_diff = diff2;
            idx = cand2;
        } else if (cand2 == -1) {         
            min_diff = diff1;
            idx = cand1;
        } else {
            if (diff1 < diff2) {          
                min_diff = diff1;
                idx = cand1;
            } else if (diff1 > diff2) {   
                min_diff = diff2;
                idx = cand2;
            } else {                      
                min_diff = diff1;
                idx = cand1;
            }
        }
        
        cout << min_diff << " " << idx << "\n";
        s.insert({x, i});                 
    }
    
    return 0;
}