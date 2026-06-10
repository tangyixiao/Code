#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;cin>>t;
    while(t--){
        int n,k;cin>>n>>k;
        vector<int> u(2*n+1,0);
        vector<pair<int,int>> c;
        for(int i=0;i<k;++i){
            int x,y;cin>>x>>y;
            u[x]=u[y]=1;
            c.push_back({x,y});
        }
        vector<int> f;
        for(int i=1;i<=2*n;++i)if(!u[i])f.push_back(i);
        int m=f.size();
        for(int i=0;i<m/2;++i)c.push_back({f[i],f[i+m/2]});
        int ans=0;
        for(int i=0;i<n;++i){
            int a=c[i].first,b=c[i].second;
            if(a>b)swap(a,b);
            for(int j=i+1;j<n;++j){
                int x=c[j].first,y=c[j].second;
                if(x>y)swap(x,y);
                bool f1=(a<x&&x<b),f2=(a<y&&y<b);
                if(f1!=f2)++ans;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}