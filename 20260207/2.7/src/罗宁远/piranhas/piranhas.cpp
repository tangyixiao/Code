#include<bits/stdc++.h>
using namespace std;
const int N=25;
int t,n,a[N],k,d[N],flag,vis[N],ans=INT_MAX;
bool check(){
    for(int i=1;i<=k;i++)
        if(a[i]!=d[i])return false;
    return true;
}
void work(int wt){
    for(int i=wt;i<=n;i++){
        if(vis[i]>0){
            a[vis[i]]--;
            vis[i-1]=vis[i],vis[i]=0;
            break;
        }
    }
    for(int i=wt;i>=1;i--){
        if(vis[i]>0){
            a[vis[i]]++;
            vis[i+1]=vis[i],vis[i]=0;
            break;
        }
    }
}
void dfs(int now){
    // for(int i=1;i<=k;i++)
    //     cout<<a[i]<<" ";
    // cout<<'\n';
    if(check()){
        ans=min(ans,now);
        return ;
    }
    if(now>20)return ;
    int tmp[N]={};
    memcpy(tmp,a,sizeof tmp);
    for(int i=1;i<=n;i++){
        if(vis[i]>0||vis[i-1]>0||vis[i+1]>0)
            continue;
        // cout<<i<<'\n';
        work(i);
        dfs(now+1);
        memcpy(a,tmp,sizeof a);
    }
}
signed main(){
    freopen("piranhas.in","r",stdin);
    freopen("piranhas.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t>>t;
    while(t--){
        memset(vis,0,sizeof vis);
        cin>>n>>k,flag=1;
        ans=INT_MAX;
        for(int i=1;i<=k;i++)
            cin>>a[i],vis[a[i]]=i;
        for(int i=1;i<=k;i++){
            cin>>d[i];
            if(!vis[d[i]])vis[d[i]]=-1;
        }
        // for(int i=1;i<=n;i++)   
        //     cout<<vis[i]<<" ";
        // cout<<'\n';
        for(int i=1;i<=k;i++){
            for(int j=a[i];;){
                if(j==d[i])break;
                if(vis[j]&&j!=a[i]){
                    // cout<<i<<'\n';
                    flag=0;
                    break;
                }
                if(j>d[i])j--;
                else j++;
            }
            if(!flag){
                cout<<"impoBGible"<<'\n';
                break;
            }
        }
        if(!flag)continue;
        dfs(0);
        if(ans!=INT_MAX)cout<<ans<<'\n';
        else cout<<"impoBGible"<<'\n';
    }
    return 0;
}
/*
0 2
9 3
3 7 9
3 5 9
8 3
1 5 8
2 4 7

0 1
9 3
3 7 9
3 5 9
*/