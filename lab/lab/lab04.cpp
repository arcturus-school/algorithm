#include "lab.h"

class Point {
public:
    int x;
    int y;

    Point(int x, int y) : x(x), y(y) {};

    // ������ x ��������
    static bool compareX(Point& a, Point& b) {
        return a.x < b.x;
    }

    // ������ y ��������
    static bool compareY(Point& a, Point& b) {
        return a.y < b.y;
    }
};

class Pair {
public:
    Point a;
    Point b;

    Pair(Point& a, Point& b) : a(a), b(b) {};

    double get_distance() {
        return calc_distance(a, b);
    }

    // ��������֮�����
    static double calc_distance(Point& a, Point& b) {
        return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
    }
};

// ��������֮����̾���
Pair min_distance_3points(Point& a, Point& b, Point& c) {
    double d1 = Pair::calc_distance(a, b);
    double d2 = Pair::calc_distance(a, c);
    double d3 = Pair::calc_distance(b, c);

    if (d1 > d2) {
        if (d2 > d3) {
            return Pair(b, c);
        }
        else {
            return Pair(a, c);
        }
    }
    else {
        if (d1 > d3) {
            return Pair(b, c);
        }
        else {
            return Pair(a, b);
        }
    }
}

// ��ӽ����
Pair closet_pair(std::vector<Point>& p) {
    // ��������
    if (p.size() == 2) {
        return Pair(p[0], p[1]);
    }
    
    // ��������
    if (p.size() == 3) {
        return min_distance_3points(p[0], p[1], p[2]);
    }

    // �Դ�ֱ�� l Ϊ�罫�㼯�ֳ���������(���ݵ㼯ˮƽ�е�������)
    std::vector<Point> pls, prs;

    int mid = p.size() / 2;

    for (int i = 0; i < mid; i++) {
        pls.push_back(p[i]);
    }

    for (int i = mid; i < p.size(); i++) {
        prs.push_back(p[i]);
    }

    Pair pl = closet_pair(pls);
    Pair pr = closet_pair(prs);

    // �����������ڽ������
    double dl = pl.get_distance();
    double dr = pr.get_distance();

    double best = dl < dr ? dl : dr;
    Pair res = dl < dr ? pl : pr; // ��ǰ���������������ĵ�

    // �ռ����봹ֱ�� l ˮƽ����С�� best �ĵ�
    std::vector<Point> left, right;

    for (int i = 0; i < pls.size(); i++) {
        if (pls[i].x > p[mid].x - best) {
            left.push_back(pls[i]);
        }
    }

    for (int i = 0; i < prs.size(); i++) {
        if (prs[i].x < p[mid].x + best) {
            right.push_back(prs[i]);
        }
    }

    // �Ҳ�㼯���� y ��������
    std::sort(right.begin(), right.end(), Point::compareY);

    // ������ߵĵ�, �鿴��û�о����ұ� best �ڵĵ�
    for (int i = 0; i < left.size(); i++) {
        for (int j = 0; j < right.size(); j++) {
            if (right[j].y < left[i].y + best && right[j].y > left[i].y - best) {
                // �������Ҳ���� [y - d, y + d] ��Χ�ڵ�
                if (Pair::calc_distance(left[i], right[j]) < best) {
                    res = Pair(left[i], right[j]);
                }
            }
        }
    }

    return res;
}

Pair pair(std::vector<Point>& p) {
    // �� x ��������
    std::sort(p.begin(), p.end(), Point::compareX);

    return closet_pair(p);
}

void lab04() {
    int num = 0, x, y;

    std::cin >> num;

    std::vector<Point> p;

    for (int i = 0; i < num; i++) {
        std::cin >> x >> y;

        p.push_back(Point(x, y));
    }

    output(pair(p).get_distance(), 4, "");
}