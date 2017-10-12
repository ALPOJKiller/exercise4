#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/**
 * 在vector内二分查找
 * @tparam T 元素类型
 * @param v 要查找的vector
 * @param x 要查找的值
 * @return 查找到的索引，未查找到返回-1
 */
template<typename T>
int binary_find(const vector <T> &v, T x) {
    int left = 0;                           // 左端点索引
    int right = v.size() - 1;               // 右端点索引
    while (left <= right) {
        // 好吧，一般情况下下面这句写(left + right) / 2就可以了
        // 然而，在特定情况下(left + right) / 2是不能得到正确的结果的（考虑一下溢出问题）
        // 这么写是为了致敬Java标准库曾经的一个bug
        // 见 http://www.importnew.com/26482.html
        // 没多少人能写对二分查找
        // 甚至没多少人能正确地取两个整数的平均数
        // "Can't even compute average of two ints" is pretty embarrassing.
        // TAT
        int middle = (left >> 1) + (right >> 1) + ((left & 1) & (right & 1));
        if (v[middle] > x) {
            // 要找的值在数组左侧
            right = middle - 1;
        } else if (v[middle] < x) {
            // 要找的值在数组左侧
            left = middle + 1;
        } else { // v[middle] == x
            // 找到了
            return middle;
        }
    }
    // 没找到
    return -1;
}

int main() {
    string s;
    int value_to_find;
    unsigned case_count = 0;
    // 读要找的值
    while (cin >> value_to_find) {
        string s;
        // 清掉要找的值的后面的换行
        getline(cin, s);
        // 获取要找的值
        getline(cin, s);
        vector<int> v;
        if (s != "") {
            istringstream ss(s);
            int value;
            while (ss >> value) {
                v.push_back(value);
            }
            int find_result = binary_find(v, value_to_find);
            cout << "Case " << ++case_count << ": " << value_to_find << ", " << find_result << endl;
        }
    }
    return 0;
}
