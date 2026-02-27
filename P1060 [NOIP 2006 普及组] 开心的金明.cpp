#include<bits/stdc++.h>
using namespace std;
int w[51],v[51],dp[51419],m,n;
int main(){
    cin>>m>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>w[i];
        w[i]*=v[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=m;j>=v[i];j--){
            if(j>=v[i]){
                dp[j]=max(dp[j],dp[j-v[i]]+w[i]);
            }
        }
    }
    cout<<dp[m];
    return 0;
} 