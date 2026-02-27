#include <bits/stdc++.h>
using namespace std;
int n,m,parent[100010],u,v,w;
inline int find(int x){
    if(x==parent[x]) return x;
    return parent[x]=find(parent[x]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++) parent[i]=i;
    for(int i=1;i<=m;i++){
        cin>>w>>u>>v;
        if(w==1){
            parent[find(u)]=find(v);
        }
        else{
            if(find(u)==find(v))
                printf("Y\n");
            else
                printf("N\n");
        }
    }
    return 0;
}