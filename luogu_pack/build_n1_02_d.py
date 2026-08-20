from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=1005,L=16;unsigned long long a[N][L],t[L];bool v[N],x[N];char s[N];bool g(int r,int p){return a[r][p>>6]>>(p&63)&1;}int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m,k=0,z=0;cin>>n>>m;for(int q=1;q<=m;q++){cin>>s;memset(t,0,sizeof t);for(int i=0;i<n;i++)if(s[i]=='1')t[i>>6]|=1ULL<<(i&63);bool r;cin>>r;for(int i=0;i<n;i++)if(t[i>>6]>>(i&63)&1){if(v[i]){for(int j=0;j<L;j++)t[j]^=a[i][j];r^=x[i];}else{v[i]=1;x[i]=r;memcpy(a[i],t,sizeof t);if(++k==n)z=q;break;}}}if(k<n)return cout<<"Cannot Determine\n",0;cout<<z<<'\n';for(int i=n-1;i>=0;i--)for(int j=i+1;j<n;j++)if(g(i,j))x[i]^=x[j];for(int i=0;i<n;i++)cout<<(x[i]?"?y7M#":"Earth")<<'\n';}
'''
AB=r'''#include <bits/stdc++.h>
using namespace std;const int N=22;unsigned long long a[N];bool b[N],x[N];char s[N];int main(){ios::sync_with_stdio(0);cin.tie(0);int n,m;cin>>n>>m;for(int i=0;i<m;i++){cin>>s>>b[i];for(int j=0;j<n;j++)if(s[j]=='1')a[i]|=1ULL<<j;}for(int k=1;k<=m;k++){int c=0;unsigned long long z=0;for(unsigned long long q=0;q<(1ULL<<n)&&c<2;q++){bool f=1;for(int i=0;i<k;i++)f&=__builtin_parityll(q&a[i])==b[i];if(f)c++,z=q;}if(c==1){cout<<k<<'\n';for(int i=0;i<n;i++)cout<<(z>>i&1?"?y7M#":"Earth")<<'\n';return 0;}}cout<<"Cannot Determine\n";}
'''
AG=r'''#include <bits/stdc++.h>
using namespace std;const int N=1005;bool x[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int n=g()%min(1000ULL,max(1ULL,z))+1,m=n+g()%min(1000,n+1);for(int i=0;i<n;i++)x[i]=g()&1;cout<<n<<' '<<m<<'\n';for(int i=0;i<m;i++){bool r=0;for(int j=0;j<n;j++){bool y=i<n?i==j:g()&1;cout<<y;r^=y&x[j];}cout<<' '<<r<<'\n';}}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=15;unsigned long long a[N],b[N];bool r[N],x[N],v[N],y[N];int main(int c,char**w){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(w[1]):1000;unsigned long long s=c>2?stoull(w[2]):1;mt19937_64 g(s);while(R--){int n=g()%10+1,m=n+g()%5,k=0,z=0;memset(v,0,sizeof v);for(int i=0;i<n;i++)x[i]=g()&1;for(int i=0;i<m;i++){a[i]=i<n?1ULL<<i:g()&((1ULL<<n)-1);r[i]=__builtin_parityll(a[i]&([&](){unsigned long long q=0;for(int j=0;j<n;j++)if(x[j])q|=1ULL<<j;return q;})());unsigned long long q=a[i];bool h=r[i];for(int j=0;j<n;j++)if(q>>j&1){if(v[j])q^=b[j],h^=y[j];else{v[j]=1;b[j]=q;y[j]=h;if(++k==n)z=i+1;break;}}}if(z!=n)return cout<<"WA\n",1;for(int i=n-1;i>=0;i--){for(int j=i+1;j<n;j++)if(b[i]>>j&1)y[i]^=y[j];if(y[i]!=x[i])return cout<<"WA\n",1;}}cout<<"OK\n";}
'''
add('P2447','P2447 [SDOI2010] 外星千足虫','按输入顺序把每条等式插入异或线性基。每个新主元使秩增加一，秩第一次达到 $N$ 时正好首次唯一确定；随后按主元从高到低回代。位集按 64 位整数分块，复杂度 $O(NM/64)$。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB,A,A],extra=[('1 1\n1 1\n','1\n?y7M#\n'),('1 1\n1 0\n','1\nEarth\n'),('2 1\n11 0\n','Cannot Determine\n')])
