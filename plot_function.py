import numpy as np
import matplotlib.pyplot as plt
import sympy as sp
import matplotlib

matplotlib.use('TkAgg')  # 强制使用 TkAgg 后端

# 读取函数数据
with open("function_data.txt", "r") as f:
    func_str = f.readline().strip()
    x_min = float(f.readline().strip())
    x_max = float(f.readline().strip())
    num_points = int(f.readline().strip())

print(f"Function: {func_str}, x_min: {x_min}, x_max: {x_max}, num_points: {num_points}")

try:
    # 解析数学表达式
    x = sp.symbols("x")
    expr = sp.sympify(func_str)  # 将字符串转换为数学表达式
    f_lambdified = sp.lambdify(x, expr, "numpy")

    # 生成数据
    X = np.linspace(x_min, x_max, num_points)
    Y = f_lambdified(X)

    print(f"Generated data: X = {X[:5]} ... Y = {Y[:5]} ...")  # 打印前几个数据点进行验证

    # 绘制图像
    plt.figure(figsize=(8, 5))
    plt.plot(X, Y, label=f"y = {func_str}", color="b")
    plt.axhline(0, color="gray", linewidth=0.5)
    plt.axvline(0, color="gray", linewidth=0.5)
    plt.grid()
    plt.legend()
    plt.xlabel("x")
    plt.ylabel("y")
    plt.title(f"Plot of y = {func_str}")
    plt.savefig("function_plot.png")
    plt.show()
except Exception as e:
    #print(f"Error: {e}")
    print(f"不支持该类型的函数")
    # 删除生成的图像文件（如果存在）
    import os
    if os.path.exists("function_plot.png"):
        os.remove("function_plot.png")
    exit(1)  # 返回错误代码
