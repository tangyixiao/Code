# 导入库
import matplotlib.pyplot as plt
import numpy as np
# 生成数据
x = np.linspace(0, 10, 100)
y = np.sin(x)
# 绘制图表
plt.plot(x, y)
plt.title("正弦曲线")
plt.show()