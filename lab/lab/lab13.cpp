#include "lab.h"

/**
*  @param count 组合数
*  @param num   括号数
*  @param len   当前组合长度
*  @param left  左括号数
*  @param right 右括号数
*/
void backtrack(int& count, int& num, int len, int left, int right) {
    if (len == num * 2) {
        count++;
        return;
    }

    // 左括号小于括号对数, 可以加入一个左括号
    if (left < num) {
        backtrack(count, num, len + 1, left + 1, right);
    }

    // 右括号要求小于左括号数
    if (right < left) {
        backtrack(count, num, len + 1, left, right + 1);
    }
}

int valid_bracket_num(int num) {
    int count = 0;

    backtrack(count, num, 0, 0, 0);

    return count;
}

void lab13() {
    int num;

    std::cin >> num;

    std::cout << valid_bracket_num(num);
}