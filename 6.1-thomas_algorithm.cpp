#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// 追赶法求解三对角线性方程组
void thomasAlgorithm(const vector<double>& a, const vector<double>& b, const vector<double>& c, const vector<double>& d, vector<double>& x) {
    int n = a.size(); // 方程组的阶数

    // 初始化中间变量
    vector<double> u(n), l(n), y(n);

    // 前向消元
    u[0] = a[0];
    y[0] = d[0];
    for (int i = 1; i < n; i++) {
        l[i] = b[i] / u[i - 1];
        u[i] = a[i] - l[i] * c[i - 1];
        y[i] = d[i] - l[i] * y[i - 1];
    }

    // 回代
    x[n - 1] = y[n - 1] / u[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        x[i] = (y[i] - c[i] * x[i + 1]) / u[i];
    }
}

int main() {
    // 定义三对角矩阵的主对角线 a、下对角线 b、上对角线 c 和右端向量 d
    int n = 10; // 方程组的阶数
    vector<double> a(n, 2.0); // 主对角线
    vector<double> b(n, -1.0); // 下对角线
    vector<double> c(n, -1.0); // 上对角线
    vector<double> d(n, 0.0); // 右端向量
    vector<double> x(n); // 解向量

    // 设置右端向量 d
    d[0] = 1.0; // 第一个方程为 2x_1 - x_2 = 1
    for (int i = 1; i < n - 1; i++) {
        d[i] = 0.0; // 中间方程为 -x_{i-1} + 2x_i - x_{i+1} = 0
    }
    d[n - 1] = 0.0; // 最后一个方程为 -x_{n-1} + 2x_n = 0

    // 调用追赶法
    thomasAlgorithm(a, b, c, d, x);

    // 输出解向量
    cout << "追赶法的解（保留到小数点后第4位）：" << endl;
    for (int i = 0; i < n; i++) {
        cout << "x[" << i + 1 << "] = " << fixed << setprecision(4) << x[i] << endl;
    }

    return 0;
}

