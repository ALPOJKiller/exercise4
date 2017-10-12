#include <iostream>
#include <map>

using namespace std;
// 缓存计算结果
map<unsigned, map<unsigned, unsigned> > buffer;

/**
 * 计算组合数
 * @param m 从 @arg m 个元素中
 * @param n 选取 @arg n 个
 * @return 计算结果
 */
unsigned C(unsigned m, unsigned n) {
    // 要选的比能选的还多
    if (n > m) {
        return 0;
    }
    // 显然为1的情况
    if (m < 2 || n == 0) {
        return 1;
    }
    // 缓存中没有，根据数学公式 C(m,n) = C(m - 1, n) + C(m - 1, n - 1) 计算，并加入缓存
    if (buffer.find(m) == buffer.end() || buffer[m].find(n) == buffer[m].end())
        buffer[m][n] = C(m - 1, n) + C(m - 1, n - 1);
    return buffer[m][n];
}

int main() {
    unsigned m, n;
    unsigned case_count = 0;
    while (cin >> m >> n) {
        cout << "Case " << ++case_count << ":" << endl
             << C(m, n) << endl;
    }
    return 0;
}
