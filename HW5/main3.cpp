#include <stdio.h>

int main() {
    int i = 1; 
    while (i <= 81) { 
        int row = (i - 1) / 9 + 1; // 計算行數（第幾列）
        int col = (i - 1) % 9 + 1; // 計算列數（第幾行）

        printf("%d*%d=%2d ", row, col, row * col); // 印出乘法結果
        if (col == 9) { // 到達每行的最後一列時換行
            printf("\n");
        }

        i++; // 前進到下一個位置
    }
    return 0;
}

