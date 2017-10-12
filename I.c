#include <stdio.h>

/**
 * 约瑟夫环公式
 * @param n n个人
 * @param m 报到m出列
 * @return 最后剩下的人原来的编号（注意是从0开始的编号）
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
