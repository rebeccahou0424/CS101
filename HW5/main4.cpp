#include <stdio.h>

int swapThousandsAndOnes(int num) {
    // 狦计单0钡
    if (num <= 0) {
        return num;
    }

    // 矗窾计
    int tenThousands = num / 10000;

    // 矗计
    int thousands = (num / 1000) % 10;

    // 矗计
    int ones = num % 10;

    // 矗κ㎝计
    int hundreds = (num / 100) % 10;
    int tens = (num / 10) % 10;

    // 穝舱计
    int result = tenThousands * 10000 + ones * 1000 + tens * 100 + hundreds * 10 + thousands;

    return result;
}

int main() {
    int testCases[] = {12345, 123, 12, 1};
    int numCases = sizeof(testCases) / sizeof(testCases[0]);

    for (int j = 0; j < numCases; j++) {
        int originalNum = testCases[j];
        int swappedNum = swapThousandsAndOnes(originalNum);
        
        printf("﹍计: %d\n", originalNum);
        printf("秸传计: %d\n\n", swappedNum);
    }

    return 0;
}
