#include<bits/stdc++.h>
#define int long long
using namespace std;
int T,n,kl,cnt;
signed main(){
    scanf("%lld",&T);
    while(T--){
        int i;
        scanf("%lld",&n);
        kl=n;
        for(i=0;kl!=0;i++){
            kl/=10;
        }
        kl=n;
        for(;kl!=0;){
            cnt+=pow((kl%10),i);
            kl/=10;
        }
        if(cnt==n) printf("T\n");
        else printf("F\n");
        cnt=0;
    }
    return 0;
}