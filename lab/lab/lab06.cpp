#include "lab.h"

int min_matrix_multiple_num(int n, std::vector<int>& a) {
    // ����������˴���
    std::vector<std::vector<int>> m(n, std::vector<int>(n, 0));

    for (int l = 2; l < n + 1; l++) { // ��ǰ�������
        for (int i = 0; i < n - l + 1; i++) {
            // ������ʼ i, ���� j
            int j = i + l - 1;

            m[i][j] = std::numeric_limits<int>::max();

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + a[i] * a[k + 1] * a[j + 1];

                if (q < m[i][j]) {
                    // ���ڸ�С�ĳ˻�����, (Ai, ..., Ak) * (A_{k+1}, ..., Aj)
                    m[i][j] = q;
                }
            }
        }
    }

    // ���� A0 ~ A_{n-1} ֮�����ٳ˻�����
    return m[0][n - 1];
}

void lab06() {
    int n, temp;

    std::cin >> n;

    std::vector<int> array;
    for (int i = 0; i < n + 1; i++) {
        std::cin >> temp;
        array.push_back(temp);
    }

    std::cout << min_matrix_multiple_num(n, array);
}