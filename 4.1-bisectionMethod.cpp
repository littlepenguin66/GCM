#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

// 定义函数 f(x)
double f(double x) {
    return x * x - 2; // 示例函数：求根号 2 的近似值
}

// 二分法求根
void bisectionMethod(double a, double b, double tol) {
    // 检查初始区间是否满足 f(a) * f(b) < 0
    if (f(a) * f(b) >= 0) {
        cout << "初始区间 [a, b] 不满足 f(a) * f(b) < 0，无法使用二分法。" << endl;
        return;
    }

    // 输出表头
    cout << setw(10) << left << "迭代次数" 
         << setw(15) << "a" 
         << setw(15) << "b" 
         << setw(15) << "c" 
         << setw(15) << "f(c)" << endl;
    cout << string(60, '-') << endl;

    int iteration = 0; // 迭代次数
    double c; // 中点

    // 二分法循环
    while ((b - a) >= tol) {
        c = (a + b) / 2; // 计算中点
        double fc = f(c); // 计算 f(c)

        // 输出当前迭代结果
        cout << fixed << setprecision(5) 
             << setw(10) << left << iteration 
             << setw(15) << a 
             << setw(15) << b 
             << setw(15) << c 
             << setw(15) << fc << endl;

        // 如果 f(c) == 0，直接找到根
        if (fc == 0) {
            break;
        }

        // 更新区间
        if (f(a) * fc < 0) {
            b = c;
        } else {
            a = c;
        }

        iteration++; // 迭代次数增加
    }

    // 输出最终结果
    cout << string(60, '-') << endl;
    cout << "最终结果：" << endl;
    cout << "根 c ≈ " << fixed << setprecision(5) << c << endl;
    cout << "f(c) ≈ " << fixed << setprecision(5) << f(c) << endl;
}

int main() {
    // 初始区间和精度
    double a = 1.0; // 左端点
    double b = 2.0; // 右端点
    double tol = 1e-5; // 精度

    // 调用二分法
    bisectionMethod(a, b, tol);

    return 0;
}

