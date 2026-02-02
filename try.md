# 一级标题
## 二级标题
### 三级标题
#### 四级标题
##### 五级标题
###### 六级标题
## 数学公式
$1+1=2$，$a^m+a^n=a^{m+n}$。
$$x ={-b \pm \sqrt{b^2-4ac}\over 2a} $$
$$\int \frac{1}{\sqrt{1-x^{2}}}\mathrm{d}x= \arcsin x +C $$
$$\frac{1}{n^{2}-1}= \frac{1}{2}\left( \frac{1}{n-1}-\frac{1}{n+1}\right) $$
$$\left.\begin{matrix} 
  a \subset \beta ,b \subset \beta ,a \cap b=P \\  
  a \parallel \partial ,b \parallel \partial  
\end{matrix}\right\}\Rightarrow \beta \parallel \alpha $$
正文     
__粗体正文__   
~~删除线~~     
*斜体正文*   
## 有序列表
- 1st
    - Ⅰ.
    - Ⅱ.
    - Ⅲ.
- 2nd
- 3rd
## 插入表格
| 阶段 |   年代 |电子元件  | 运算速度（每秒/次） |
| :----------- | :----------- | :----------- | :----------- |
| 第一代 |  $1946-1958$  |真空电子管  | 数千至数万 |
| 第二代 |  $1958-1964$  | 晶体管 | 几十万至几百万 |
| 第三代 |  $1964-1970$  | 中小规模集成电路 | 百万至几百万 |
| 第四代 |  $1970-2024$ |(超)大规模集成电路 | 几百万至千亿 | 

[行内式链接标题](http://www.luogu.org/)   
<http://www.luogu.org/>       

![插入图片](https://cdn.luogu.com.cn/upload/image_hosting/0gtzudx8.png)

## 代码块
`小段代码`     
```cpp
//大段代码
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll l,r;
int main(){
 	cin>>n>>m;
	cout<<(n+1)/2<<endl;
	for(int i=1;i<=m;i++){
		cin>>l>>r;
	}
	for(int i=1;i<=n/2;++i){
		cout<<i<<" "<<i+n/2<<endl;
	}
	if(n%2!=0){
		cout<<1<<" "<<n<<endl;
	}
	return 0;
}
```
>引用文字
