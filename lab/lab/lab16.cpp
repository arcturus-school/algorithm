#include "lab.h"

void composition(std::vector<int>& in, std::vector<char>& str, std::vector<std::string>& res) {
    int n = str.size();
    
    if (in.size() == n) {
        res.push_back(std::string(str.data(), n));
        return;
    }

    static const std::vector<std::vector<char>>map = {
        {},                     // 0
        {},                     // 1
        { 'a', 'b', 'c' },      // 2
        { 'd', 'e', 'f' },      // 3
        { 'g', 'h', 'i' },      // 4
        { 'j', 'k', 'l' },      // 5
        { 'm', 'n', 'o' },      // 6
        { 'p', 'q', 'r', 's' }, // 7
        { 't', 'u', 'v' },      // 8
        { 'w', 'x', 'y', 'z' }, // 9
    };

    for (int i = 0; i < map[in[n]].size(); i++) {
        str.push_back(map[in[n]][i]);
        composition(in, str, res);
        str.pop_back();
    }
}

void output_comp(std::vector<std::string>& res) {
    std::sort(res.begin(), res.end());

    for (auto it = res.begin(); it != res.end(); it++) {
        std::cout << *it << " ";
    }
}

void lab16() {
    std::string in;

    std::cin >> in;

    std::vector<int> digits;

    for (int i = 0; i < in.length(); i++) {
        digits.push_back(in[i] - '0');
    }

    std::vector<std::string> res;
    std::vector<char> str;

    composition(digits, str, res);

    output_comp(res);
}