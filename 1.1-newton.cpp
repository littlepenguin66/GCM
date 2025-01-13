#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

vector<vector<double> > calculateDiffQuotient(const vector<double>& x, const vector<double>& y) {
    int n = x.size();
    vector<vector<double> > f(n, vector<double>(n, 0));
    
    for(int i = 0; i < n; i++) {
        f[i][0] = y[i];
    }
    
    for(int j = 1; j < n; j++) {
        for(int i = 0; i < n - j; i++) {
            f[i][j] = (f[i + 1][j - 1] - f[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
    
    return f;
}

// 牛顿插值计算
double newtonInterpolation(const vector<double>& x, const vector<vector<double> >& f, double x_val) {
    int n = x.size();
    double result = f[0][0];
    double term = 1.0;
    
    for(int i = 1; i < n; i++) {
        term *= (x_val - x[i-1]);
        result += f[0][i] * term;
    }
    
    return result;
}

int main() {
    cout << "\n牛顿插值法求解 sin(x)" << endl;
    cout << string(50, '-') << endl << endl;
    
    // 已知数据点
    vector<double> x = {0.4, 0.5, 0.6, 0.7};
    vector<double> y = {0.38942, 0.47943, 0.56464, 0.64422};
    
    // 输出已知数据点
    cout << "已知数据点：" << endl;
    cout << setw(10) << left << "xi" << setw(15) << "sin(xi)" << endl;
    for(int i = 0; i < x.size(); i++) {
        cout << fixed << setprecision(5) 
             << setw(10) << left << x[i] 
             << setw(15) << y[i] << endl;
    }
    cout << endl << string(50, '-') << endl << endl;
    
    // 计算差商
    vector<vector<double> > f = calculateDiffQuotient(x, y);
    
    // 输出差商表
    cout << "差商表：" << endl;
    cout << setw(5) << left << "i"
         << setw(15) << "零阶差商"
         << setw(15) << "一阶差商"
         << setw(15) << "二阶差商"
         << setw(15) << "三阶差商" << endl;
         
    for(int i = 0; i < x.size(); i++) {
        cout << setw(5) << left << i;
        for(int j = 0; j < x.size() - i; j++) {
            cout << setw(15) << fixed << setprecision(5) << f[i][j];
        }
        cout << endl;
    }
    cout << endl << string(50, '-') << endl << endl;
    
    // 输出牛顿插值多项式
    cout << "牛顿插值多项式：" << endl;
    cout << "P(x) = " << fixed << setprecision(5) << f[0][0] << endl;
    cout << "     + " << f[0][1] << "(x - " << x[0] << ")" << endl;
    cout << "     + " << f[0][2] << "(x - " << x[0] << ")(x - " << x[1] << ")" << endl;
    cout << "     + " << f[0][3] << "(x - " << x[0] << ")(x - " << x[1] << ")(x - " << x[2] << ")" << endl;
    cout << endl << string(50, '-') << endl << endl;
    
    // 计算插值结果
    double x_val = 0.57891;
    double result = newtonInterpolation(x, f, x_val);
    
    // 输出计算结果
    cout << "计算结果：" << endl;
    cout << "x = " << x_val << " 时：" << endl;
    cout << "sin(" << x_val << ") ≈ " << fixed << setprecision(5) << result << endl;
    cout << endl << string(50, '-') << endl << endl;
    
    return 0;
}

