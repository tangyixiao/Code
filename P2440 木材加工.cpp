#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10,inf=0x3f3f3f3f;
int n,k,a[N],l,r=inf,mid;
bool check(){
    int cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=(a[i]/mid);
    }
    return cnt>=k;
}
signed main(){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    while(l+1<r){
        mid=(l+r)>>1;
        if(check()){
            l=mid;
        }else{
            r=mid;
        }
    }
    printf("%d",l);
    return 0;
}