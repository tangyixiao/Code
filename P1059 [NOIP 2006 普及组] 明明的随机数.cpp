#include<bits/stdc++.h>
using namespace std;
const int N=1e2+10;
set<int> s;
int n,a;
signed main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a);
        s.insert(a);
    }
    printf("%d\n",s.size());
    for(auto it:s){
        printf("%d ",it);
    }
    return 0;
}
