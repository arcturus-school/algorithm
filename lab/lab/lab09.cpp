#include "lab.h"

// c 语言版
//#include <stdio.h>
//#include <stdlib.h>
//
//int max(int a, int b) {
//    return a > b ? a : b;
//}
//
//int min(int a, int b) {
//    return a < b ? a : b;
//}
//
//int calc_max_capacity(int h[], int len) {
//    if (len <= 1) return 0;
//
//    int l = 0, r = len - 1, c = 0;
//
//    while (l < r) {
//        c = max(c, (r - l) * min(h[l], h[r]));
//
//        if (h[l] < h[r]) l++;
//        else r--;
//    }
//
//    return c;
//}
//
//void lab09() {
//    int  temp, len = 0, cap, c = 100;
//    int* heights = (int*)malloc(sizeof(int) * 100);
//
//    while (scanf("%d", &temp) == 1) {
//        heights[len++] = temp;
//
//        if (len >= c) {
//            heights = (int*)realloc(heights, sizeof(int) * (c *= 2));
//        }
//
//        if (getchar() == '\n') {
//            break;
//        }
//    }
//
//    cap = calc_max_capacity(heights, len);
//
//    printf("%d", cap);
//
//    free(heights);
//}

int calc_max_capacity(std::vector<int>& h) {
    int len = h.size();

    if (len <= 1) return 0;

    int l = 0, r = len - 1, c = 0;

    while (l < r) {
        c = std::max(c, (r - l) * std::min(h[l], h[r]));

        if (h[l] < h[r]) l++;
        else r--;
    }

    return c;
}

void lab09() {
    std::vector<int> heights;

    int temp;

    // oj 不能这样写, 不知为何...
    //while (true) {
    //    std::cin >> temp;
    //    heights.push_back(temp);

    //    if (getchar() == '\n') {
    //        break;
    //    }
    //}

    while (scanf_s("%d", &temp) == 1) {
        heights.push_back(temp);

        if (getchar() == '\n') {
            break;
        }
    }

    std::cout << calc_max_capacity(heights);
}