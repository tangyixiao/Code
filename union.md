# C++中union用法详解

## 1. 什么是union？

**Union（联合体）** 是一种特殊的数据结构，它允许在**同一块内存空间中存储不同的数据类型**，但**同一时刻只能使用其中一种类型**。

### 直观比喻
想象一个储物柜，这个柜子可以存放：
- 一个篮球 🏀（较大物品）
- 或者一个网球 🎾（较小物品）
- 或者一副乒乓球拍 🏓（中等物品）

但**同一时间只能存放其中一种物品**，因为它们共享同一个柜子空间。

## 2. union的基本语法

```cpp
union MyUnion {
    int intValue;     // 整数（通常是4字节）
    float floatValue; // 浮点数（通常是4字节）
    char charArray[4];// 字符数组（4字节）
    // 所有成员共享同一块内存
};
```

## 3. 内存布局图

```
内存地址      intValue      floatValue     charArray
   ↓        ↓↓↓↓↓↓↓↓       ↓↓↓↓↓↓↓↓       ↓↓↓↓↓↓↓↓
   [0x1000] |   0-3   | = |   0-3   | = | 0 | 1 | 2 | 3 |
   [0x1004] 下一个union开始...
```

**关键点**：
- 所有成员从**同一内存地址开始**
- union的大小由**最大成员**决定
- 修改一个成员会影响其他成员的值

## 4. 基本使用示例

```cpp
#include <iostream>
using namespace std;

union Data {
    int i;
    float f;
    char str[20];
};

int main() {
    Data data;
    
    // 使用整数成员
    data.i = 42;
    cout << "整数模式: " << data.i << endl;
    // 此时访问data.f或data.str会得到无意义的值
    
    // 使用浮点数成员
    data.f = 3.14;
    cout << "浮点数模式: " << data.f << endl;
    // 之前存储的整数42被覆盖了
    
    // 使用字符数组成员
    strcpy(data.str, "Hello");
    cout << "字符串模式: " << data.str << endl;
    
    return 0;
}
```

## 5. 实际应用场景

### 场景1：节省内存空间
```cpp
union EmployeeID {
    int numericID;      // 数字ID（如：1001）
    char shortCode[4];  // 短代码（如："A12"）
    // 只需要存储其中一种，节省内存
};
```

### 场景2：数据类型的转换
```cpp
union FloatConverter {
    float floatValue;
    unsigned char bytes[4];
};

int main() {
    FloatConverter converter;
    converter.floatValue = 3.14f;
    
    // 查看浮点数在内存中的字节表示
    for(int i = 0; i < 4; i++) {
        cout << "字节 " << i << ": " << (int)converter.bytes[i] << endl;
    }
    return 0;
}
```

### 场景3：处理不同协议的数据包
```cpp
union NetworkPacket {
    struct {
        unsigned char type;
        unsigned char data[255];
    } raw;
    
    struct {
        unsigned char type;
        int x;
        int y;
    } position;
    
    struct {
        unsigned char type;
        char message[252];
    } text;
    // 根据type字段决定如何解释data
};
```

## 6. 带标签的union（更安全的使用方式）

为了避免混淆当前使用的是哪个成员，可以配合一个标签使用：

```cpp
struct TaggedData {
    enum Type { INT, FLOAT, STRING } type;
    
    union {
        int i;
        float f;
        char s[20];
    } value;
    
    // 根据type安全地获取值
    void print() {
        switch(type) {
            case INT: cout << "整数: " << value.i; break;
            case FLOAT: cout << "浮点数: " << value.f; break;
            case STRING: cout << "字符串: " << value.s; break;
        }
    }
};
```

## 7. C++11/17中的增强：匿名union和类成员union

### 匿名union（直接访问成员）
```cpp
struct Point {
    enum { CARTESIAN, POLAR } coordType;
    
    union {  // 匿名union
        struct { double x, y; };  // 笛卡尔坐标
        struct { double r, theta; }; // 极坐标
    };
    
    // 可以直接访问x,y或r,theta
};

Point p;
p.coordType = Point::CARTESIAN;
p.x = 10;  // 直接访问，不需要p.unionName.x
p.y = 20;
```

### C++17：带构造函数的union
```cpp
union U {
    std::string s;  // string有构造函数
    int n;
    
    U() : s("默认") {}  // 构造函数
    ~U() { s.~string(); } // 需要显式析构
};
```

## 8. 注意事项

### ⚠️ 重要限制：
1. **不能存储引用类型**
2. **不能包含虚函数**
3. **不能继承或被继承**
4. **C++11前不能包含有构造函数的类成员**

### 内存对齐问题
```cpp
union UnalignedExample {
    char c;      // 1字节
    int i;       // 4字节（可能要求4字节对齐）
    double d;    // 8字节
};
// 这个union的大小至少是8字节，因为需要对齐double
```

## 9. union vs struct 对比

| 特性 | union | struct |
|------|-------|--------|
| **内存使用** | 共享内存 | 每个成员有自己的内存 |
| **大小** | 最大成员的大小 | 所有成员大小之和（考虑对齐） |
| **同时访问** | 只能访问一个成员 | 可同时访问所有成员 |
| **用途** | 节省内存，类型转换 | 组合相关数据 |

## 10. 简单示例：颜色表示

```cpp
#include <iostream>
using namespace std;

union Color {
    unsigned int rgba;  // 32位整型颜色值
    
    struct {
        unsigned char b;  // 蓝色
        unsigned char g;  // 绿色
        unsigned char r;  // 红色
        unsigned char a;  // 透明度
    } components;
};

int main() {
    Color color;
    color.rgba = 0xFF336699;  // ARGB格式
    
    cout << hex;  // 十六进制输出
    cout << "整数值: 0x" << color.rgba << endl;
    cout << "红色分量: 0x" << (int)color.components.r << endl;
    cout << "绿色分量: 0x" << (int)color.components.g << endl;
    cout << "蓝色分量: 0x" << (int)color.components.b << endl;
    cout << "透明度: 0x" << (int)color.components.a << endl;
    
    return 0;
}
```

## 总结

**union的核心思想**：同一块内存，多种解释方式。

### 使用建议：
1. **明确当前使用的成员**，避免访问错误
2. 考虑使用**带标签的union**增加安全性
3. 主要用于**内存敏感**或需要**二进制兼容**的场景
4. 现代C++中，`std::variant` (C++17) 可能是更安全的选择

union就像是一个多功能工具，虽然强大但需要小心使用，确保你知道当前正在使用的是哪个"功能"！