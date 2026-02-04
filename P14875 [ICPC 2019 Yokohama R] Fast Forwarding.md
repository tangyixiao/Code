# P14875 [ICPC 2019 Yokohama R] Fast Forwarding

## 题目描述

Anderson 先生经常租借他最喜欢的经典电影录像带。由于观看了这些电影很多次，他已经学会了所有这些电影中他最喜欢场景的精确开始时间。现在，他想找出如何在他录像机上快速倒带到他想观看的场景。

当按下 [播放] 按钮时，电影以正常播放速度开始播放。录像机有两个按钮可以控制播放速度：[3x] 按钮使速度变为三倍，而 [1/3x] 按钮将速度降低到三分之一。然而，这些速度控制按钮在按下时并不会立即生效。从播放开始后恰好一秒起，以及之后的每一秒，都会检查这些速度控制按钮的状态。如果在检查的时刻 [3x] 按钮被按下，播放速度将变为当前速度的三倍。如果 [1/3x] 按钮被按下，播放速度将变为当前速度的三分之一，除非它已经是正常速度。

例如，假设他最喜欢的场景从电影开始后 $19$ 秒处开始。如果在播放开始后一秒和两秒时 [3x] 按钮被按下，在三秒和五秒时 [1/3x] 按钮被按下，那么他可以在播放开始五秒后以正常速度观看想要的场景，如下图所示。

:::align{center}
![](https://cdn.luogu.com.cn/upload/image_hosting/1ba7i53k.png)
:::

你的任务是计算从播放开始到目标场景开始之间可能的最短时间周期。当然，场景的播放必须以正常速度进行。

## 输入格式

输入包含单个测试用例，格式如下。

$$t$$

给定的单个整数 $t$ （$0 \le t < 2^{50}$）是目标场景的开始时间。

## 输出格式

输出一个整数，表示他能以正常速度开始观看目标场景之前的最小可能时间（以秒为单位）。

## 输入输出样例 #1

### 输入 #1

```
19
```

### 输出 #1

```
5
```

## 输入输出样例 #2

### 输入 #2

```
13
```

### 输出 #2

```
5
```

## 输入输出样例 #3

### 输入 #3

```
123456789098765
```

### 输出 #3

```
85
```

## 输入输出样例 #4

### 输入 #4

```
51
```

### 输出 #4

```
11
```

## 输入输出样例 #5

### 输入 #5

```
0
```

### 输出 #5

```
0
```

## 输入输出样例 #6

### 输入 #6

```
3
```

### 输出 #6

```
3
```

## 输入输出样例 #7

### 输入 #7

```
4
```

### 输出 #7

```
2
```

---

# P14875 [ICPC 2019 Yokohama R] Fast Forwarding

## 题目描述

Mr. Anderson frequently rents video tapes of his favorite classic films. Watching the films so many times, he has learned the precise start times of his favorite scenes in all such films. He now wants to find how to wind the tape to watch his favorite scene as quickly as possible on his video player.

When the [play] button is pressed, the film starts at the normal playback speed. The video player has two buttons to control the playback speed: The [3x] button triples the speed, while the [1/3x] button reduces the speed to one third. These speed control buttons, however, do not take effect on the instance they are pressed. Exactly one second after playback starts and every second thereafter, the states of these speed control buttons are checked. If the [3x] button is pressed on the timing of the check, the playback speed becomes three times the current speed. If the [1/3x] button is pressed, the playback speed becomes one third of the current speed, unless it is already the normal speed.

For instance, assume that his favorite scene starts at $19$ seconds from the start of the film. When the [3x] button is on at one second and at two seconds after the playback starts, and the [1/3x] button is on at three seconds and at five seconds after the start, the desired scene can be watched in the normal speed five seconds after starting the playback, as depicted in the following chart.

:::align{center}
![](https://cdn.luogu.com.cn/upload/image_hosting/1ba7i53k.png)
:::

Your task is to compute the shortest possible time period after the playback starts until the desired scene starts. The playback of the scene, of course, should be in the normal speed.

## 输入格式

The input consists of a single test case of the following format.

$$t$$

The given single integer $t$ ($0 \le t < 2^{50}$) is the start time of the target scene.

## 输出格式

Print an integer that is the minimum possible time in seconds before he can start watching the target scene in the normal speed.

## 输入输出样例 #1

### 输入 #1

```
19
```

### 输出 #1

```
5
```

## 输入输出样例 #2

### 输入 #2

```
13
```

### 输出 #2

```
5
```

## 输入输出样例 #3

### 输入 #3

```
123456789098765
```

### 输出 #3

```
85
```

## 输入输出样例 #4

### 输入 #4

```
51
```

### 输出 #4

```
11
```

## 输入输出样例 #5

### 输入 #5

```
0
```

### 输出 #5

```
0
```

## 输入输出样例 #6

### 输入 #6

```
3
```

### 输出 #6

```
3
```

## 输入输出样例 #7

### 输入 #7

```
4
```

### 输出 #7

```
2
```