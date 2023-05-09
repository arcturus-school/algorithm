#include "lab.h"

int max_valid_bracket_num(std::string& str) {
    int len = str.length();

    std::vector<int>dp(len + 1, 0);

    int max = 0;

    for (int i = 2, j = 1; j < len; i++, j++) {
        // [ ��β��, �϶����Ϸ�
        if (str[j] == ']') {
            // ...[] �����
            if (str[j - 1] == '[') {
                dp[i] = dp[i - 2] + 2;
            }
            else if (str[j - dp[i - 1] - 1] == '[') {
                // ...]] �����, ��ǰ dp[i-1] + 1 ����λ�鿴
                // ��Ϊ ...[...]] �򳤶ȼ� 2
                dp[i] = dp[i - 1] + 2;

                // ���ǵ������� ...[..][...]] �����
                // ��˳��� [...]] ����󳤶�
                // ��Ҫ���� [..] ����󳤶�
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