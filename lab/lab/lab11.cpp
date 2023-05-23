#include "lab.h"

class Point {
public:
    int start = 0;
    int end   = 0;
};

int calc_min_num_bows_arrows(std::vector<Point>& p) {
    if (p.size() == 0) return 0;

    auto compare = [](Point& p1, Point& p2) {
        return p1.start < p2.start;
    };

    std::sort(p.begin(), p.end(), compare);

    // 至少有一个球, 因此至少要一个弓箭
    int num = 1;

    int max = p[0].end;

    for (int i = 1; i < p.size(); i++) {
        // 没有重叠部分, 需增加一支弓箭
        if (p[i].start > max) {
            num++;
            max = p[i].end;
        }
    }

    return num;
}

void lab11(){
    int n;

    std::cin >> n;

    std::vector<Point> p(n);

    for (int i = 0; i < n; i++) {
        std::cin >> p[i].start >> p[i].end;
    }

    std::cout << calc_min_num_bows_arrows(p);
}