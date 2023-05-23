#include "lab.h"

int max_valid_bracket_num(std::string& str) {
    int len = str.length();

    std::vector<int>dp(len + 1, 0);

    int max = 0;

    for (int i = 2, j = 1; j < len; i++, j++) {
        // [ 结尾的, 肯定不合法
        if (str[j] == ']') {
            // ...[] 的情况
            if (str[j - 1] == '[') {
                dp[i] = dp[i - 2] + 2;
            }
            else if (str[j - dp[i - 1] - 1] == '[') {
                // ...]] 的情况, 往前 dp[i-1] + 1 个单位查看
                // 若为 ...[...]] 则长度加 2
                dp[i] = dp[i - 1] + 2;

                // 考虑到可能有 ...[..][...]] 的情况
                // 因此除了 [...]] 的最大长度
                // 还要加上 [..] 的最大长度
                if (j - dp[i - 1] >= 2) {
                    dp[i] += dp[i - dp[i - 1] - 2];
                }
            }
        }

        max = max > dp[i] ? max : dp[i];
    }

    return max;
}

void lab07() {
    std::string input;

    std::cin >> input;

    std::cout << max_valid_bracket_num(input);
}