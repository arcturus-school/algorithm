#include "lab.h"

class Lecture {
public:
    int start = 0;
    int end   = 0;
};

int min_num_lecture_halls(std::vector<Lecture>& le) {
    if (le.size() == 0) return 0;

    auto compare = [](Lecture& l1, Lecture& l2) {
        return l1.start < l2.start;
    };

    std::sort(le.begin(), le.end(), compare);

    std::vector<int> halls;

    // 至少有一间报告厅
    halls.push_back(le[0].end);

    int idx;

    for (int i = 1; i < le.size(); i++) {
        // 找到最早结束的讲座
        auto end = std::min_element(halls.begin(), halls.end());

        if (le[i].start >= *end) {
            // 如果能开讲座就将结束时间更新
            idx = std::distance(halls.begin(), end);

            halls[idx] = le[i].end;
        }
        else {
            // 不能开讲座就多加一间报告厅
            halls.push_back(le[i].end);
        }
    }

    return halls.size();
}

// 使用优先队列优化
int min_num_lecture_halls_priority_queue(std::vector<Lecture>& le) {
    if (le.size() == 0) return 0;

    auto compare = [](Lecture& l1, Lecture& l2) {
        return l1.start < l2.start;
    };

    std::sort(le.begin(), le.end(), compare);

    // 小堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> halls;

    // 至少有一间报告厅
    halls.push(le[0].end);

    for (int i = 1; i < le.size(); i++) {
        if (le[i].start >= halls.top()) {
            // 如果能开讲座则弹出一个报告厅
            halls.pop();
        }

        // 无论如何都加一间报告厅
        halls.push(le[i].end);
    }

    return halls.size();
}

void lab12() {
    int n;

    std::cin >> n;

    std::vector<Lecture> lectures(n);

    for (int i = 0; i < lectures.size(); i++) {
        std::cin >> lectures[i].start >> lectures[i].end;
    }

    std::cout << min_num_lecture_halls(lectures);
}