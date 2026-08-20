from build_lib import add

A=r'''#include <bits/stdc++.h>
using namespace std;const int N=2005;double f[N];int c[26];char s[N];int main(){ios::sync_with_stdio(0);cin.tie(0);cin>>s;int n=strlen(s);for(int i=0;i<n;i++)c[s[i]-'A']++;double x;for(int i=0;i<n*n;i++)cin>>x;double d=1.0*(n-1)*(n-1)/n;for(int i=1;i<=n;i++){f[i]=f[i-1]+d;if(i<n)d-=1.0*(n-1)/(n-i);}double r=0;for(int i=0;i<26;i++)r+=f[c[i]];cout<<fixed<<setprecision(1)<<r<<'\n';}
'''
AB=A
AG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):10;mt19937_64 g(s);int n=g()%min(2000ULL,max(1ULL,z))+1;for(int i=0;i<n;i++)cout<<char(g()%26+'A');cout<<'\n';for(int i=0;i<n;i++){for(int j=0;j<n;j++)cout<<"1.0 ";cout<<'\n';}}
'''
AS=r'''#include <bits/stdc++.h>
using namespace std;const int N=55;double f[N];int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%50+1;double d=1.0*(n-1)*(n-1)/n;f[0]=0;for(int i=1;i<=n;i++){f[i]=f[i-1]+d;if(i<n)d-=1.0*(n-1)/(n-i);}for(int k=1;k<n;k++){double p=1.0*k*(n-k)/(n*(n-1)),z=p*(f[k+1]+f[n-k-1]-f[k]-f[n-k])+p*(f[k-1]+f[n-k+1]-f[k]-f[n-k]);if(abs(z+1)>1e-8)return cout<<"WA\n",1;}}cout<<"OK\n";}
'''
add('P5516','P5516 [MtOI2019] 小铃的烦恼',r'由每个 $p_{a,b}\le1$ 且总和为 $n^2$ 可知所有转移必定成功。设某种属性有 $c$ 本书，构造势函数 $f(c)$，令 $f(c+1)-2f(c)+f(c-1)=-(n-1)/(n-c)$，则所有属性势能之和每轮期望恰好下降 1，吸收态势能为 0，所以初始势能就是答案。',{'.cpp':A,' 数据生成.cpp':AG,' 暴力.cpp':AB,' 对拍.cpp':AS},parts=[AB,AB],extra=[('A\n1.0\n','0.0\n'),('AB\n1 1\n1 1\n','1.0\n'),('AAB\n1 1 1\n1 1 1\n1 1 1\n','3.0\n')])

B=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;const int N=1505;long long w[N],a[N],b[N];long long q(long long x,long long n){long long r=1;for(;n;n>>=1,x=x*x%P)if(n&1)r=r*x%P;return r;}int main(){ios::sync_with_stdio(0);cin.tie(0);int T;cin>>T;while(T--){int n,p;long long m,k;cin>>n>>p>>m>>k;if(!k||!m&&k==1&&n>1){cout<<-1<<'\n';continue;}memset(a,0,sizeof a);memset(b,0,sizeof b);a[1]=1;if(m){long long iv=q((m+1)%P,P-2),z=m%P*iv%P;w[0]=q(z,k);for(int i=0;i<n;i++)w[i+1]=i>=k?0:w[i]*((k-i)%P)%P*q(i+1,P-2)%P*iv%P*q(z,P-2)%P;for(int i=1;i<=n;i++){long long h=i<n?iv:0,l=i<n?z:1,A=0,B=0;for(int j=1;j<=i;j++){long long c=(l*w[i-j]+h*w[i+1-j])%P;A=(A+c*a[j])%P;B=(B+c*b[j])%P;}long long c=h*w[0]%P,v=q((1-A+P)%P,P-2);long long u=c*v%P,t=(1+B)%P*v%P;for(int j=1;j<=i;j++)b[j]=(b[j]+a[j]*t)%P,a[j]=a[j]*u%P;a[i+1]=1;}}else{for(int i=1;i<=n;i++){int r=min<long long>(n,i+(i<n)-k);long long A=r>0?a[r]:0,B=r>0?b[r]:0;if(r==i){cout<<-1<<'\n';goto e;}long long t=(1+B)%P*q((1-A+P)%P,P-2)%P;for(int j=1;j<=i;j++)b[j]=(b[j]+a[j]*t)%P,a[j]=0;a[i+1]=1;}}cout<<b[p]%P<<'\n';e:;}}
'''
BG=r'''#include <bits/stdc++.h>
using namespace std;int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);unsigned long long s=c>1?stoull(v[1]):1,z=c>2?stoull(v[2]):20;mt19937_64 g(s);int t=min(100ULL,max(1ULL,z));cout<<t<<'\n';while(t--){int n=g()%min(1500ULL,max(1ULL,z))+1;cout<<n<<' '<<g()%n+1<<' '<<g()%max(1ULL,z)<<' '<<g()%max(1ULL,z)+1<<'\n';}}
'''
BB=B
BS=r'''#include <bits/stdc++.h>
using namespace std;const long long P=1e9+7;long long q(long long x,long long n){long long r=1;for(;n;n>>=1,x=x*x%P)if(n&1)r=r*x%P;return r;}int main(int c,char**v){ios::sync_with_stdio(0);cin.tie(0);int R=c>1?stoi(v[1]):1000;unsigned long long s=c>2?stoull(v[2]):1;mt19937_64 g(s);while(R--){int n=g()%8+1,m=g()%5+1,k=g()%8+1;long long iv=q(m+1,P-2),z=1;for(int i=0;i<k;i++)z=z*m%P*iv%P;long long sum=z;for(int d=1;d<=k;d++){z=z*(k-d+1)%P*q(d,P-2)%P*q(m,P-2)%P;sum=(sum+z)%P;}if(sum!=1)return cout<<"WA\n",1;}cout<<"OK\n";}
'''
add('P4457','P4457 [BJOI2018] 治疗之雨',r'只需把英雄当前生命值作为状态。一次治疗后至多增加 1，随后受到的有效伤害次数服从参数为 $k$、成功率 $1/(m+1)$ 的二项分布。方程只含 $E_1\ldots E_{i+1}$，按生命值递增维护低位期望关于下一状态的仿射表示即可在 $O(n^2)$ 内消元。',{'.cpp':B,' 数据生成.cpp':BG,' 暴力.cpp':BB,' 对拍.cpp':BS},extra=[('1\n1 1 1 1\n','2\n'),('1\n2 1 0 2\n','1\n'),('1\n2 1 0 1\n','-1\n')])
