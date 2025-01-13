#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

// 复化梯形求积公式
double compositeTrapezoidalRule(const vector<double>& x, const vector<double>& fx) {
    int n = x.size() - 1; // 区间数
    double h = x[1] - x[0]; // 步长
    double T = 0.0; // 积分值

    // 输出计算过程
    cout << "详细计算过程：" << endl;
    cout << setw(10) << left << "区间" 
         << setw(15) << "x_k" 
         << setw(15) << "x_{k+1}" 
         << setw(15) << "f(x_k)" 
         << setw(15) << "f(x_{k+1})" 
         << setw(15) << "面积" << endl;
    cout << string(80, '-') << endl;

    // 计算每个小区间的梯形面积
    for (int k = 0; k < n; k++) {
        double x_k = x[k];
        double x_k1 = x[k + 1];
        double f_k = fx[k];
        double f_k1 = fx[k + 1];
        double area = (h / 2) * (f_k + f_k1); // 当前区间的梯形面积

        // 输出当前区间的计算过程
        cout << fixed << setprecision(5) 
             << setw(10) << left << k + 1 
             << setw(15) << x_k 
             << setw(15) << x_k1 
             << setw(15) << f_k 
             << setw(15) << f_k1 
             << setw(15) << area << endl;

        T += area; // 累加面积
    }

    cout << string(80, '-') << endl;
    return T;
}

int main() {
    // 已知数据点
    vector<double> x = {0.00, 0.25, 0.50, 0.75, 1.00};
    vector<double> fx = {1.00000, 1.65534, 1.55152, 1.06666, 0.72159};

    // 输出已知数据点
    cout << "已知数据点：" << endl;
    cout << setw(10) << left << "x" << setw(15) << "f(x)" << endl;
    for (int i = 0; i < x.size(); i++) {
        cout << fixed << setprecision(5) 
             << setw(10) << left << x[i] 
             << setw(15) << fx[i] << endl;
    }
    cout << endl << string(50, '-') << endl << endl;

    // 计算积分值
    double integral = compositeTrapezoidalRule(x, fx);

    // 输出结果
    cout << "积分结果：" << endl;
    cout << "I = ∫₀¹ f(x) dx ≈ " << fixed << setprecision(5) << integral << endl;
    cout << endl << string(50, '-') << endl << endl;

    return 0;
}

