#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5000005;       
const int MAXB = 20000010;      

int a[MAXN * 2];                
int b[MAXB];                    

int main() {
    freopen("tower.in", "r", stdin);
    freopen("tower.out", "w", stdout);
    
    int T;
    scanf("%d", &T);
    while (T--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int nn = n * 2;         
        int k = nn * 2;         
        
        for (int i = 1; i <= nn; i++) {
            scanf("%d", &a[i]);
            b[i] = a[i];                
            b[i + nn] = a[i] - m;       
        }
        
         
        sort(b + 1, b + k + 1);
        
         
        int l = nn + 1, r = nn;         
         
        while (r - l + 1 < nn) {
            l--; r++;                    
             
            if (b[l] + b[r] < 0) {
                l++; r++;
            }
        }
        
         
        int ans = 0;
        while (l <= r) {
            ans = max(ans, b[l] + b[r]);
            l++; r--;
        }
        
        printf("%d\n", ans);
    }
    
    return 0;
}