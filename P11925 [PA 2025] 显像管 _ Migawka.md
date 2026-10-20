# P11925 [PA 2025] 显像管 / Migawka

## 题目背景

PA 2025 R5C.

可以用 PHP 语言提交答案，也可以提交答案生成器。

## 题目描述

**这是一道提交答案题。**

有一台老旧的黑白电视机，屏幕尺寸为 $100 \times 100$ 像素。每个像素可以是亮着的，也可以是熄灭的。然而，这台电视机有缺陷的，显示的图像一般不会保持太久。

称一个 $2 \times 2$ 的像素块是**错误的**，当且仅当其**只有**（主/副）对角线上的像素是亮的。电视机每秒将**在至少一个**错误块中的像素状态反转（亮变为灭，灭变为亮）。

![](https://cdn.luogu.com.cn/upload/image_hosting/1usrl3xs.png?x-oss-process=image/resize,m_lfit,h_200)

例如，考虑一个 $4 \times 4$ 的电视机屏幕，初始时各像素状态为下图左 $1$ 所示。下图展示了电视机在未来几秒钟的屏幕状态变化。

![](https://cdn.luogu.com.cn/upload/image_hosting/wcgmxgup.png?x-oss-process=image/resize,m_lfit,h_200)

从图中可以看出，第 $3$ 秒的屏幕画面与第 $1$ 秒相同，所以有 $3$ 种不同的画面。

构造初始的像素状态，最大化它能生成的不同画面的数量。（在刚才的例子中，生成了 $3$ 种不同画面）。

## 输入格式

没有输入。

## 输出格式

输出 $100$ 行，第 $i$ 行一个长度为 $100$ 的 $\texttt{01}$ 串 $s_{i,j}$，表示电视机的初始画面（$\texttt{1}$ 代表像素点亮，$\texttt{0}$ 代表像素熄灭）。

## 说明/提示

### 计分方式

设初始画面生成了 $x$ 种不同的画面。

令 $i$ 为最大的非负整数，满足 $(10\cdot i-1)^2\le x$，则得分为 $\min(100,10\cdot i)$。

### 提示


**光敏性癫痫警告：开发者已尽力确保可视化对癫痫患者是安全的，但请小心使用。**

我们在附件中提供了可视化工具 $\boldsymbol{visualise.py}$。

这是一个 Python 脚本，依赖于 `matplotlib` 和 `numpy` 库（请自行搜索如何安装，可能需要更换镜像源）。

使用以下命令启动可视化工具：

- Linux / MacOS：

	```bash
	python3 visualise.py < mig.txt
	```
- Windows cmd：
	```bash
	py visualise.py < mig.txt
    ```

压缩包还包含了一个示例文件 $\boldsymbol{mig.txt}$。

你可以根据需要自行修改可视化工具。