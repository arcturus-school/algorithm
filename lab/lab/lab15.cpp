#include "lab.h"

// 按字典顺序排序
bool cmp(std::vector<int>& a, std::vector<int>& b) {
    for (int i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] < b[i]) {
            return true;
        }
        else if (a[i] > b[i]) {
            return false;
        }
    }

    return a.size() < b.size();
}

/*
*  @param graph 图
*  @param path  路径
*  @param res   结果
*  @param p     当前节点
*/
void dfs(std::vector<std::vector<int>>& graph, std::vector<int>& path, std::vector<std::vector<int>>& res, int p) {
    int n = graph.size() - 1;

    if (p == n) {
        res.push_back(path);
        return;
    }

    std::vector<int>& node = graph[p];

    for (auto i = node.begin(); i != node.end(); i++) {
        path.push_back(*i);
        dfs(graph, path, res, *i);
        path.pop_back();
    }
}

// 输出路径
void output_paths(std::vector<std::vector<int>> res) {
    std::sort(res.begin(), res.end(), cmp);
    
    int i = 0;
    for (; i < res.size() - 1; i++) {
        for (int j = 0; j < res[i].size(); j++) {
            std::cout << res[i][j] << " ";
        }

        std::cout << std::endl;
    }

    for (int j = 0; j < res[i].size(); j++) {
        std::cout << res[i][j] << " ";
    }
}

void lab15() {
    std::vector<std::vector<int>> graph;

    int n, temp;

    std::cin >> n;
    std::cin.ignore(); // 忽略第一行末尾的换行符

    char c;
    for (int i = 0; i < n; i++) {
        std::vector<int> node;

        while (true) {
            if ((c = std::cin.get()) == '\n') {
                graph.push_back(node);
                break;
            }

            std::cin.putback(c); // 将字符 c 返回输入流
            std::cin >> temp;
            node.push_back(temp);
        }
    }

    std::vector<std::vector<int>> res;
    std::vector<int> path;

    path.push_back(0); // 路径从节点 0 开始 
    dfs(graph, path, res, 0);

    output_paths(res);
}