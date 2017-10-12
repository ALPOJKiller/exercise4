#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <numeric>

using namespace std;

/**
 * 求矩阵的和
 * @tparam T 矩阵内元素的类型
 * @param mat 要求和的矩阵
 * @return 求出的和
 */
template<typename T>
T matrix_sum(std::vector <std::vector<T>> mat) {
    T ans = 0;
    //每行求和，加入ans中
    for (auto &v:mat) {
        ans += accumulate(v.begin(), v.end(), static_cast<T>(0));
    }
    return ans;
}

int main() {
    string s;
    vector <vector<double>> mat;
    unsigned case_count = 0;
    while (getline(cin, s)) {
        // 获得的是空字符串，说明这是个空行
        if (s == "") {
            //输出
            cout << "Case " << ++case_count << ": " << mat.size() << ", " << mat.front().size() << ", "
                 << matrix_sum(mat) << endl;
            mat.clear();    // 清除矩阵内元素，等待下个矩阵输入
        } else {
            // 获取输入的浮点数
            istringstream ss(s);
            double d;
            std::vector<double> v;
            while (ss >> d) {
                v.push_back(d);
            }
            // 将这一行加入矩阵中
            mat.push_back(v);
        }
    }
    // 文件最后一行没有空行，故碰到EOF后，最后一个矩阵仍然在mat中没有被输出
    // 此时需要手动再次输出
    cout << "Case " << ++case_count << ": " << mat.size() << ", " << mat.front().size() << ", " << matrix_sum(mat)
         << endl;
    return 0;
}
