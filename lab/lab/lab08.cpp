#include "lab.h"

// 贪心算法
int min_trans_num_greedy(int n, std::vector<int>& dis) {
    int cur = 0;  // 当前位置
    int jump = 1; // 传送次数(至少传送 1 次)

    while (true) {
        if (cur + dis[cur] >= n) {
            return jump;
        }

        int max = cur + 1;

        // 在本次能传送到的位置内, 搜索再传送一次能到的最远位置
        for (int i = cur + 2; i <= cur + dis[cur]; i++) {
            if (i + dis[i] > max + dis[max]) {
                max = i;
            }
        }

        cur = max;
        jump++;
    }   
}

// 动态规划
int min_trans_num_dp(int n, std::vector<int>& dis) {
    std::vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
        if (i + dis[i] >= n) {
            return dp[i] + 1;
        }

        for (int j = 1; j <= dis[i]; j++) {
            if (dp[i] + 1 < dp[i + j] || dp[i + j] == 0) {
                dp[i + j] = dp[i] + 1;
            }
        }
    }

    return dp[n - 1];
}

void lab08() {
    int n;

    // 目的地距离
    std::cin >> n;

    // 每站最远传输距离
    std::vector<int> dis(n);
    for (int i = 0; i < n; i++) {
        std::cin >> dis[i];
    }

    // std::cout << min_trans_num_greedy(n, dis);
    std::cout << min_trans_num_dp(n, dis);
}