#include "stdc++.h"
#include "output.h"
#include "lab.h"

class Test {
    std::map<std::string, void(*)()> map;
    void(*cur)()  = nullptr;
public:
    void add(const std::string& key, void (*func)()) {
        map[key] = func;
    }

    void set(const std::string& key) {
        if (map.find(key) != map.end()) {
            cur = map[key];
        }
        else {
            cur = nullptr;
        }
    }

    void operation() {
        if (cur != nullptr) {
            cur();
        }
    }
};

int main() {

    Test test;

    test.add("lab01", lab01);
    test.add("lab02", lab02);
    test.add("lab03", lab03);
    test.add("lab04", lab04);
    test.add("lab05", lab05);
    test.add("lab06", lab06);
    test.add("lab07", lab07);
    test.add("lab08", lab08);
    test.add("lab09", lab09);
    test.add("lab10", lab10);

    // 设置当前需要执行的方法
    test.set("lab10");
    
    test.operation();

    return 0;
}

