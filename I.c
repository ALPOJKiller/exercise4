#include <stdio.h>

/**
 * 公式法解问题约瑟夫环
 * @param n n个人
 * @param m 报到m出列
 * @return 最后剩下的人原来的编号（注意是从0开始的编号）
 * @note 推导过程：
 *          问题描述：n个人（编号0~(n-1))，从0开始报数，报到(m-1)的退出，剩下的人继续从0开始报数。求胜利者的编号
 *          第一个人(编号一定是m%n-1) 出列之后，剩下的n-1个人组成了一个新的约瑟夫环（以编号为k=m%n的人开始）
 *          重新将这些人编号为 0~(n-2)
 *          问题变成了n-1个人的约瑟夫环问题
 *          假设这个"n-1个人的约瑟夫环问题"的解为a
 *          那么容易发现，原来"n个人的约瑟夫环问题"的解就是(a+m)%n [可以举几个小规模的例子试一下]
 */
unsigned Josephus(unsigned n, unsigned m) {
    if (n == 1)
        return 0;
    return (Josephus(n - 1, m) + m) % n;
}

int main() {
    unsigned n, m;
    unsigned case_count = 0;
    while (scanf("%u %u", &n, &m) != EOF) {
        printf("Case %u: %u, %u, %u\n", ++case_count, n, m, Josephus(n, m) + 1);
    }
    return 0;
}
