#include <bits/stdc++.h>
using namespace std;
const int M = 5e3+5;
struct node {
    int x, y;
    bool f;  
}ques[M];
int n, m, idcnt,ans;
vector<int> fa,w;  
unordered_map<int, int> mp;
inline int gidx(int x) {
    if (mp.find(x) == mp.end()) {
        mp[x] = idcnt++;
    }
    return mp[x];
}
inline int find(int x) {
    if (fa[x] != x) {
        int rt = find(fa[x]);
        w[x] ^= w[fa[x]];  
        fa[x] = rt;
    }
    return fa[x];
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("bullet.in", "r", stdin);
    freopen("bullet.out", "w", stdout);
    cin >> n >> m;
    ans=m;
    for (int i = 0,x,y; i < m; i++) {
        string op;
        cin >> x >> y >> op;
        ques[i].x = x - 1,ques[i].y = y,ques[i].f = (op == "even");
        gidx(ques[i].x);
        gidx(ques[i].y);
    }

    int tiot = idcnt;
    fa.resize(tiot);
    w.resize(tiot, 0);
    for (int i = 0; i < tiot; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        int l = gidx(ques[i].x),r = gidx(ques[i].y),rl = find(l),rr = find(r);
        
        if (rl == rr) {
            if ((w[l] == w[r])^ ques[i].f) {
                ans = i;  
                break;
            }
        } else {
            int nw = w[l] ^ w[r] ^ (!ques[i].f);
            fa[rl] = rr;
            w[rl] = nw;
        }
    }
    
    cout << ans;
    return 0;
}

