#include <bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define int long long
using namespace std;
const int N = 1e6 + 5,logN=21;
struct node{
    int s,t,d;
}p[N];
int n, m, r[N],cnt,a[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("mushroom.in", "r", stdin);
    freopen("mushroom.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> r[i];
    }
    for (int i = 1; i <= m; i++) {
        cin>>p[i].d>>p[i].s>>p[i].t;
        for(int j=p[i].s;j<=p[i].t;j++){
            r[j]-=p[i].d;
            if(r[j]<0){
                cout<<"-1\n"<<i;
                exit(0);
            }
        }
    }
    cout<<"0";
    return 0;
}