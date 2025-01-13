#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>

using namespace std;

// 定义微分方程 y' = f(x, y)
double f(double x, double y) {
    return -0.9 / (1 + 2 * x) * y;
}

// 改进欧拉法
void improvedEuler(double x0, double y0, double h, double x_end) {
    double x = x0;
    double y = y0;

    // 输出表头
    cout << setw(10) << left << "x" 
         << setw(15) << "改进欧拉法 y" 
         << setw(15) << "精确解 y_exact" 
         << setw(15) << "误差 |y - y_exact|" << endl;
    cout << string(55, '-') << endl;

    // 循环计算
    while (x <= x_end) {
        // 改进欧拉法计算
        double y_predict = y + h * f(x, y); // 预测
        double y_correct = y + (h / 2) * (f(x, y) + f(x + h, y_predict)); // 校正

        // 精确解
        double y_exact = 1 / pow(1 + 2 * x, 0.45);

        // 输出结果
        cout << fixed << setprecision(5) 
             << setw(10) << left << x 
             << setw(15) << y_correct 
             << setw(15) << y_exact 
             << setw(15) << abs(y_correct - y_exact) << endl;

        // 更新 x 和 y
        y = y_correct;
        x += h;
    }
}

int main() {
    // 初始条件
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1; // 步长
    double x_end = 1.0; // 终点

    // 调用改进欧拉法
    improvedEuler(x0, y0, h, x_end);

    return 0;
}

