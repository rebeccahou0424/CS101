#include <stdio.h>
#include <math.h> // 使用 fabs() 計算絕對值

int main() {
    double pi = 0.0;      // 初始化 PI 值
    int x = 1;            // 項數計數器
    int sign = 1;         // 符號變化 (-1, 1)
    double target = 3.14159; // 精準目標值
    double precision = 0.000005; // 精準度範圍（小於 0.000005）

    for (x = 0; ; x++) { // 無限循環，直到達到精準度
        double term = 4.0 / (2 * x + 1); // 計算當前項
        pi += sign * term;               // 根據符號累加項值
        sign = -sign;                    // 符號切換

        // 判斷計算出的 PI 是否精準到目標值
        if (fabs(pi - target) < precision) {
            break; // 如果達到精準度，跳出迴圈
        }
    }

    printf("計算出的 PI 值為：%.5f\n", pi);
    printf("所需的最小項數 x 為：%d\n", x + 1);

    return 0;
}

