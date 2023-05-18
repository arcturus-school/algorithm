#include "lab.h"

bool compare(std::pair<int, int>& p1, std::pair<int, int>& p2) {
    return p1.first < p2.first;
}

int calc_min_schedule(std::vector<int>& T, std::vector<int>& D) {
    // 同时记录索引
    std::vector<std::pair<int, int>> D_plus;

    for (int i = 0; i < D.size(); i++) {
        D_plus.push_back(std::make_pair(D[i], i));
    }

    // 对完成时间进行排序
    std::sort(D_plus.begin(), D_plus.end(), compare);

    int max = 0, s /* 当前服务开始时间 */ = 0, dt /* 延迟 */;

    // 计算各服务延迟
    for (int i = 0; i < D_plus.size(); i++) {
        dt = s + T[D_plus[i].second] - D_plus[i].first;

        if (dt > 0 && dt > max) {
            max = dt;
        }

        s += T[D_plus[i].second];
    }

    return max;
}

void lab10(){
    int n;

    std::cin >> n;

    std::vector<int> T(n), D(n);

    for (int i = 0; i < n; i++) {
        std::cin >> T[i] >> D[i];
    }

    std::cout << calc_min_schedule(T, D);
}