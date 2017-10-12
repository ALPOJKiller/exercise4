#include <iostream>
#include <vector>

using namespace std;

/**
 * 根据题目所述规则生成幻方
 * @param n 幻方阶数
 * @return 幻方
 */
vector <vector<unsigned>> magic(unsigned n) {
    // 先做一个空白的幻方
    std::vector <std::vector<unsigned>> ans;
    for (unsigned i = 0; i < n; ++i) {
        std::vector<unsigned> v(n, 0);
        ans.push_back(v);
    }
    // current_x 即当前位置的横坐标
    // current_y 即当前位置的纵坐标
    int current_x = 0, current_y = n / 2;
    // 要填的数是1到n*n
    for (unsigned i = 1; i <= n * n; ++i) {
        ans[current_x][current_y] = i;      // 填数
        if (i % n == 0) {                   // n的倍数
            ++current_x;                    // 下一行
            current_x %= n;                 // 防止上溢
        } else {
            --current_x;                    // 上一行
            if (current_x < 0) {            // 防止下溢
                current_x += n;
            }
            ++current_y;                    // 右移一格
            current_y %= n;                 // 防止上溢
        }
    }
    return ans;
}

/**
 * 打印矩阵
 * @tparam T 元素类型
 * @param mat 要打印的矩阵
 * @note 最后一个元素输出后不会有多余的空格
 */
template<typename T>
void print_matrix(vector <vector<T>> mat) {
    for (auto it_1 = mat.begin(); it_1 != mat.end(); ++it_1) {
        for (auto it_2 = it_1->begin(); it_2 != it_1->end(); it_2++) {
            if (it_2 != it_1->begin()) {
                cout << ' ';
            }
            cout << *it_2;
        }
        cout << endl;
    }
}

int main() {
    unsigned input_val;
    unsigned case_count = 0;
    vector<unsigned> input;
    while (cin >> input_val) {
        cout << "Case " << ++case_count << ":" << endl;
        print_matrix(magic(input_val));
    }
    return 0;
}
