#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

/**
 * 打印一个优先队列中前 @arg n 个元素
 * @tparam T 元素的类型
 * @param q 要打印的优先队列
 * @param n 要打印的元素个数
 * @note 最后一个元素输出后不会有多余的空格
 */
template<typename T>
void print_first_n(priority_queue <T> q, unsigned n) {
    for (unsigned i = 0; i < n; i++) {
        if (i != 0)
            cout << ", ";
        cout << q.top();
        q.pop();
    }
    cout << endl;
}

int main() {
    // 构建有10个0的优先队列
    vector<int> v{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // 规定大的元素放在优先队列的头上
    // 没错，大的元素用 less<int>()
    // STL就是这样规定的……
    priority_queue<int> q(less<int>(), v);

    string s;
    unsigned case_count = 0;
    while (getline(cin, s)) {
        if (s != "") {
            istringstream ss(s);
            int value;
            while (ss >> value) {
                q.push(value);
            }
        }
        cout << "Case " << ++case_count << ": ";
        print_first_n(q, 10);
    }
    return 0;
}
