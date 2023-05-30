#include "lab.h"

// 判断 row 行 col 列放置皇后是否合法
bool judgeLegalPut(std::vector<int>& row, int r, int c) {
    for (int i = r - 1; i >= 0; i--) {
        // 计算斜率
        if (r - i == std::abs(c - row[i])) {
            // 当前位置与之前的皇后处于同一斜线上
            return false;
        }
    }

    return true;
}

void queen(int& count, std::vector<bool>& col, std::vector<int>& row, int r) {
    int n = col.size();

    if (r >= n) {
        count++;
        return;
    }

    for (int i = 0; i < n; i++) {
        if (col[i]) continue; // 第 r 行第 i 列位置被使用过

        // 判断当前位置是否合法
        if (judgeLegalPut(row, r, i)) {
            col[i] = true; // 第 i 列标记使用过
            row[r] = i;

            queen(count, col, row, r + 1 /* 下一行 */);

            // 撤销之前的状态
            col[i] = false;
            row[r] = 0;
        }
    }
}

void lab14() {
    int num, count /* 方案数 */ = 0;

    std::cin >> num;

    // 记录某一行第几列存放皇后
    std::vector<bool> col(num, false);

    // 存储每行皇后存放的列
    std::vector<int> row(num, 0);

    queen(count, col, row, 0);
    
    std::cout << count;
}