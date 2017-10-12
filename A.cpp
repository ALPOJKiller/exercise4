#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

const double EPSILON = 1E-8;
using namespace std;

/**
 * 输出一个vector内的所有元素
 * @tparam T vector的类型
 * @param v 要输出的vector
 * @note 最后一个元素输出后不会有多余的空格
 */
template<typename T>
void print_vector(const vector <T> &v) {
    cout << v.front();
    for (auto it = v.begin() + 1; it != v.end(); ++it) {
        cout << ", " << *it;
    }
    cout << endl;
}

/**
 * 排名次
 * @param v 要排名的序列，要求已经排好序，pair中第一个值为原序列中的序号，第二个值是元素的值
 * @return 对应的排名构成的vector
 */
std::vector<unsigned> rank_(const vector <pair<unsigned, double>> &v) {
    std::vector<unsigned> ans(v.size());
    unsigned last_index = 1;                    // 记录下次应该输出的排名
    double last_num = v.front().second;         // 记录上次输出排名时的成绩
    for (unsigned i = 0; i < v.size(); ++i) {
        // 如果和上次的成绩不相等
        // 注意浮点数判定相等不宜直接用 == / != 号
        if (abs(v[i].second - last_num) > EPSILON) {
            // 需要更新下次输出的排名和上次输出排名时的成绩
            last_index = i + 1;
            last_num = v[i].second;
        }
        // 如果和上次的成绩不相等，则直接使用last_index中的排名数据
        // 输出排名
        ans[v[i].first] = last_index;
    }
    return ans;
}

int main() {
    string s;
    unsigned case_count = 0;
    while (getline(cin, s)) {
        if (s != "") {
            istringstream ss(s);
            double d;
            vector <pair<unsigned, double>> v;
            while (ss >> d) {
                unsigned index = v.size();
                v.push_back(make_pair(index, d));
            }
            sort(v.begin(), v.end(), [](pair<unsigned, double> a, pair<unsigned, double> b) {
                return a.second > b.second;
            });
            cout << "Case " << ++case_count << ':' << endl;
            print_vector(rank_(v));
        }
    }
    return 0;
}
