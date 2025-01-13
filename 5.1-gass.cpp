#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// 定义误差精度
const double EPSILON = 1e-4;

// 从方程组中解出x1的表达式
double calc_x1(double x2, double x3) {
    return (16 - 3 * x2) / 4;
}

// 从方程组中解出x2的表达式
double calc_x2(double x1, double x3) {
    return (20 - 3 * x1 + x3) / 4;
}

// 从方程组中解出x3的表达式
double calc_x3(double x2) {
    return (-12 + x2) / 4;
}

// 计算当前解与上一次解的最大误差
double calc_error(double x1, double x2, double x3, 
                 double prev_x1, double prev_x2, double prev_x3) {
    double diff1 = fabs(x1 - prev_x1);
    double diff2 = fabs(x2 - prev_x2);
    double diff3 = fabs(x3 - prev_x3);
    return max(max(diff1, diff2), diff3);
}

int main() {
    // 初始值设置
    double x1 = 0, x2 = 0, x3 = 0;
    double prev_x1, prev_x2, prev_x3;
    int iteration = 0;
    
    cout << fixed << setprecision(6);
    cout << "迭代过程：" << endl;
    cout << "迭代次数\tx1\t\tx2\t\tx3\t\t误差" << endl;
    
    do {
        // 保存上一次的值
        prev_x1 = x1;
        prev_x2 = x2;
        prev_x3 = x3;
        
        // 高斯-塞德尔迭代
        x1 = calc_x1(x2, x3);
        x2 = calc_x2(x1, x3);
        x3 = calc_x3(x2);
        
        // 计算误差
        double error = calc_error(x1, x2, x3, prev_x1, prev_x2, prev_x3);
        
        // 输出当前迭代结果
        cout << iteration << "\t\t" 
             << x1 << "\t" 
             << x2 << "\t" 
             << x3 << "\t" 
             << error << endl;
        
        iteration++;
        
        // 当误差小于指定精度时退出
        if (error < EPSILON) {
            break;
        }
        
    } while (true);
    
    cout << "\n最终结果：" << endl;
    cout << "x1 = " << x1 << endl;
    cout << "x2 = " << x2 << endl;
    cout << "x3 = " << x3 << endl;
    cout << "迭代次数：" << iteration << endl;
    
    return 0;
}

